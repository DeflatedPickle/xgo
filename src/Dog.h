#ifndef Dog_h
#define Dog_h

#include "Version.h"
#include "Bluetooth.h"
// #include "Steering.h"
#include "Controller.h"

class Dog {
  public:
    Dog();

    // State information
    /*0x00*/ int getMode();
    /*0x01*/ int getBatteryLevel();
    /*0x02*/ Version getVersion();

    // Bluetooth information
    Bluetooth bluetooth = new Bluetooth();

    // Test mode
    // Steering steering = new Steering();

    // Whole unit mode
    Controller controller = new Controller();
}

#endif
