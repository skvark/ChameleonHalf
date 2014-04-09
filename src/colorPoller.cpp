#include "colorPoller.h"

ColorPoller::ColorPoller(TCS34725Driver *sensor, QObject *parent) :
    QObject(parent)
{
    sensor_ = sensor;
    timer_ = new QTimer(0);
    timer_->setInterval(710);
    connect(timer_, SIGNAL(timeout()), this, SLOT(poll()));
    timer_->start();
}

ColorPoller::~ColorPoller()
{
    timer_->stop();
}

void ColorPoller::poll()
{
    qDebug() << "poll";
    QColor color = sensor_->getCurrentColor();
    emit newColor(color);
}
