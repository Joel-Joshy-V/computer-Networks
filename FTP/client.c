//CLIENT
#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#define TCP_PORT 5035
#define MAX 60
int main()
{
int clientsocket,n;
struct sockaddr_in serveraddr;
char send[MAX],recvline[MAX],s[MAX],name[MAX];
clientsocket=socket(AF_INET,SOCK_STREAM,0);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=inet_addr("127.0.0.1");
serveraddr.sin_port=htons(TCP_PORT);
connect(clientsocket,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("Enter the source file name: ");
scanf("%s",send);
write(clientsocket,send,MAX);
while((n=read(clientsocket,recvline,MAX))!=0){
printf("%s",recvline);}
close(clientsocket);
return 0;}