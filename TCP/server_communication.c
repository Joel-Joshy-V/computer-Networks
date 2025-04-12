#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define PORT 8080

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    socklen_t addrlen = sizeof(address);
    char buffer[1024], message[1024];

    // Create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Reuse the address
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt));

    // Bind and listen
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    printf("Server listening on port %d...\n", PORT);
    new_socket = accept(server_fd, (struct sockaddr *)&address, &addrlen);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        read(new_socket, buffer, sizeof(buffer));
        printf("Client: %s\n", buffer);
        if (strcmp(buffer, "exit") == 0) break;

        printf("Enter message for client: ");
        fgets(message, sizeof(message), stdin);
        message[strcspn(message, "\n")] = '\0';
        send(new_socket, message, strlen(message), 0);

        if (strcmp(message, "exit") == 0) break;
    }

    close(new_socket);
    close(server_fd);
    return 0;
}
