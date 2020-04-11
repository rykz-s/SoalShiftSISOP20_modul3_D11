#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <pthread.h>
#include <sys/types.h>
#include <signal.h>

#define port 8880
static _Atomic unsigned int cli_count = 0;
//int cli_count=0;
static int uid = 10;
int find_match;
typedef struct client
{
    struct sockaddr_in address;
    int sockfd;
    int uid;
    char name[100];
    char password[100];
    int running;
    int addrlen;
} client_t;

typedef struct p_client
{
    int my_health;
    int isPlaying;
    int my_socket;
    client_t* server;
    struct p_client* enemy;
} player_c;

player_c *queue_p[2];

client_t *root, *now;
pthread_mutex_t clients_mutex = PTHREAD_MUTEX_INITIALIZER;

void queue_add(player_c *cl){
    pthread_mutex_lock(&clients_mutex);

    for(int i=0; i <2; ++i){
        if(!queue_p[i]){
            queue_p[i] = cl;
            break;
        }
    }

    pthread_mutex_unlock(&clients_mutex);
}

void queue_remove(int uid){
    pthread_mutex_lock(&clients_mutex);
    player_c *player;
    for(int i=0; i < 2; ++i){
        if(queue_p[i]){
            if(queue_p[i]->server->uid== uid){
                queue_p[i] = NULL;
                break;
            }
        }
    }
    pthread_mutex_unlock(&clients_mutex);
}

void *playingHandling(void *arg)
{
    player_c* player_cl= (void *)arg;
    char result[1000];
    find_match = 0;
    while (player_cl->server->running)
    {
        int val = read(player_cl->my_socket, result, sizeof(result));
        if (val == 0)
        {
            break;
        }
        if (strcmp(result, "login") == 0)
        {
            char username[1000], password[1000], userName[1000], userPassword[1000];
            int val1 = read(player_cl->my_socket, username, sizeof(username));
            int val2 = read(player_cl->my_socket, password, sizeof(password));
            int count = 0;
            FILE *db_read;
            db_read = fopen("akun.txt", "r");
            while (fscanf(db_read, "username: %s\npassword: %s\n\n", userName, userPassword) == 2)
            {
                if (strcmp(userName, username) == 0 && strcmp(userPassword, password) == 0)
                {
                    count = 1;
                }
            }
            fclose(db_read);
            if (count)
            {
                char message[1000];
                printf("Auth Success\n");
                strcpy(message, "login success");
                if (send(player_cl->my_socket, "login success", strlen("login success"), 0) < 0)
                {
                    printf("Send failed\n");
                    exit(0);
                }
                memset(message,'\0',sizeof(message));
            }
            else
            {
                char message[1000];
                printf("Auth Failed\n");
                strcpy(message, "login failed");
                if (send(player_cl->my_socket, "login failed", strlen("login failed"), 0) < 0)
                {
                    printf("Send failed\n");
                    exit(0);
                }
                memset(message,'\0',sizeof(message));
            }
        }
        else if (strcmp(result, "register") == 0)
        {
            char username[1000], password[1000], message[1000], userName[1000], userPassword[1000];
            FILE *db_save;

            db_save = fopen("akun.txt", "a+");
            int rec1 = recv(player_cl->my_socket, username, 1000, 0);
            int rec2 = recv(player_cl->my_socket, password, 1000, 0);
            fprintf(db_save, "username: %s\n", username);
            fprintf(db_save, "password: %s\n\n", password);
            fclose(db_save);
            db_save = fopen("akun.txt", "r");
            while (fscanf(db_save, "username: %s\npassword: %s\n\n", userName, userPassword) == 2)
            {
                printf("Username : %s\n", userName);
                printf("Password : %s\n\n", userPassword);

                memset(userName, '\0', sizeof(userName));
                memset(userPassword, '\0', sizeof(userPassword));
            }
            fclose(db_save);
        }
        else if (strcmp(result, "find") == 0)
        {
            char message[1000],message1[1000];
            queue_add(player_cl);
            cli_count++;
            //if(find_match == 0){
            //    find_match=c_play->my_socket;
            //}
            while(cli_count<2){
                
            }
            strcpy(message,"found");
            player_c *playerOne=queue_p[0], *playerTwo=queue_p[1];
            if(queue_p[0]->my_socket==player_cl->my_socket){
                player_cl->enemy = playerTwo;
            }
            else if(queue_p[1]->my_socket==player_cl->my_socket){
                player_cl->enemy = playerOne;
            }
            queue_remove(playerOne->server->uid);
            queue_remove(playerTwo->server->uid);

            //memset(&queue_p,0,sizeof(player_c)*2);
            cli_count=0;
            player_cl->my_health=100;
            player_cl->enemy->my_health=100;
            send(playerOne->my_socket,message, strlen(message),0) ;
            send(playerTwo->my_socket,message, strlen(message),0) ;
            
            char message2[1000],win[]="win",lose[]="lose",minus[]="minus",message3[1000];
            int valread;
            //while(1){
            //}
            while((valread=recv(player_cl->my_socket,message2,1000,0))>0){
//                pthread_t pl_one;
//                pthread_create(&pl_one,NULL,recvTap, (void *)&playerOne);
//                pthre
                player_cl->enemy->my_health-=10;
                if(player_cl->enemy->my_health<=0){
                    int sent1=send(player_cl->my_socket,win,strlen(win),0);
                    int sent2=send(player_cl->enemy->my_socket,lose,strlen(lose),0);
                    break;
                }
                if(player_cl->my_health<=0){
                    break;
                }
                //int recv1 = recv(player_cl->my_socket, message2, 1000, 0);
                //if(strcmp(message2,"tap")==0){
                    //player_cl->enemy->my_health-=10;
                sprintf(message3, "Health: %d",player_cl->enemy->my_health);
                send(player_cl->enemy->my_socket,message3,strlen(message3),0);
                memset(message3,'\0',sizeof(message3));
                memset(message2,'\0',sizeof(message2));
                //}
            }
            
        }
    }
    /* Handle all communication with the client */

    pthread_detach(pthread_self());
}
void *handle_client(void *arg)
{
    client_t *cl = (client_t *)arg;
    int addrlen = cl->addrlen;
    struct sockaddr_in address = cl->address;
    int server = cl->sockfd;
    while (cl->running)
    {
        client_t *servers = (client_t *)malloc(sizeof(client_t));

        servers = cl;
        player_c *c_play = (player_c *)malloc(sizeof(player_c));
        c_play->my_socket = accept(servers->sockfd, (struct sockaddr *)&servers->address, (socklen_t *)&servers->addrlen);
        c_play->my_health = 100;
        c_play->server = servers;
        pthread_t play_thread;
        pthread_create(&play_thread, NULL, playingHandling, (void *)c_play);
    }
}

