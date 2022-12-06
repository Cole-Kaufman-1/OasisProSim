#ifndef SESSION_H
#define SESSION_H

#include <QString>

class session
{
public:
    session(const QString &typeTreatment, int d, int i)
    {
        type = typeTreatment;
        duration = d;
        intensity = i;

    };
    void print();

private:
    QString type;
    int duration;
    int intensity;
};

#endif // SESSION_H
