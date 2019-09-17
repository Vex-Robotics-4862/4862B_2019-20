#ifndef _CONTROLS_HPP_
#define _CONTROLS_HPP_

#include "main.h"

class Joystick{
  int deadband;
  std::function<int(int)> curve;
  public:
    Joystick(pros::controller_analog_e_t channel, int deadband, std::function<int(int)> curve);

    int get();
};

int noCurve(int x);

class Button{
  public:
    Button(pros::controller_digital_e_t channel);

    int get();
};

class Input{
  std::function<int()> calculateInput;
  public:
    Input(std::function<int()> calculateInput);

    int get();
};

#endif //_CONTROLS_HPP_
