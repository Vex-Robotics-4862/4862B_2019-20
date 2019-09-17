#ifndef _AUTON_HPP_
#define _AUTON_HPP_

#include "main.h"

class Auton {
  std::string autonName;
  std::function<void(bool)> auton;

  public:
    static int getTime();

    Auton(std::string autonName, std::function<void(bool)> auton);

    void run(bool side);
};

#endif //_AUTON_HPP_
