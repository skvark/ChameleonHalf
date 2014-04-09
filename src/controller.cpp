#include "controller.h"
#include <QThread>

Controller::Controller(QObject *parent) :
    QObject(parent)
{
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
}

Controller::~Controller()
{
    setVDD();
}

QColor Controller::getColor()
{
    return TCS34725Driver_->getCurrentColor();
}

void Controller::setColor(QColor color)
{
    BlinkMDriver_->fadeToRGBColor(color);
}

void Controller::setChameleonMode(bool onOff)
{
    return;
}

void Controller::getID()
{
    TCS34725Driver_->getID();
}

void Controller::changeColor()
{
    return;
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
