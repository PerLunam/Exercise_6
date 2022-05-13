#include <iostream>
#include "robot.h"

int main()
{
    Robot robot;
    robot.addSensor(new CameraSensor());
    robot.addSensor(new DistanceSensor());
    robot.addSensor(new CliffSensor());

    robot.eventLoop(10);

    return 0;
}
