# Unix Domain Sockets

IPC is a data communications endpoint for exchanging data between processes executing on the **same** host operating system.

### Socket Types:

-   `SOCK_STREAM` (compare to TCP) 
    - for a **stream-oriented** socket
-   `SOCK_DGRAM` (compare to UDP) 
    - for a **datagram-oriented** socket that preserves message boundaries (as on most UNIX implementations, UNIX domain datagram sockets are always reliable and don't reorder datagrams)
-   `SOCK_SEQPACKET` (compare to SCTP) 
    - for a **sequenced-packet** socket that is connection-oriented, preserves message boundaries, and delivers messages in the order that they were sent

## Server

1.  open new `socket()`
2.  `bind()` it
3.  `listen()` on it
4.  `accept()` incoming connections
5.  `read()` data incoming data
6.  `write()` response
7.  `close()` the socket

## Client

1.  open new `socket()`
2.  `connect()` to server
3.  `write()` message
4.  `read()` reply
5.  `close()` the socket


## Sources:

-   [Getting Started With Unix Domain Sockets by Matt Lim](https://medium.com/swlh/getting-started-with-unix-domain-sockets-4472c0db4eb1)
-   [The Linux Programming Interface by Michael Kerrisk](https://www.man7.org/tlpi/)



---

