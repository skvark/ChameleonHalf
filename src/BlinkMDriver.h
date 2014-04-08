#ifndef BLINKMDRIVER_H
#define BLINKMDRIVER_H
#include <QObject>
#include <QColor>
#include <driverBase.h>

namespace {
    const unsigned char fadetorgb = 0x63;
    unsigned char stopscript = 0x6f;
}

class BlinkMDriver: public DriverBase
{
    Q_OBJECT
public:
    explicit BlinkMDriver(unsigned char blinkmAddress);
    ~BlinkMDriver();

    void stopScript();
    void fadeToRGBColor(QColor color);

public slots:

signals:

private:
    unsigned char blinkmAddress_;
    void convertQColorComponentsToCharArray(QColor color, char bytes[]);
};


#endif // BLINKMDRIVER_H

