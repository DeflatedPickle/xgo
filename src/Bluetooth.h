#ifndef Bluetooth_h
#define Bluetooth_h

#include "BluetoothStatus.h"

class Bluetooth {
  public:
    Bluetooth();
    
    /*0x10*/ BluetoothStatus getStatus();
    /*0x11*/ int getBaudRate();
    
    /*0x12*/ int getPassword();
    /*0x12*/ void setPassword(int password);
    
    /*0x13*/ String getName();
    /*0x13*/ void setName(String name);
}

#endif
