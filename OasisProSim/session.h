#ifndef SESSION_H
#define SESSION_H

#include <QString>

class session
{
public:
    session (const QString &typeTreatment, int duration, int intensity);
    void print();
private:
    QString type;
    int duration;
    int intensity;


};

#endif // SESSION_H
