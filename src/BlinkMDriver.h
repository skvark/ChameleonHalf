#ifndef BLINKMDRIVER_H
#define BLINKMDRIVER_H
#include <QObject>
#include <QColor>
#include <driverBase.h>

// commands
const QString fadetorgb = "63";
const QString stopscript = "6f";

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
};


#endif // BLINKMDRIVER_H

