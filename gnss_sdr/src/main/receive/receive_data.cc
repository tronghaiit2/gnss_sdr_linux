#include "receive_data.h"

ReceiveData::ReceiveData(){
    
}

int ReceiveData::init(char* file)
{
    this->file = file;
    char* cmd = (char*) malloc(sizeof(char) * BUFSIZE);
    snprintf(cmd, BUFSIZE, "touch %s", file);
    int result = system(cmd);
    free(cmd);

    if ((key = ftok(file, 'B')) == -1) {
        perror("ftok");
    }
    
    if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
        perror("msgget");
    }

    return result;
}

int ReceiveData::dispose()
{
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
    }

    char* cmd = (char*) malloc(sizeof(char) * BUFSIZE);
    snprintf(cmd, BUFSIZE, "rm %s", this->file);
    int result = system(cmd);
    free(cmd);
    return result;
}

char* ReceiveData::receiveData()
{
    ssize_t siz = msgrcv(msqid, &buf, sizeof(buf.mtext), 0, IPC_NOWAIT);
    if(siz>0) return buf.mtext;
    if (siz<0) {
      if (errno == ENOMSG) 
        {
          // usleep(100);
          // std::this_thread::sleep_for(std::chrono::milliseconds(100));
          return "";
        }
      else {
        perror("msgrcv");
        return "";
      }
    } 
    else {
        return buf.mtext;
    }
}