#include "controller.h"

Controller::Controller(QObject *parent) :
    QObject(parent)
{
    ChameleonMode_ = false;
    VDDstate_ = false;
    // Set 3,3 V on
    setVDD();
    // Wait for stabile power - this is hacky and makes app to start delayed.
    // QTimer in a separete thread has to be implemented.
    QThread::msleep(500);
    // Disable any preprogrammed scripts from blinkm,
    // other commands won't go trough otherwise.
    disableScript();
    BlinkMDriver_ = new BlinkMDriver(blinkm);
    TCS34725Driver_ = new TCS34725Driver(tcs);
    connect(this, SIGNAL(colorChanged(QColor)), BlinkMDriver_, SLOT(fadeToRGBColor(QColor)));
}

Controller::~Controller()
{
    setVDD();
}

QColor Controller::getColor()
{
    return TCS34725Driver_->getLastColor();
}

void Controller::setColor(QColor color)
{
    BlinkMDriver_->fadeToRGBColor(color);
}

void Controller::setChameleonMode(bool onOff)
{
    if (onOff && !ChameleonMode_) {
        qDebug() << "start";

        ChameleonMode_ = true;
        thread_ = new QThread;
        poller_ = new ColorPoller(TCS34725Driver_);
        poller_->moveToThread(thread_);
        connect(poller_, SIGNAL(newColor(QColor)), this, SLOT(changeColor(QColor)), Qt::DirectConnection);
        connect(thread_, SIGNAL(finished()), thread_, SLOT(deleteLater()));
        thread_->start();

    } else if (!onOff && ChameleonMode_) {
        qDebug() << "stop";

        delete poller_;
        thread_->quit();
        ChameleonMode_ = false;
    }
}

void Controller::getID()
{
    TCS34725Driver_->getID();
}

void Controller::changeColor(QColor color)
{
    qDebug() << "color changed";
    emit colorChanged(color);
    emit colorDetected(color);
}

void Controller::disableScript()
{
    BlinkMDriver_->stopScript();
}

void Controller::setVDD()
{
    int fd;
    fd = open("/sys/devices/platform/reg-userspace-consumer.0/state", O_WRONLY);

    if (!(fd < 0))
    {
        if (VDDstate_ == false) {
            if(write(fd, "1" ,1)) {
                VDDstate_ = true;
                qDebug() << "VDD on.";
            }
        } else {
            if(write(fd, "0" ,1)) {
                VDDstate_ = false;
                qDebug() << "VDD off.";
            }
        }
    } else {
        qDebug() << "Error.";
    }
    close(fd);
}
