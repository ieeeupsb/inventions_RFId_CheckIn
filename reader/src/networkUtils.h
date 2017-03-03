#ifndef _NETWORKUTILS_H_
#define _NETWORKUTILS_H_

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

String URLEncode(const char *msg);

void WiFiConnect();

void connectToDB();

int sendUid(String message);

#endif