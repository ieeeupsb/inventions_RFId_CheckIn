#include "networkUtils.h"
#include "configs/networks.h"

WiFiClient client;

String URLEncode(const char *msg) {
    const char *hex = "0123456789abcdef";
    String encodedMsg = "";

    while (*msg != '\0') {
        if (('a' <= *msg && *msg <= 'z')
            || ('A' <= *msg && *msg <= 'Z')
            || ('0' <= *msg && *msg <= '9')) {
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

void WiFiConnect() {
    while (WiFi.status() != WL_CONNECTED);
}

void connectToDB() {
    if (!client.connected()) {
        client.connect(host, port);
    }
}

int sendUid(String message) {
    client.println("POST /checkin HTTP/1.1");
    client.println("Host: " + String(host) + ":" + port);
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Cache-Control: no-cache");
    client.print("Content-Length: ");
    client.println(message.length());
    client.println();
    client.println(message);
    return client.read();
}