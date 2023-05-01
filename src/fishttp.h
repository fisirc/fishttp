#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

typedef struct _fishttp_options {
    int port; // 443 or 80
    char* method; // GET
} options;

int sendData(const char* addr, const char* msg);
