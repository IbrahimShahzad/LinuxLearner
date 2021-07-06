# POSIX Messaging Queue

A queue that is marked for deletion is removed only after it is closed by all processes that are currently using it.

The main functions:
-   `mq_open()` 
    -   creates new **OR** opens existing
    -   get/sets attributes
        -   `mq_getattr()` get queue attributes
        -   `mq_setattr()` set queue attributes
-   `mq_send()` 
    -   writes a message to the queue
-   `mq_receive()` 
    -   reads a message from a queue
-   `mq_close()` 
    -   closes a message queue 
-   `mq_unlink()` 
    -   marks the queue for deletion

-   `mq_notify()` 
    -   allows a process to register for message notification
    -   the process is notified by signal or by the invocation of a function in a separate thread

## Creation

`mq_open() oflag` values are as follows

| Flag | Description |
| --- | --- |
| `O_CREAT` | Create queue if it doesn’t already exist |
| `O_EXCL` | With `O_CREAT`, create queue exclusively |
| `O_RDONLY` | Read-only Access |
| `O_WRONLY` | Write-only Access |
| `O_RDWR` | Read/Write Access |
| `O_NONBLOCK` | Open in non-blocking mode |

If `O_CREAT` is specified in flags, two further arguments are required: 
1.  `mode` and 
    -   bit mask specifying queue permissions (same as those of files)
2.  `attr`
    -   `mq_attr` struct
        -   if `NULL`, queue created with default attributes  

>   On success, `mq_open()` returns a **message queue descriptor**

### Message Queue Attributes

The attributes structure is defined in `mqueue.h` as follows:
```c
struct mq_attr {
    long mq_flags; /* Message queue description flags: 0 or O_NONBLOCK[mq_getattr(), mq_setattr()] */
    long mq_maxmsg; /* Maximum number of messages on queue [mq_open(), mq_getattr()] */
    long mq_msgsize; /* Maximum message size (in bytes) [mq_open(), mq_getattr()] */
    long mq_curmsgs; /* Number of messages currently in queue [mq_getattr()] */
};
```