/**
 * @file posix_msgq.c
 * @brief creates a queue
 */
#include <mqueue.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#define MAX_MESSAGE 50
#define MESSAGE_SIZE 2048

/**
 * @brief prints usage error. 
 * 
 * Displays help
 * 
 * @param progName 
 */
static void usageError(const char *progName)
{
    fprintf(stderr, "Usage: %s [-cx] [-m maxmsg] [-s msgsize] mq-name "
                    "[octal-sPermissions]\n",
                    progName);
    fprintf(stderr, " -c Create queue (O_CREAT)\n");
    fprintf(stderr, " -m maxmsg Set maximum # of messages\n");
    fprintf(stderr, " -s msgsize Set maximum message size\n");
    fprintf(stderr, " -x Create exclusively (O_EXCL)\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
    int nFlags, nOption;
    mode_t sPermissions;
    mqd_t sMQD;
    struct mq_attr sAttr, *pAttr;
    pAttr = NULL;
    sAttr.mq_maxmsg = MAX_MESSAGE;
    sAttr.mq_msgsize = MESSAGE_SIZE;
    nFlags = O_RDWR;                    /* Read write Flag */
        /* Parse command-line options */
        while ((nOption = getopt(argc, argv, "cm:s:x")) != -1)
    {
        switch (nOption)
        {
        case 'c':
            nFlags |= O_CREAT;          /* Create New */
            break;
        case 'm':
            sAttr.mq_maxmsg = atoi(optarg); /* Change Max Message Length */
            pAttr = &sAttr;
            break;
        case 's':
            sAttr.mq_msgsize = atoi(optarg); /* Change Message Size */
            pAttr = &sAttr;
            break;
        case 'x':
            nFlags |= O_EXCL;           /* Create Exclusive */
            break;
        default:
            usageError(argv[0]);
        }
    }
    if (optind >= argc)
        usageError(argv[0]);
    sPermissions = (argc <= optind + 1) ? (S_IRUSR | S_IWUSR) : getInt(argv[optind + 1], GN_BASE_8, "octal-sPermissions");
    sMQD = mq_open(argv[optind], nFlags, sPermissions, pAttr);
    if (sMQD == (mqd_t)-1)
        errExit("mq_open");
    exit(EXIT_SUCCESS);
}