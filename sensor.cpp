#include "sensor.h"

#include <stdlib.h>

int CameraSensor::checkSensor()
{
    //Zufallszahl zwischen 0 und 100
    int randValue = rand() % 101;

    if(randValue <= 15)
    {
        throw InternalErrorException("CameraSensor::checkSensor(): Achtung. Interne Fehlfunktion.");
    } else if(randValue > 15 && randValue <= 35)
    {
        throw CriticalDangerException("CameraSensor::checkSensor(): Achtung. Es wurde eine kritische Situation erkannt.");
    } else
    {
        //Zufallszahl zwischen 0 und 9
        return rand() % 10;
    }
}

int DistanceSensor::checkSensor()
{
    //Zufallszahl zwischen 0 und 100
    int randValue = rand() % 101;

    if(randValue <= 5)
    {
        throw InternalErrorException("DistanceSensor::checkSensor(): Achtung. Interne Fehlfunktion.");
    } else if(randValue > 5 && randValue <= 20)
    {
        throw CriticalDangerException("DistanceSensor::checkSensor(): Achtung. Es wurde eine kritische Situation erkannt.");
    } else
    {
        //Zufallszahl zwischen 0 und 6
        return rand() % 7;
    }
}

int CliffSensor::checkSensor()
{
    //Zufallszahl zwischen 0 und 100
    int randValue = rand() % 101;

    if(randValue <= 5)
    {
        throw InternalErrorException("CliffSensor::checkSensor(): Achtung. Interne Fehlfunktion.");
    } else if(randValue > 5 && randValue <= 15)
    {
        throw CriticalDangerException("CliffSensor::checkSensor(): Achtung. Es wurde eine kritische Situation erkannt.");
    } else
    {
        //Zufallszahl zwischen 0 und 4
        return rand() % 5;
    }
}