#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

int main(void) {
    // struct sockaddr_in server_addr;
    char request_buff[2000], response_buff[2000];

    // Clean buffers:
    memset(request_buff, 'a', sizeof(request_buff));
    memset(response_buff, '\0', sizeof(response_buff));


    printf("Socket created successfully\n");
    struct addrinfo *info = NULL;

    int errcode = getaddrinfo("2800:200:e800:3509:dc68:b04e:c130:b63a", "8080", NULL, &info);
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

    // Send connection request to server:
    if (connect(socket_fd, info->ai_addr, info->ai_addrlen)) {
        printf("Unable to connect\n");
        return -1;
    }
    printf("Connected with server successfully\n");

    // // Get input from the user:
    // printf("Enter message: ");

    // Send the message to server:
    if (send(socket_fd, request_buff, strlen(request_buff), 0) < 0){
        printf("Unable to send message\n");
        return -1;
    }

    // // Receive the server's response:
    // if(recv(socket_desc, response_buff, sizeof(response_buff), 0) < 0){
    //     printf("Error while receiving server's msg\n");
    //     return -1;
    // }

    // printf("Server's response: %s\n", response_buff);

    // // Close the socket:
    // close(socket_desc);

    freeaddrinfo(info);
    return 0;
}
