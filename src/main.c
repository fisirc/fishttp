#include "fishttp.h"
#include <stdio.h>



int main() {

    char* headers[] = {
        "User-agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/90.0.4430.93 Safari/537.36",
        "Accept-Language: en-US,en;q=0.5",
        "Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8"
    };

    fishttp_options opt = {
        .method = "GET",
        .headers = headers
    };

    char* req = fishttp_buildRequest("www.google.com", opt);

    printf("data to send: %s\n", req);
    
    printf("\n---\n");

    sendData("www.google.com", req);

    return 0;
}

