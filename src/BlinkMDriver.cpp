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
    char bytes[1];
    bytes[0] = stopscript;
    writeBytes(blinkmAddress_, bytes, 1);
}

// Fade to RGB Color: {‘c’, R, G, B}
void BlinkMDriver::fadeToRGBColor(QColor color)
{
    char bytes[4];
    bytes[0] = fadetorgb;
    convertQColorComponentsToCharArray(color, bytes);
    writeBytes(blinkmAddress_, bytes, 4);
}

void BlinkMDriver::convertQColorComponentsToCharArray(QColor color, char bytes[]) {

    QColor RGB = color.toRgb();
    bool ok;
    bytes[1] = QString::number(RGB.red(), 16).toInt(&ok, 16);
    bytes[2] = QString::number(RGB.green(), 16).toInt(&ok, 16);
    bytes[3] = QString::number(RGB.blue(), 16).toInt(&ok, 16);
}

