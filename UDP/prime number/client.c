#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[1024];
    socklen_t len;
    
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;
    
    int number;
    printf("Enter a number to check prime: ");
    scanf("%d", &number);
    
    sendto(sockfd, &number, sizeof(number), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    
    int result;
    len = sizeof(servaddr);
    recvfrom(sockfd, &result, sizeof(result), 0, (struct sockaddr *)&servaddr, &len);
    
    printf("Server Response: %s\n", result ? "Prime Number" : "Not a Prime Number");
    
    close(sockfd);
    return 0;
}
