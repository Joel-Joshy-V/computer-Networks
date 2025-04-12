#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int factorial(int n) {
    if (n < 0) return -1; // error case
    int result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    int number, result;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("UDP Factorial Server running on port %d...\n", PORT);

    while (1) {
        len = sizeof(cliaddr);
        recvfrom(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&cliaddr, &len);
        number = ntohl(number);  // Convert to host byte order
        printf("Received number: %d\n", number);

        result = factorial(number);
        result = htonl(result);  // Convert to network byte order
        sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&cliaddr, len);
        printf("Sent factorial result.\n");
    }

    close(sockfd);
    return 0;
}
