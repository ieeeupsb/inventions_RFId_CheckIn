#include "networkUtils.h"

String URLEncode(const char* msg){
    const char *hex = "0123456789abcdef";
    String encodedMsg = "";

    while (*msg!='\0'){
        if( ('a' <= *msg && *msg <= 'z')
            || ('A' <= *msg && *msg <= 'Z')
            || ('0' <= *msg && *msg <= '9') ) {
            encodedMsg += *msg;
        } else {
            encodedMsg += '%';
            encodedMsg += hex[*msg >> 4];
            encodedMsg += hex[*msg & 15];
        }
        msg++;
    }
    return encodedMsg;
}

void WiFiConnect(){
    while (WiFi.status() != WL_CONNECTED);
}

bool connect(){
    if(client.connect(host, port)){
        con = true;
        return true;
    }
    else
        return false;
}

void connectToDB(){
    while(!connect()){};
}

void sendResponse(String message){
    client.println("POST /checkin HTTP/1.1");
    client.println("Host: " + String(host) + ":" + port);
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Cache-Control: no-cache");
    client.print("Content-Length: ");
    client.println(message.length());
    client.println();
    client.println(message);
}