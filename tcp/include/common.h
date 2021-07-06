#include<sys/socket.h>
#include<arpa/inet.h>


#define SERVER_ADDRESS "127.0.0.1"
#define SERVER_PORT 9000
#define CLIENT_PORT 9000
#define ERROR -1
#define TIMEOUT 10 // 10 secs timeout
#define DEFAULT_MESSAGE_LENGTH 250

/**
 * @brief closes Socket
 * 
 * Further read write/communcation is disabled.
 * 
 * @param nSocket 
 */
void closeSocket(int nSocket);

/**
 * @brief create Socket for communication
 * calls socket function from sys/socket.h
 * 
 * @return 0 in case of success, -ive in case of an error
 */
int socketCreate(void);
