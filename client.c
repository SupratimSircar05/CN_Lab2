// UDP socket for client
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    printf("\nClient Socket");
    int fd, res;
    fd = socket(AF_INET, SOCK_DGRAM, 0);
    printf("\nReturn value : %d", fd);
    if (fd == -1)
        printf("\nSocket not created");
    else
        printf("\nSocket created");


    struct sockaddr_in x;
    x.sin_family = AF_INET; //ipv4 env.
    x.sin_port = ntohs(6000); //port - network to host short (long to short)
    x.sin_addr.s_addr = inet_addr("127.0.0.1"); //invoke ip address to socket

    res = bind(fd, (struct sockaddr *) &x, sizeof(x));

    if (res == -1)
        printf("\nBind error\n");
    else
        printf("\nBind successfully\n");
}