#include "session.h"

void session::print(){
    qInfo("session type is %s\n",type);
    qInfo("duration is%d\n",duration);
    qInfo("intensity is%d\n",intensity);
}

void session::setIntensity(int newIntensity){
    intensity = newIntensity;
}

void session::setDuration(int newDuration){
    duration = newDuration;
}

const QString session::getType(){
    return type;
}

int session::getIntensity(){
    return intensity;
}

int session::getDuration(){
    return duration;
}
