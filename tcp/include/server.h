#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include "common.h"

#define BACKLOG 3


/**
 * @brief Binds the created socket to any ip address available
 * 
 * @param nSocket       Socket
 * @param nClientPort   Client Port 
 * @return -ive in case of an error 
 */
int bindCreatedSocket(int nSocket,int nClientPort);
