#ifndef _SUBSYSTEM_HPP_
#define _SUBSYSTEM_HPP_

#include "main.h"

class Subsystem {
  pros::Motor motors[];
  public:
    Subsystem(pros::Motor motors[]);

};

#endif //_SUBSYSTEM_HPP_
