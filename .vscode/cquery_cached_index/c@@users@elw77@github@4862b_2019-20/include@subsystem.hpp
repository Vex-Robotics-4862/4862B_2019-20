#ifndef _SUBSYSTEM_HPP_
#define _SUBSYSTEM_HPP_

#include "main.h"

class Subsystem {
  pros::Motor motors[8];
  public:
    Subsystem(pros::Motor motors[], int slew);

    Poller moveVoltage(int power);

    Poller moveVelocity(int velocity, int custom1 = INT32_MAX, int custom2 = INT32_MAX, int custom3 = INT32_MAX);

    Poller movePosition(int position, int maxVelocity, int custom1 = INT32_MAX, int custom2 = INT32_MAX, int custom3 = INT32_MAX);
};

#endif //_SUBSYSTEM_HPP_
