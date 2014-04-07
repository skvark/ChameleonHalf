#include "driverBase.h"

int DriverBase::openDeviceFile(const char* name)
{
    int file = open(name, O_RDWR);
    if (file < 0) {
        qDebug() << "Device file open failed.";
        return -1;
    }
    return file;
}

bool DriverBase::setSlaveAddress(int file, unsigned char address)
{
    if (ioctl(file, I2C_SLAVE, address) < 0) {
        qDebug() << "ioctl failed.";
        return false;
    }
    return true;
}

bool DriverBase::i2cWrite(int file, char buffer[], int buffer_length)
{
    if (write(file, buffer, buffer_length) != buffer_length) {
        close(file);
        qDebug() << "Write failed.";
        return false;
    }
    qDebug() << "Write successful.";
    return true;
}

// address: slave device adress in hex
// bytes: QList of hex formatted QStrings ("bytes"), each value must be one byte
bool DriverBase::writeBytes(unsigned char address, QList<QString> bytes)
{
    char buffer[20];
    bool ok;

    // convert QStrings to hex
    for (int i = 0; i < bytes.length(); ++i) {
        QString temp = bytes[i];
        buffer[i] = temp.toInt(&ok, 16);
        if (!ok) {
            return false;
        }
    }

    // try to open the device
    int file = openDeviceFile("/dev/i2c-1");

    if (file != -1) {
        // set slave address
        if (setSlaveAddress(file, address)) {
            // try to perform the actual write
            if (i2cWrite(file, buffer, bytes.length())) {
                close(file);
                return true;
            }
        }
    }
    close(file);
    return false;
}

// To be implemented
bool DriverBase::readBytes(unsigned char address,
                           QString registerToRead,
                           int howManyBytesToRead)
{
    qDebug() << "This method is not yet implemeted.";
    return false;
}

bool DriverBase::writeThenRead(unsigned char address,
                               QList<QString> bytes,
                               int howManyBytesToRead)
{
    qDebug() << "This method is not yet implemeted.";
    return false;
}


