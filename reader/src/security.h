#ifndef _SECURITY_H_
#define _SECURITY_H_

#include "sha256.h"

#define HMAC_KEY_LENGTH 20 //This number must reflect the number of bytes in 'hmacKey'.
char* generateHash(String data);

#endif