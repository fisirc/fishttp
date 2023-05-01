#include "fishttp.h"

int main() {
    sendData("www.google.com", "GET / HTTP/1.1\nHost: www.google.com\nUser-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36\nAccept-Language: en-US,en;q=0.5\nConnection: close\r");

    return 0;
}

/*
Request URL: https://google.com/
Request Method: GET
Status Code: 301  (from disk cache)
Remote Address: [2800:3f0:4003:c08::64]:443
Referrer Policy: strict-origin-when-cross-origin
*/
