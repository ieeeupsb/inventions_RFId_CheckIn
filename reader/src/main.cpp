#include <Arduino.h>
#include "rfid.h"

void setup(){
    initRFId();
    WiFiConnect();
    connectToDB();
}

void loop(){
    handleRFId();
}
