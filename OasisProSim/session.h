#ifndef SESSION_H
#define SESSION_H

#include <QString>

class session
{
public:
    session(int type, int duration, int intensity);

private:
    int type;
    int duration;
    int intensity;


};

#endif // SESSION_H
