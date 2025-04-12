
//SERVER
#include<stdio.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#define TCP_PORT 5035
#define MAX 60
int i, j, tem;
char buff[4096], t;
FILE *f1;
int main()
{
int serversocket, clientsocket, clength;
struct sockaddr_in serveraddr,clientaddr;
char t[MAX], str[MAX];
strcpy(t,"exit");
serversocket=socket(AF_INET, SOCK_STREAM,0);
serveraddr.sin_family=AF_INET;
serveraddr.sin_addr.s_addr=INADDR_ANY;
serveraddr.sin_port=htons(TCP_PORT);
printf("Binded");
bind(serversocket,(struct sockaddr*)&serveraddr, sizeof(serveraddr));
printf("\nListening...");
listen(serversocket, 5);
clength=sizeof(clientaddr);
clientsocket=accept(serversocket,(struct sockaddr*) &clientaddr,&clength);
close(serversocket);
read(clientsocket, &str, MAX);
printf("\nClient message\nFile Name: %s\n", str);
f1=fopen(str, "r");
while(fgets(buff, 4096, f1)!=NULL)
{
write(clientsocket, buff,MAX);
printf("\n");
}
fclose(f1);
printf("File Transferred\n");
return 0;
}
