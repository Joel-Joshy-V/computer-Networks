// tcp_prime_server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int isPrime(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return 0;
    return 1;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024] = {0};
    char response[50];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr*)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server is listening on port %d...\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen);

    read(new_socket, buffer, sizeof(buffer));
    int number = atoi(buffer);
    printf("Received number: %d\n", number);

    if (isPrime(number)) {
        strcpy(response, "Prime");
    } else {
        strcpy(response, "Not Prime");
    }

    send(new_socket, response, strlen(response), 0);
    printf("Sent to client: %s\n", response);

    close(new_socket);
    close(server_fd);
    return 0;
}
