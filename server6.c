#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define SERVER_PORT 5432
#define MAX_PENDING 1
#define MAX_LINE 256

int main() {
    struct sockaddr_in sin;
    char buf[MAX_LINE];
    int len;
    int s, new_s;
    /* build address data structure */
    bzero((char *)&sin, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(SERVER_PORT);
    /* setup passive open */
    if ((s = socket(PF_INET, SOCK_DGRAM, 0)) < 0) {
        perror(" ERROR opening socket");
        exit(1);
    }
    if ((bind(s, (struct sockaddr *)&sin, sizeof(sin))) < 0) {
        perror("Error in binding socket");
        exit(1);
    }
    
    /* wait for connection, then receive and print text */
   
        while (len = recv(s, buf, sizeof(buf), 0)){
            fputs(buf, stdout);
        }
        close(s);

}
