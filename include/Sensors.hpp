#ifndef _SENSORS_HPP_
#define _SENSORS_HPP_

#include "main.h"

class PosTracker{
  double frontWheelOffset, backWheelOffset, middleWheelOffset;
  double x, y, theta;

  public:
    PosTracker(double frontWheelOffset, doucle backWheelOffset, double middleWheelOffset);

    void updatePosition();

    double getX();

    double getY();

    double getTheta();
};

double degreesToRad(double degrees);

double radToDegrees(double rad);

#endif //_SENSORS_HPP_
