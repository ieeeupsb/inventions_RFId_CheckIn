#include "sha256.h"
#include "configs/secrets.h"

#define HMAC_KEY_LENGTH 20 //This number must reflect the number of bytes in 'hmacKey'.
char* generateHash(String data);