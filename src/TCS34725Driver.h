#ifndef TCS34725DRIVER_H
#define TCS34725DRIVER_H
#include <QObject>
#include <QString>
#include <driverBase.h>

namespace {
    const char command_byte = 0x80;
    const char ID = command_byte | 0x12;
}

class TCS34725Driver: public DriverBase
{
    Q_OBJECT
public:
    explicit TCS34725Driver(unsigned char TCS34725Address);
    ~TCS34725Driver();

    // gets current color from the sensor
    QColor getColor();
    // this enables or disables the onboard led
    void setInterrupt(bool state);
    void getID();

signals:

private:
    unsigned char TCS34725Address_;

};

#endif // TCS34725DRIVER_H
