#include <stdio.h>

struct fishttp_options {
    int port; // 443 or 80
    char* method; // GET
};

void fishttp(const char* url, struct fishttp_options options) {
    printf("url: %s\n", url);
    printf("method: %s\n", options.method);
    if (options.port == 0) {
        options.port = 80;
    }
    printf("port: %d\n", options.port);
}

int main() {
    fishttp("https://2800:200:e800:3509:dc68:b04e:c130:b63a", (struct fishttp_options) {
        .method = "GET"
    });
}