int main()
{
    int option = 1;
    /* Socket settings */
    int listenfd = socket(AF_INET, SOCK_STREAM, 0);
    if (listenfd < 0)
    {
        printf("error");
        exit(0);
    }

    if (setsockopt(listenfd, SOL_SOCKET, (SO_REUSEPORT | SO_REUSEADDR), (char *)&option, sizeof(option)) < 0)
    {
        perror("ERROR: setsockopt failed");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_info, client_info;
    int s_addrlen = sizeof(server_info);
    memset(&server_info, 0, s_addrlen);

    server_info.sin_family = AF_INET;
    server_info.sin_addr.s_addr = INADDR_ANY;
    server_info.sin_port = htons(port);

    /* Bind */
    if (bind(listenfd, (struct sockaddr *)&server_info, s_addrlen) < 0)
    {
        perror("ERROR: Socket binding failed");
        return EXIT_FAILURE;
    }

    client_t *serv = (client_t *)malloc(sizeof(client_t));
    serv->address = server_info;
    serv->sockfd = listenfd;
    serv->uid = uid++;
    serv->running = 1;
    serv->addrlen = s_addrlen;
    root = serv;
    now = root;
    /* Listen */
    if (listen(serv->sockfd, 10) < 0)
    {
        perror("Can't Listen");
        exit(0);
    }
    pthread_t tid;
    
    if(pthread_create(&tid, NULL, handle_client, (void *)serv)<0){
        perror("Failed create thread");
        exit(EXIT_FAILURE);
    }
    pthread_join(tid,NULL);

    return EXIT_SUCCESS;
}
