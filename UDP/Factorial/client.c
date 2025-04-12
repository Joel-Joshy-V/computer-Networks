#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    socklen_t len;
    int number, result;

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    printf("Enter a number to find factorial: ");
    scanf("%d", &number);
    number = htonl(number);  // Convert to network byte order

    sendto(sockfd, &number, sizeof(number), 0, (const struct sockaddr *)&servaddr, sizeof(servaddr));

    recvfrom(sockfd, &result, sizeof(result), 0, NULL, NULL);
    result = ntohl(result);  // Convert to host byte order
    printf("Factorial received from server: %d\n", result);

    close(sockfd);
    return 0;
}
