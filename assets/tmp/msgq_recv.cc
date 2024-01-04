/* Filename: msgq_recv.c */
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};

int main(void) {
   struct my_msgbuf buf;
   int msqid;
   int toend;
   key_t key;
   // system("touch /tmp/tracking.txt");

   const char* file = "/tmp/tracking.txt";
   int BUFSIZE = 32;
   char *cmd = (char*) malloc(sizeof(char) * BUFSIZE);
   snprintf(cmd, BUFSIZE, "touch %s", file);
   system(cmd);
   free(cmd);
   
   if ((key = ftok(file, 'B')) == -1) {
      perror("ftok");
      exit(1);
   }
   
   if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) { /* connect to the queue */
      perror("msgget");
      exit(1);
   }
   printf("message queue: ready to receive messages.\n");
   
   for(;;) { /* normally receiving never ends but just to make conclusion 
             /* this program ends wuth string of end */
      ssize_t siz = msgrcv(msqid, &buf, sizeof(buf.mtext), 0, IPC_NOWAIT);
      if (siz<0) {
         if (errno == ENOMSG) 
         {
            sleep(0.1);
         }
         else {
            perror("msgrcv");
         }
      } 
      else {
         printf("recvd: \"%s\"\n", buf.mtext);
         toend = strcmp(buf.mtext,"end");
         if (toend == 0)
         break;
      }
   }

   if (msgctl(msqid, IPC_RMID, NULL) == -1) {
      perror("msgctl");
      exit(1);
   }
   printf("message queue: done receiving messages.\n");
   
   // system("rm /tmp/tracking.txt");
   cmd = (char*) malloc(sizeof(char) * BUFSIZE);
   snprintf(cmd, BUFSIZE, "rm %s", file);
   system(cmd);
   free(cmd);
   return 0;
}