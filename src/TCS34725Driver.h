#ifndef TCS34725DRIVER_H
#define TCS34725DRIVER_H
#include <QObject>
#include <QString>
#include <driverBase.h>
#include <QColor>

// TCS34725 Driver
// Please see the datasheet for further info:
// http://www.adafruit.com/datasheets/TCS34725.pdf

namespace {

    // registers are OR'ed with this to address the command register correctly
    // (to set MSB 1)
    const char command_byte = 0x80;

    // enable bits
    const char enable_pon = 0x01;
    const char enable_aen = 0x02 | enable_pon;
    const char disable_all = 0x00;
    const char enable_aien = 0x10;

    // registers
    const char enable = command_byte | 0x00;
    const char integration_time = command_byte | 0x01;
    const char gain_control = command_byte | 0x0F;
    const char ID = command_byte | 0x12;
    const char clear_low = command_byte | 0x14;
    const char clear_high = command_byte | 0x15;
    const char red_low = command_byte | 0x16;
    const char red_high = command_byte | 0x17;
    const char green_low = command_byte | 0x18;
    const char green_high = command_byte | 0x19;
    const char blue_low = command_byte | 0x1A;
    const char blue_high = command_byte | 0x1B;

    // timing register possible values
    enum IntegrationTimes
    {
      time_2_4ms = 0xFF,
      time_24ms = 0xF6,
      time_50ms = 0xEB,
      time_101ms = 0xD5,
      time_154ms = 0xC0,
      time_700ms = 0x00
    };

    // Control register (gain) possible values
    enum Gains
    {
      gain_1 = 0x00, // no gain
      gain_4 = 0x01,
      gain_16 = 0x02,
      gain_60 = 0x03
    };
}

class TCS34725Driver: public DriverBase
{
    Q_OBJECT
public:
    explicit TCS34725Driver(unsigned char TCS34725Address);
    ~TCS34725Driver();

    void initialize();
    void setIntegrationTime(IntegrationTimes time);
    void setGain(Gains gain);
    void setPower(bool state);
    void setAENbit(bool state);
    void setInterrupt(bool state);
    void getID();
    QColor getCurrentColor();
    void clearInterrupt();
    QColor getLastColor();

signals:

private:
    unsigned char TCS34725Address_;
    quint16 clearvalue_;
    quint16 redvalue_;
    quint16 greenvalue_;
    quint16 bluevalue_;
    QColor lastColor_;

};

#endif // TCS34725DRIVER_H
