#pragma once

#include <iostream>
#include "exception.h"

class Motor
{
private:
    int speed = 0;

public:
    //Objektfunktionen
    void emergencyBreak();

    //Getter und Setter
    int getSpeed() const;
    void setSpeed(int speed);
};