#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main() {
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);
    
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }
    
    printf("UDP Server listening on port %d...\n", PORT);
    
    while (1) {
        len = sizeof(cliaddr);
        int number;
        recvfrom(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&cliaddr, &len);
        printf("Received number: %d\n", number);
        
        int result = isPrime(number);
        sendto(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&cliaddr, len);
        printf("Sent response: %s\n", result ? "Prime" : "Not Prime");
    }
    
    close(sockfd);
    return 0;
}
