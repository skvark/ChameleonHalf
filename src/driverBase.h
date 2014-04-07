#ifndef DRIVERBASE_H
#define DRIVERBASE_H
#include <QString>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <QDebug>
#include <QObject>

class DriverBase : public QObject {

public:

    // write given bytes to specified address
    bool writeBytes(unsigned char address,
                    QList<QString> bytes);

    // read specified amount of bytes from a register
    bool readBytes(unsigned char address,
                   QString registerToRead,
                   int howManyBytesToRead);

    // first write bytelist and then read
    bool writeThenRead(unsigned char address,
                       QList<QString> bytes,
                       int howManyBytesToRead);

private:
    int openDeviceFile(const char *name);
    bool setSlaveAddress(int file, unsigned char address);
    bool i2cWrite(int file, char buffer[], int buffer_length);
};

#endif // DRIVERBASE_H
