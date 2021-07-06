#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "client.h"

int socketConnect(int nSocket,char *pServerAddress, int nServerPort)
{
    int nRet=ERROR;
    struct sockaddr_in remote= {0};
    remote.sin_addr.s_addr = inet_addr(pServerAddress);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(nServerPort);
    nRet = connect(nSocket,(struct sockaddr *)&remote,sizeof(struct sockaddr_in));
    return nRet;
}

int socketSend(int nSocket,char* pcMessage,int nMessageLength)
{
    int nRet = ERROR;
    struct timeval sTv;
    sTv.tv_sec = TIMEOUT;
    sTv.tv_usec = 0;
    if(setsockopt(nSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&sTv,sizeof(sTv)) < 0)
    {
        perror("TimeOut reached %ds\n",TIMEOUT);
        return ERROR;
    }
    nRet = send(nSocket, pcMessage, nMessageLength, 0);
    return nRet;
}

int socketReceive(int nSocket,char* pcMessage,int nMessageLength)
{
    int nRet = ERROR;
    struct timeval sTv;
    sTv.tv_sec = TIMEOUT;
    sTv.tv_usec = 0;
    if(setsockopt(nSocket, SOL_SOCKET, SO_RCVTIMEO,(char *)&sTv,sizeof(sTv)) < 0)
    {
        perror("TimeOut reached %ds\n",TIMEOUT);
        return ERROR;
    }
    nRet = recv(nSocket, pcMessage, nMessageLength, 0);
    printf("Response %s\n",pcMessage);
    return nRet;
}

int main(int argc, char *argv[])
{
    int nSocket=0;
    int nReadSize=0;
    struct sockaddr_in sServer;
    char pcMessage[DEFAULT_MESSAGE_LENGTH] = {0};
    char pcResponse[DEFAULT_MESSAGE_LENGTH] = {0};
    //Create socket
    nSocket = socketCreate();
    if(nSocket == ERROR)
    {
        perror("Could not create socket\n");
        return 1;
    }
    if (socketConnect(nSocket,SERVER_ADDRESS,SERVER_PORT) < 0)
    {
        perror("Connection Failed!\n");
        return 1;
    }
    printf("Connection Established with %s:%d!\n",SERVER_ADDRESS, SERVER_PORT);
    printf("Enter Message: ");
    gets(pcMessage);
    
    //Send data to the server
    socketSend(nSocket, pcMessage, strlen(pcMessage));
    
    //Received the data from the server
    nReadSize = SocketReceive(nSocket, pcResponse, DEFAULT_MESSAGE_LENGTH);
    printf("Server Response : %s\n",pcResponse);
    closeSocket(nSocket);
    return 0;
}