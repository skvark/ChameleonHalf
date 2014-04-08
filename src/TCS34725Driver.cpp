#include <TCS34725Driver.h>

TCS34725Driver::TCS34725Driver(unsigned char TCS34725Address)
{
    TCS34725Address_ = TCS34725Address;
}

TCS34725Driver::~TCS34725Driver()
{

}

void TCS34725Driver::getID()
{
    QByteArray result = writeThenRead(TCS34725Address_, ID, 1);
    qDebug() << QString(result.toHex());
}

