#ifndef GNSS_SDR_RECEIVE_DATA_H
#define GNSS_SDR_RECEIVE_DATA_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <thread>


#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[128];
};

/** \addtogroup Send_data
 * \{ */
/** \addtogroup Send_data_libs
 * \{ */

class ReceiveData
{
public:
    ReceiveData();
    int init(char* file);
    char* receiveData();
    int dispose();
    const int BUFSIZE = 32;
    const int MSIZE = 128;

private:
    struct my_msgbuf buf;
    char* file;
    int msqid;
    // int len;
    key_t key;
};


/** \} */
/** \} */
#endif  // GNSS_SDR_RECEIVE_DATA_H
