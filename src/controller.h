#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <BlinkMDriver.h>
#include <TCS34725Driver.h>
#include <QColor>
#include <QDebug>


namespace {
    // blinkm address
    const unsigned char blinkm = 0x09;
    // flora color sensor address
    const unsigned char tcs = 0x29;
}

// Controller class for UI <-> driver interaction.
class Controller : public QObject
{
    Q_OBJECT
public:
    Controller(QObject *parent = 0);
    ~Controller();

    Q_INVOKABLE QColor getColor();
    Q_INVOKABLE void setColor(QColor color);
    Q_INVOKABLE void setChameleonMode(bool onOff);
    Q_INVOKABLE void getID();

    void disableScript();

signals:
    // this emits color changes to UI - not implemented
    void colorChanged();

public slots:
    // receives signals from QThread which polls the color sensor - not implemented
    void changeColor();

private:
    // Mode
    bool ChameleonMode_;

    // Drivers
    BlinkMDriver* BlinkMDriver_;
    TCS34725Driver* TCS34725Driver_;

    // VDD control
    bool VDDstate_;
    void setVDD();
};

#endif // CONTROLLER_H
