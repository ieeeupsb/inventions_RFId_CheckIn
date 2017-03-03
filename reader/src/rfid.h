#include <SPI.h>
#include "MFRC522.h"
#include "encriptation.h"
#include "networkUtils.h"
#include "configs/pins.h"

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

void handleRFId();

void initRFId();