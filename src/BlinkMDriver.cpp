#include <BlinkMDriver.h>
#include <QCoreApplication>


BlinkMDriver::BlinkMDriver(unsigned char blinkmAddress)
{
    blinkmAddress_ = blinkmAddress;
}

BlinkMDriver::~BlinkMDriver()
{

}

// stops running script if any
void BlinkMDriver::stopScript()
{
    QList<QString> bytes;
    bytes.append(stopscript);
    writeBytes(blinkmAddress_, bytes);
}

// Fade to RGB Color: {‘c’, R, G, B}
void BlinkMDriver::fadeToRGBColor(QColor color)
{
    QColor RGB = color.toRgb();
    QList<QString> bytes;

    bytes.append(fadetorgb);
    bytes.append(QString::number(RGB.red(), 16));
    bytes.append(QString::number(RGB.green(), 16));
    bytes.append(QString::number(RGB.blue(), 16));

    qDebug() << "Command byte: " << bytes[0];
    qDebug() << "Color: " << bytes[1] << bytes[2] << bytes[3];

    writeBytes(blinkmAddress_, bytes);
}

