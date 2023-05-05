#include "fishttp.h"
#include <stddef.h>
#include <stdio.h>


char* fishttp_buildRequest(char* url, fishttp_options opt) {
    char* req = calloc(2000, sizeof(char));
    size_t headers_len = 3;
// GET /[endpoint] HTTP/1.1
// \r\n
// Host: [Host]
// \r\n
// Headers: [headers]\n[final_header]
// \r\n
// \r\n
    strcat(req, opt.method);
    strcat(req, " /");
    strcat(req, url);
    strcat(req, " HTTP/1.1");
    strcat(req, "\r\n");
    for (size_t i = 0; i < headers_len; i++) {
        strcat(req, opt.headers[i]);
        if (i != headers_len - 1) strcat(req, "\n");
    }
    strcat(req, "\r\n\r\n");
    return req;
    return "\0";
}

int sendData(const char* addr, char* msg) {
    // struct sockaddr_in server_addr;
    char request_buff[2000], response_buff[4000];

    // Clean buffers:
    memset(request_buff, '\0', sizeof(request_buff));
    memset(response_buff, '\0', sizeof(response_buff));    

    struct addrinfo *info = NULL;

    int errcode = getaddrinfo(addr, "80", NULL, &info);
    if (errcode != 0) {
        fprintf(stderr, "06\n");
        exit(1);
    }

    // Create socket:
    int socket_fd = socket(info->ai_family, SOCK_STREAM, 0);

    if (socket_fd < 0){
        printf("Unable to create socket\n");
        return -1;
    }
    
    printf("Socket created successfully\n");

    // Send connection request to server:
    if (connect(socket_fd, info->ai_addr, info->ai_addrlen)) {
        printf("Unable to connect\n");
        return -2;
    }
    printf("Connected with server successfully\n");

    // Get input from the user:
    // printf("Enter message: ");

    // Send the message to server:
    if (send(socket_fd, msg, strlen(msg), 0) < 0) {
        printf("Unable to send message\n");
        return -1;
    }

    if (read(socket_fd, response_buff, sizeof(response_buff)) < 0) {
        printf("No response at all\n");
        return -1;
    }
    printf("response: %s\n", response_buff);

    // // Receive the server's response:
    // if(recv(socket_desc, response_buff, sizeof(response_buff), 0) < 0){
    //     printf("Error while receiving server's msg\n");
    //     return -1;
    // }

    // printf("Server's response: %s\n", response_buff);

    // // Close the socket:
    // close(socket_desc);

    freeaddrinfo(info);
    close(socket_fd);
    return socket_fd;
}
