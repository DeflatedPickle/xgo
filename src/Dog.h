#pragma once

#include <Serial.h>

#include "Version.h"
#include "Bluetooth.h"
// #include "Steering.h"
#include "Controller.h"
#include "Leg.h"
#include "Util.h"

class Dog {
  public:
    Dog();
    
    void setup() {
    	Serial.begin(baud_rate);
    	while(!Serial) {
    		;
    	}
    }

    // State information
    /*0x00*/ int getMode() {
      send(0x00);
      return Serial.read();
    }
    /*0x01*/ int getBatteryLevel() {
      send(0x01);
      return Serial.read();
    }
    /*0x02*/ Version getVersion() {
      send(0x02);
      int value = Serial.read();

      switch (value) {
        case 0x00:
          return Version.MINI;
        case 0x01:
          return Version.LITE;
        case 0x02:
          return Version.PRO;
        default:
          break;
      }
    }

    // Bluetooth information
    Bluetooth bluetooth = new Bluetooth();

    // Test mode
    // Steering steering = new Steering();

    // Whole unit mode
    Controller controller = new Controller();
    
    // Single leg mode
    Leg left_fore_leg = new Leg(0x40, 0x41, 0x42);
    Leg right_fore_leg = new Leg(0x43, 0x44, 0x45);
    Leg right_rear_leg = new Leg(0x46, 0x47, 0x48);
    Leg left_rear_leg = new Leg(0x49, 0x4A, 0x4B);

  private:
    int baud_rate = 115200;
    int data_bit = 8;
    int stop_bit = 1;
}
