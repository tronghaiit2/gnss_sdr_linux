/* Filename: msgq_send.c */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

#define PERMS 0644
struct my_msgbuf {
   long mtype;
   char mtext[200];
};


int main(void) {
   struct my_msgbuf buf;
   int msqid;
   int len;
   key_t key;
   // system("touch /tmp/tracking.txt");

   int MSIZE = 256;

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
   
   if ((msqid = msgget(key, PERMS | IPC_CREAT)) == -1) {
      perror("msgget");
      exit(1);
   }
   printf("message queue: ready to send messages.\n");
   printf("Enter lines of text, ^D to quit:\n");
   buf.mtype = 1; /* we don't really care in this case */

   int i = 0;
   while(i < 10) {
      // char* str;
      // sprintf(str, "{\"id\": %d, \"early\": %f, \"prompt\": %f, \"late\": %f}", i, 0.2, 0.5, 0.8);
      char *str = (char*) malloc(sizeof(char) * BUFSIZE);
      snprintf(str, MSIZE, "{\"id\": %d, \"early\": %f, \"prompt\": %f, \"late\": %f}", i, 0.2, 0.5, 0.8);
      strcpy(buf.mtext, str);
      len = strlen(buf.mtext);
      free(str);
      /* remove newline at end, if it exists */
      if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
      if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
      perror("msgsnd");
      i++;
      sleep(1.0);
   }

   // while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
   //    len = strlen(buf.mtext);
   //    /* remove newline at end, if it exists */
   //    if (buf.mtext[len-1] == '\n') buf.mtext[len-1] = '\0';
   //    if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
   //    perror("msgsnd");
   // }

   strcpy(buf.mtext, "end");
   len = strlen(buf.mtext);
   if (msgsnd(msqid, &buf, len+1, 0) == -1) /* +1 for '\0' */
   perror("msgsnd");
   
   // if (msgctl(msqid, IPC_RMID, NULL) == -1) {
   //    perror("msgctl");
   //    exit(1);
   // }
   printf("message queue: done sending messages.\n");
   return 0;
}