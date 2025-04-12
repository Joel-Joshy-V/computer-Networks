// tcp_factorial_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};
    char response[1024];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server is running and listening on port %d...\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

    read(new_socket, buffer, sizeof(buffer));
    int num = atoi(buffer);
    printf("Received number: %d\n", num);

    unsigned long long result = factorial(num);
    sprintf(response, "Factorial of %d is %llu", num, result);
    send(new_socket, response, strlen(response), 0);
    printf("Sent result: %s\n", response);

    close(new_socket);
    close(server_fd);
    return 0;
}
