#include "security.h"
#include "configs/secrets.h"

char* generateHash(String data){
    Sha256.initHmac(hmacKey, HMAC_KEY_LENGTH); // key, and length of key in bytes
    Sha256.print(data);
    return (char*)Sha256.resultHmac();
}