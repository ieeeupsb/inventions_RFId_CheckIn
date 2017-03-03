#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "configs/networks.h"

bool con = false;
WiFiClient client;

String URLEncode(const char *msg);

void WiFiConnect();

bool connect();

void connectToDB();

void sendResponse(String message);