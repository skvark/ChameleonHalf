#ifndef COLORPOLLER_H
#define COLORPOLLER_H

#include <QObject>
#include <QTimer>
#include <TCS34725Driver.h>

class ColorPoller : public QObject
{
    Q_OBJECT
public:
    ColorPoller(TCS34725Driver* sensor, QObject *parent=0);
    ~ColorPoller();
public slots:
    void poll();
signals:
    void newColor(QColor color);
private:
    TCS34725Driver* sensor_;
    QTimer* timer_;
};

#endif // COLORPOLLER_H
