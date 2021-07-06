#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "server.h"


int bindCreatedSocket(int nSocket,int nClientPort)
{
    int nRet=ERROR;
    struct sockaddr_in  remote= {0};

    /* Internet address family */
    remote.sin_family = AF_INET;

    /* Any incoming interface */
    remote.sin_addr.s_addr = htonl(INADDR_ANY); 
    remote.sin_port = htons(nClientPort); 
    nRet = bind(nSocket,(struct sockaddr *)&remote,sizeof(remote));
    return nRet;
}


int main(int argc, char *argv[])
{
    int nSocket; 
    int nSock;
    int nClientLen;
    struct sockaddr_in server, client;
    char pcClientMessage[DEFAULT_MESSAGE_LENGTH]= {0};
    char message[DEFAULT_MESSAGE_LENGTH] = {0};
    const char *pMessage = "hello";
    //Create socket
    nSocket = socketCreate();
    if (nSocket)
    {
        perror("Could not create socket!\n");
        return 1;
    }
    if( bindCreatedSocket(nSocket) < 0)
    {
        perror("Socket Bind Failed!\n");
        return 1;
    }
    //Listen
    listen(nSocket, BACKLOG);
    
    //Accept and incoming connection
    while(1)
    {
        printf("Waiting for incoming connections...\n");
        nClientLen = sizeof(struct sockaddr_in);

        //accept connection from an incoming client
        nSock = accept(nSocket,(struct sockaddr *)&client,(socklen_t*)&nClientLen);
        if (nSock)
        {
            perror("accept failed");
            return 1;
        }
        printf("Connection accepted\n");
        memset(pcClientMessage, '\0', sizeof(pcClientMessage));
        memset(message, '\0', sizeof(message));

        //Receive a reply from the client
        if(recv(nSock, pcClientMessage, DEFAULT_MESSAGE_LENGTH, 0))
        {
            perror("message receive from client failed\n");
            break;
        }
        printf("Client reply : %s\n",pcClientMessage);
        
        // Send some data
        if(send(nSock, message, strlen(message), 0))
        {
            perror("Send failed\n");
            return 1;
        }

        close(nSock);
        sleep(1);
    }
    return 0;
}