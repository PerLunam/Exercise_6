#pragma once

#include "exception.h"

class Sensor
{
public:
    //Kein Konstruktor notwendig, das Programm verwendet deshalb den Default-Konstruktor

    //Destruktor
    virtual ~Sensor(){};

    virtual int checkSensor() = 0;
};

class CameraSensor : public Sensor
{
public:
    virtual int checkSensor() override;
};

class DistanceSensor : public Sensor
{
public:
    virtual int checkSensor() override;
};

class CliffSensor : public Sensor
{
public:
    virtual int checkSensor() override;
};