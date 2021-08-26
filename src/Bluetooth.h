#pragma once

#include "util/func/BluetoothStatus.h"
#include "util/enum/send.h"

class Bluetooth {
  public:
    Bluetooth();
    
    /*0x10*/ BluetoothStatus getStatus();
    /*0x11*/ int getBaudRate();
    
    /*0x12*/ int getPassword();
    /*0x12*/ void setPassword(int password) {
      send(0x12, password);
    }
    
    /*0x13*/ String getName();
    /*0x13*/ void setName(String name) {
      send(0x13, name);
    }
}
