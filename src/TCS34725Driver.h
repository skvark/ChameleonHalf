#ifndef TCS34725DRIVER_H
#define TCS34725DRIVER_H
#include <QObject>
#include <QString>
#include <driverBase.h>

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

signals:

private:
    void write(unsigned char TCS34725_register, QString data);
    void read(unsigned char TCS34725_register, unsigned int howManyBytesToRead);
    unsigned char TCS34725Address_;

};

#endif // TCS34725DRIVER_H
