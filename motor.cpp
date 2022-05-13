#include "motor.h"

//Objektfunktionen
void Motor::emergencyBreak()
{
    std::cout << "Achtung. Es wurde eine Notbremsung eingeleitet. Die Geschwindigkeit wird auf 0 gesetzt." << std::endl;
    this->speed = 0;
}

//Getter und Setter
int Motor::getSpeed() const
{
    return this->speed;
}
void Motor::setSpeed(int speed)
{
    if(speed >= 0)
    {
        std::cout << "Die Geschwindigkeit wurde auf " << speed << " gesetzt." << std::endl;
        this->speed = speed;
    } else
    {
        throw InvalidValueException("Motor::setSpeed(int speed): Bitte gib einen gültigen Wert ein.");
    }
}