#pragma once

#include <map>

#include "sensor.h"
#include "motor.h"

class Robot
{
private:
    std::map<int, Sensor*> sensors;
    int nextID = 0;
    Motor motor;
    int status = 0; // 0 = Normalbetrieb; 1 = Internal Error; 2 = Notstopp

public:
    //Destruktor
    virtual ~Robot()
    {
        //Freigabe des Speichers am Heap, sobald die Class "Robot" zerstört wird
        /*for(int i = 0; i < sensors.size(); ++i)
        {
            std::cout << "Der Sensor " << sensors[i] << " wurde entfernt." << std::endl;
            this->deleteSensor(i);
            //delete sensors[i];
        }
        */

        sensors.clear();
    }

    //Objektfunktionen
    void deleteSensor(int id);
    void eventLoop(int iterations);

    //Getter und Setter
    int addSensor(Sensor* sensor);
    Sensor* getSensor(int id);
};
