#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

typedef struct {
    char* method; // GET on default
    char** headers;
    char* body;
} fishttp_options;

int sendData(const char* addr, char* msg);

char* fishttp_buildRequest(char* url, fishttp_options opt);
