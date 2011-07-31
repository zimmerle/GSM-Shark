#ifndef RADIO_H
#define RADIO_H

#include <QObject>

class Radio : public QObject
{
    Q_OBJECT
    Q_ENUMS(status)

public:
    explicit Radio(QObject *parent = 0);

signals:

public slots:

};

#endif // RADIO_H
