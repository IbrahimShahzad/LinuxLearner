#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "common.h"

void closeSocket(int nSocket)
{
    close(nSocket);
    (shutdown(nSocket,SHUT_RD)) : printf("socket receive operations disabled\n") , perror("cannot disable socket receiver operations!\n");
    (shutdown(nSocket,SHUT_WR)) : printf("socket send operations disabled\n") , perror("cannot disable socket send operations!\n");
    (shutdown(nSocket,SHUT_RDWR)) : printf("socket send/receive operations disabled\n") , perror("cannot disable socket send/receiver operations!\n");
}

int socketCreate(void)
{
    int nResult;
    nResult = socket(AF_INET, SOCK_STREAM, 0);
    return nSocket;
}