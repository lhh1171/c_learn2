#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#define PORT 6666
#define MAX_MSG_LENGTH 1024
#define END_STRING "end\n"
//哪一个文件哪一行出现问题
#define perro(x) {fprintf(stderr, "%s:%d: %s: %s\n", __FILE__, __LINE__, x, strerror(errno));exit(1);}
void send_cmd(int sock, int pid) {
    char str[MAX_MSG_LENGTH] = {0};
    printf("> ");
    while (fgets(str, MAX_MSG_LENGTH, stdin) == str) {
        if(strncmp(str, END_STRING, strlen(END_STRING)) == 0) break;
        if(send(sock, str, strlen(str)+1, 0) < 0) perro("send");
    }
    kill(pid, SIGKILL);
    printf("Goodbye.\n");
}

void receive(int sock) {
    char buf[MAX_MSG_LENGTH] = {0};
    int filled = 0;
    while(filled = recv(sock, buf, MAX_MSG_LENGTH-1, 0)) {
        buf[filled] = '\0';
        printf("%s", buf);
        fflush(stdout);
    }
    printf("Server disconnected.\n");
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) perro("socket");

    struct in_addr server_addr;
    if(!inet_aton("127.0.0.1", &server_addr)) perro("inet_aton");

    struct sockaddr_in connection;
    //协议族
    connection.sin_family = AF_INET;
    //ip,将127.0.0.1
    memcpy(&connection.sin_addr, &server_addr, sizeof(server_addr));
    //port
    connection.sin_port = htons(PORT);
    if (connect(sockfd, (const struct sockaddr*) &connection, sizeof(connection)) != 0) perro("connect");

    int pid;
    pid = fork();
    //一个进程发一个进程收
    if(pid) send_cmd(sockfd, pid);
    else receive(sockfd);

    return 0;
}