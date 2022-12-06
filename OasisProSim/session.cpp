#include "session.h"

session::session(const QString &typeTreatment, int duration, int intensity)
{
    type = typeTreatment;
    duration = duration;
    intensity = intensity;

}

void session::print(){

    qInfo("session type is %s\n",type);
    qInfo("duration is%d\n",duration);
    qInfo("duration is%d\n",intensity);
}
