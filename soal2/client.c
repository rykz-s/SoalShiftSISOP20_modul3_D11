#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

#define LENGTH 1000
#define port 8880
// Global variables
volatile sig_atomic_t flag = 0;
static struct termios old;
// int sockfd = 0;
int screenOne(int);
int registerUser(int);
int playGame(int);
int mainGame(int);
int login(int);
int found_match=0;

typedef struct p_data{
    int socket;
    int health;
    int win;
    int lose;
}player_data;

void catch_ctrl_c_and_exit(int sig)
{
    flag = 1;
}

void *wait_opponent(){
    while(!found_match){
        printf("Waiting for player...\n");
        sleep(1);
    }
}

void *send_msg_handler(void *arg) {
    char message[1000] ="tap";
    player_data *data = (player_data *)arg;
    while (1){
        // sprintf(message, 1000, "tap %d",data->health);
        if(data->lose || data->win)
        {
            break;
        }
        char input = getchar();
            printf("\n");
        if (input == ' ' && data->health>0)
        {
            send(data->socket, message, 1000, 0);
            printf("hit!!\n");
        } 

    }
    catch_ctrl_c_and_exit(2);
    pthread_exit(NULL);
}

void *recv_msg_handler(void *arg) {
    char receiveMessage[1000];
    int valread;
    player_data *data = (player_data *)arg;
    while((valread=read(data->socket,receiveMessage,sizeof(receiveMessage)))){
        if(strcmp(receiveMessage,"win")==0){
            printf("Game berakhir kamu menang\n");
            memset(receiveMessage,'\0',sizeof(receiveMessage));
            data->win=1;
            return NULL;
        }
        if(strcmp(receiveMessage,"lose")==0){
            printf("Game berakhir kamu kalah\n");
            memset(receiveMessage,'\0',sizeof(receiveMessage));
            data->lose=1;
            return NULL;
        }
        printf("%s\n",receiveMessage);
        memset(receiveMessage,'\0',sizeof(receiveMessage));
    }
    catch_ctrl_c_and_exit(2);
    pthread_exit(NULL);
}

void *thread_g()
{

    /* Socket settings */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    int s_addrlen = sizeof(server_addr);
    memset(&server_addr, '0', s_addrlen);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if(inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr)<=0) {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }
    // Connect to Server
    int err = connect(sockfd, (struct sockaddr *)&server_addr, s_addrlen);
    if (err == -1)
    {
        printf("ERROR: connect\n");
        exit(0);
    }
    int option=0, running=1;
    while (running)
    {
        if(option==0)option=screenOne(sockfd);
        else if(option==1)option=login(sockfd);
        else if (option==2)option=registerUser(sockfd);
        else if (option==3)option=mainGame(sockfd);
        else if(option==4)option=playGame(sockfd);
    }
    close(sockfd);
}

int main()
{
    signal(SIGINT, catch_ctrl_c_and_exit);
    pthread_t game_thread;
    pthread_create(&game_thread, NULL, thread_g, NULL);
    pthread_join(game_thread, NULL);
    return EXIT_SUCCESS;
}

int screenOne(int sock)
{
    char choice[1000];
    printf("---------------Welcome to Tap Tap Game---------------\n");
    printf("1. Login\n");
    printf("2. Register\n");
    printf("Which one do you want : ");
    scanf("%s", choice);
    if (strcmp(choice, "login") == 0)
    {
        return 1;
    }
    else if (strcmp(choice, "register") == 0)
    {
        return 2;
    } else
    {
        return 0;
    }

}

int registerUser(int sockfd)
{
    char username[1000], password[1000], reg[1000]="register";

    printf("Username : ");
    scanf("%s", username);

    printf("Password : ");
    scanf("%s", password);

    send(sockfd, reg, 1000, 0);
    send(sockfd, username, 1000,0);
    send(sockfd, password, 1000,0);

    char result[1000];
    printf("register success\n");
    return 0;
}

int playGame(int sock)
{
    char buffer[1000];
    player_data *player= (player_data *)malloc(sizeof(player_data));
    player->socket = sock;
    player->health = 100;
    player->win=0;
    player->lose=0;

    pthread_t f_match;
    pthread_create(&f_match,NULL, wait_opponent,NULL);
    int receive = recv(player->socket, buffer, 1000, 0);

    if(strcmp(buffer,"found")==0){
        found_match=1;
    }
    pthread_cancel(f_match);
    found_match=0;
    printf("Game dimulai silahkan tap tap secepat mungkin\n");
    pthread_t rcv_msd_thread;
    pthread_create(&rcv_msd_thread,NULL, recv_msg_handler,(void *)player);
     struct termios new;
    tcgetattr(0,&old);
    new= old;
    new.c_lflag &= (~ICANON);
    new.c_cc[VTIME] = 0;
    new.c_cc[VMIN] = 1;
    tcsetattr(0,TCSANOW,&new);
    pthread_t send_msd_thread;
    pthread_create(&send_msd_thread,NULL, send_msg_handler,(void *)player);
    while (1) {
        if(flag) {
            tcsetattr(0,TCSANOW,&old);
            flag=0;
            break;
        }
    }

    return 3; 
}

int mainGame(int sock)
{
    char choice[1000];
    sleep(1);
    printf("---------------Let's Play The Game---------------\n");
    printf("1. Find Match\n");
    printf("2. Log Out\n");
    printf("Which one do you want : ");
    scanf("%s", choice);
    if (strcmp(choice, "find") == 0)
    {
        send(sock, choice, 1000,0);
        return 4;
    }
    else if (strcmp(choice, "logout") == 0)
    {
        return 0;
    }
    else return 3;
}

int login(int sock)
{
    char username[1000], password[1000], login[1000]="login";

    printf("Username : ");
    scanf("%s", username);
    printf("Password : ");
    scanf("%s", password);
    send(sock, login, 1000, 0);
    send(sock, username, 1000,0);
    send(sock, password, 1000,0);
    char result[1000];
    int valread = read(sock, result, sizeof(result));
    printf("%s\n", result);
    if (strcmp(result, "login failed") == 0)
    {
        return 0;
    }
    else
        return 3;
}
