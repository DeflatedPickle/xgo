#ifndef Controller_h
#define Controller_h

#include "Axis.h"

class Controller {
  public:
    Controller();

    /*0x30,0x31*/ int getMovementSpeed(Axis axis);
    
    /*0x30*/ void walkForward(int speed);
    /*0x30*/ void walkBackward(int speed);
    
    /*0x31*/ void walkLeft(int speed);
    /*0x31*/ void walkRight(int speed);
    
    /*0x32*/ int getRotationSpeed();
    /*0x32*/ void rotateClockwise(int speed);
    /*0x32*/ void rotateCounterClockwise(int speed);

    /*0x33,0x34*/ int getTwist(Axis axis);
    /*0x33,0x34*/ void setTwist(Axis axis, int speed);

    /*0x35*/ int getBodyHeight();
    /*0x35*/ void setBodyHeight(int height);

    /*0x36,0x37,0x38*/ int getRotationAngle(Axis axis);
    /*0x36,0x37,0x38*/ void setRotationAngle(Axis axis, int angle);

    /*0x39,0x3A,0x3B*/ int getMinRotationSpeed(Axis axis);
    /*0x39,0x3A,0x3B*/ void setMinRotationSpeed(Axis axis);
    /*0x39,0x3A,0x3B*/ int getMaxRotationSpeed(Axis axis);
    /*0x39,0x3A,0x3B*/ void setMaxRotationSpeed(Axis axis);

    /*0x3C*/ int getSteppingHeight();
    /*0x3C*/ void setSteppingHeight(int height);

    /*0x3D*/ Speed getMovingMode();
    /*0x3D*/ void setMovingMode(Speed speed);

    /*0x3E*/ Action setAction(Action action);
    
    /*0x80,0x81,0x82*/ int getMinSteppingSpeed(Axis axis);
    /*0x80,0x81,0x82*/ void setMinSteppingSpeed(Axis axis);
    /*0x80,0x81,0x82*/ int getMaxSteppingSpeed(Axis axis);
    /*0x80,0x81,0x82*/ void setMaxSteppingSpeed(Axis axis);
}

#endif
