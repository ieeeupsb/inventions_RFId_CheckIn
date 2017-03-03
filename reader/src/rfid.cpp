#include "rfid.h"

void red(bool state, int pin = RED_LED_PIN){
    digitalWrite(pin, state);
}
void yellow(bool state, int pin = YELLOW_LED_PIN){
    digitalWrite(pin, state);
}
void green(bool state, int pin = GREEN_LED_PIN){
    digitalWrite(pin, state);
}

void initRFId(){
    pinMode(RED_LED_PIN, OUTPUT);     //
    pinMode(YELLOW_LED_PIN, OUTPUT);  //Set up LED pins
    pinMode(GREEN_LED_PIN, OUTPUT);   //

    SPI.begin(); //Init SPI bus

    mfrc522.PCD_Init(); //Init each MFRC522 card
    mfrc522.PCD_DumpVersionToSerial();
}

void handleRFId(){
    char payload_c = '1';
    int payload_i = 1;

    // Look for new cards
    if(!mfrc522.PICC_IsNewCardPresent() || !mfrc522.PICC_ReadCardSerial())
        return;

    yellow(true); //Indicate that the reading has started.

    String uid = "";
    byte *buffer = mfrc522.uid.uidByte;
    byte bufferSize = mfrc522.uid.size;
    for (byte i = 0; i < bufferSize; i++){ //Populate the 'uid' string
        uid += buffer[i] < 0x10 ? " 0" : " ";
        uid += buffer[i], HEX;
    }

    String PostData = "uid=" + URLEncode(generateHash(uid));

    if(con){
        sendResponse(PostData);

        long interval = 2000;
        unsigned long currentMillis = millis(), previousMillis = millis();

        while(!client.available()){

            if( (currentMillis - previousMillis) > interval ){
                Serial.println("Timeout");
                client.stop();
                con = false;
                return;
            }
            currentMillis = millis();
        }

        while (client.connected()) {
            if ( client.available() ) {
                payload_c = client.read();
            }
            else
                break;
        }
    }
    else
        while(!connect()){}

    payload_i = payload_c - '0'; //Converts the receieved char to an integer.

    if(!payload_i){
        yellow(false); //Turn off the yellow LED, because we are about to show a response
        green(true); //Turn on the green LED to show that the uid has accepted by the server.
        delay(500); //Wait two seconds to give time for the user to see the response.
        green(false); //Turn off the green LED
    }
    else{
        yellow(false); //Turn off the yellow LED, because we are about to show a response
        red(true); //Turn on the red LED to show that the uid has rejected by the server. The user is either not registered, or the uid has not read correctly.
        delay(500); //Wait two seconds to give time for the user to see the response.
        red(false); //Turn off the red LED
    }
    mfrc522.PICC_HaltA(); //Halt PICC
    mfrc522.PCD_StopCrypto1(); //Stop encryption on PCD
}