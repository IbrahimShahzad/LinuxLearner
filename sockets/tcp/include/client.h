#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "common.h"


/**
 * @brief Connect with server
 * 
 * @param nSocket           socjet to connect to
 * @param pServerAddress    The IP Address of the Server
 * @param nServerPort       The port to connect to
 * @return -ive in case of error 
 */
int socketConnect(int nSocket,char *pServerAddress, int nServerPort);

/**
 * @brief Send message
 * 
 * @param nSocket           Socket To send the message on
 * @param pcMessage         Message 
 * @param nMessageLength    Message Length
 * @return int 
 */
int socketSend(int nSocket,char* pcMessage,int nMessageLength);


/**
 * @brief receive from the socket
 * 
 * @param nSocket           socket
 * @param pcMessage         Message
 * @param nMessageLength    Message Length
 * @return -ive in case of an error
 */
int socketReceive(int nSocket,char* pcMessage,int nMessageLength);
