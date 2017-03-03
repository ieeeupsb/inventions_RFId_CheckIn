#ifndef _RFID_H_
#define _RFID_H_

#include <SPI.h>
#include "MFRC522.h"
#include "security.h"
#include "networkUtils.h"

void handleRFId();

void initRFId();

#endif