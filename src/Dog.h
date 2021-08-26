#pragma once

#include <Serial.h>

#include "Bluetooth.h"
#include "Steering.h"
#include "Controller.h"
#include "Leg.h"
#include "util/enum/Version.h"
#include "util/enum/Limb.h"
#include "util/func/send.h"

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
    Steering steering = new Steering();

    // Whole unit mode
    Controller controller = new Controller();
    
    // Single leg mode
    Leg left_fore_leg = new Leg(Limb.LEFT_FORE);
    Leg right_fore_leg = new Leg(Limb.RIGHT_FORE);
    Leg right_rear_leg = new Leg(Limb.RIGHT_REAR);
    Leg left_rear_leg = new Leg(Limb.LEFT_REAR);

  private:
    int baud_rate = 115200;
    int data_bit = 8;
    int stop_bit = 1;
}
