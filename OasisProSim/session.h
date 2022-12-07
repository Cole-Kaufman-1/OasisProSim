#ifndef SESSION_H
#define SESSION_H

#include <QString>

class session
{
public:
    session(const QString typeTreatment, int d, int i)
    {
        type = "";
        type.append(typeTreatment);
       // type = typeTreatment;
        duration = d;
        intensity = i;

    }
    void print();
    QString type;
    int duration;
    int intensity;

    void setIntensity(int newIntensity);
    void setDuration(int newDuration);

    const QString getType();
    int getIntensity();
    int getDuration();


private:

};

#endif // SESSION_H
