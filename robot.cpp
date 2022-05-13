#include <utility>
#include <unistd.h>

#include "robot.h"

void Robot::deleteSensor(int id)
{
    if(id >= 0)
    {
        sensors.erase(id);
    } else
    {
        throw InvalidValueException("Robot::deleteSensor(): Bitte gib einen gültigen Wert ein.");
    }
}
void Robot::eventLoop(int iterations)
{
    int statusCount = 0;

    while(iterations >= 0)
    {
        std::cout << "Iteration: " << iterations << std::endl;

        int maxStatus = 0;

        if(status != 2)
        {
            for(auto &sensor : sensors)
            {
                try {
                    int currentStatus = sensor.second->checkSensor();

                    if(currentStatus > maxStatus)
                    {
                        maxStatus = currentStatus;
                    }

                    std::cout << "Sensor-Nr.: " << sensor.first << std::endl;
                    std::cout << "Der aktuelle Gefahren-Status beträgt: " << currentStatus << std::endl;
                } catch(CriticalDangerException& e)
                {
                    std::cout << "Sensor-Nr.: " << sensor.first << " // " << e.what() << std::endl;

                    motor.emergencyBreak();
                    status = 2; // 2 = Notstopp
                    statusCount = 5;

                    break;
                } catch(InternalErrorException& e)
                {
                    std::cout << "Sensor-Nr.: " << sensor.first << " // " << e.what() << std::endl;

                    motor.setSpeed(1);
                    status = 1; // 1 = Internal Error
                    statusCount = 5;
                }
            }
        }

        if(status == 0)
        {
            std::cout << "Der höchste gemeldete Gefahrenstatus lautet: " << maxStatus << std::endl;

            motor.setSpeed(10 - maxStatus);
        } else
        {
            std::cout << "Der StatusCounter beträgt: " << statusCount << std::endl;

            statusCount--;
            std::cout << "Der neue StatusCounter beträgt nun: " << statusCount << std::endl;

            if(statusCount <= 0)
            {
                std::cout << "Der Roboter kehrt wieder in den Normalbetrieb zurück." << std::endl;
                status = 0;
            }
        }

        if(iterations > 0)
        {
            iterations--;

            if(iterations <= 0)
            {
                break;
            }
        }

        sleep(2);
    }
}

int Robot::addSensor(Sensor* sensor)
{
    int newID = nextID++;
    sensors.insert(std::pair<int, Sensor*>(newID, sensor));

    //Vorgehensweise bei Smartpointern
    //sensors[newID].reset(sensor);

    return newID;
}
Sensor* Robot::getSensor(int id)
{
    if(sensors.find(id) != sensors.end())
    {
        std::cout << "Die ID des Sensors lautet: " << id << std::endl;
        return sensors[id];

        //Vorgehensweise bei Smartpointern
        //sensors[newID].reset(sensor);

    } else
    {
        return nullptr;
    }
}