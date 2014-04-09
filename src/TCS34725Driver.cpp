#include <TCS34725Driver.h>
#include <QThread>

TCS34725Driver::TCS34725Driver(unsigned char TCS34725Address)
{
    TCS34725Address_ = TCS34725Address;
    // start up the sensor with default values
    initialize();
}

TCS34725Driver::~TCS34725Driver()
{

}

void TCS34725Driver::initialize() {

    setGain(gain_1);
    setIntegrationTime(time_700ms);
    setPower(true);
    // power up cycle with 2,4 ms integration time is 2,4 ms
    QThread::msleep(3);
    setAENbit(true);
}

void TCS34725Driver::setIntegrationTime(IntegrationTimes time) {

    char bytes[2];
    bytes[0] = integration_time;
    bytes[1] = time;
    writeBytes(TCS34725Address_, bytes, 2);
}

void TCS34725Driver::setGain(Gains gain) {

    char bytes[2];
    bytes[0] = gain_control;
    bytes[1] = gain;
    writeBytes(TCS34725Address_, bytes, 2);
}

void TCS34725Driver::setPower(bool state) {

    char bytes[2];
    bytes[0] = enable;

    if (state == true) {
        bytes[1] = enable_pon;
    } else {
        bytes[1] = disable_all;
    }

    writeBytes(TCS34725Address_, bytes, 2);
}

// enables the ADC
void TCS34725Driver::setAENbit(bool state) {

    char bytes[2];
    bytes[0] = enable;

    if (state == true) {
        bytes[1] = enable_aen | enable_pon; // bytes[1] = 00000011 = 0x03
    } else {
        bytes[1] = enable_pon & 0x7D; // 0x7D = 11111101
    }

    writeBytes(TCS34725Address_, bytes, 2);
}

void TCS34725Driver::setInterrupt(bool state) {

    QByteArray enable_state = writeThenRead(TCS34725Address_, enable, 1);
    char bytes[2];
    bytes[0] = enable;

    if (state == true) {
        bytes[1] = enable_state[0] | enable_aien; // enable_aien = 00010000
    } else {
        bytes[1] = enable_state[0] & 0xEF; // 0xEF = 11101111
    }

    writeBytes(TCS34725Address_, bytes, 2);
}

void TCS34725Driver::clearInterrupt() {
    char bytes[1];
    bytes[0] = 0x67; // o.o' ??
    writeBytes(TCS34725Address_, bytes, 1);
}

void TCS34725Driver::getID()
{
    QByteArray result = writeThenRead(TCS34725Address_, ID, 1);
    qDebug() << QString(result.toHex());
}

QColor TCS34725Driver::getCurrentColor() {

    QByteArray clear = writeThenRead(TCS34725Address_, clear_low, 2);
    QByteArray red = writeThenRead(TCS34725Address_, red_low, 2);
    QByteArray green = writeThenRead(TCS34725Address_, green_low, 2);
    QByteArray blue = writeThenRead(TCS34725Address_, blue_low, 2);

    clearvalue_ = clear[1] << 8 | clear[0];
    redvalue_ = red[1] << 8 | red[0];
    greenvalue_ = green[1] << 8 | green[0];
    bluevalue_ = blue[1] << 8 | blue[0];

    QColor color = QColor(static_cast<quint8>(redvalue_),
                         static_cast<quint8>(greenvalue_),
                         static_cast<quint8>(bluevalue_));

    qDebug() << color.toRgb().name();
    return color;
}
