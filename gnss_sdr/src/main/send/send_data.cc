#include "send_data.h"

SendData::SendData(){
    
}

int SendData::init(char* file)
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

void SendData::end()
{
    strcpy(buf.mtext, "end");
    // int last = strlen(buf.mtext) - 1;
    // /* remove newline at end, if it exists */
    // if (buf.mtext[last] == '\n') buf.mtext[last] = '\0';
    if (msgsnd(msqid, &buf, BUFSIZE, 0) == -1) /* +1 for '\0' */
    perror("msgsnd");
}

int SendData::dispose()
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

void SendData::sendData(char* data)
{
    strcpy(buf.mtext, data);
    // int last = strlen(buf.mtext) - 1;
    /* remove newline at end, if it exists */
    // if (buf.mtext[last] == '\n') buf.mtext[last] = '\0';
    if (msgsnd(msqid, &buf, MSIZE, 0) == -1) /* +1 for '\0' */
    perror("msgsnd");
}