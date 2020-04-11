# SoalShiftSISOP20_modul3_D11
**Soal 1:** 
---
Poke*ZONE adalah sebuah game berbasis text terminal mirip dengan Pokemon GO.
Ketentuan permainan sebagai berikut:
a. Menggunakan IPC-shared memory, thread, fork-exec.
b. Kalian bebas berkreasi dengan game ini asal tidak konflik dengan
requirements yang ada. (Contoh: memberi nama trainer, memberi notifikasi
kalau barang di shop sudah penuh, dan lain-lain).
c. Terdapat 2 code yaitu soal2_traizone.c dan soal2_pokezone.c.
d. soal2_traizone.c mengandung fitur:
i. Normal Mode (3 Menu)
1. Cari Pokemon
a. Jika diaktifkan maka setiap 10 detik akan memiliki
60% chance untuk menemui pokemon bertipe normal,
rare, legendary dengan encounter rate sesuai pada
tabel di bawah (Gunakan Thread).
b. Cari pokemon hanya mengatur dia menemukan
pokemon atau tidak. Untuk tipe pokemon dan pokemon
tersebut shiny atau tidak diatur oleh soal2_pokezone.c.
c. Opsi “Cari Pokemon” akan berubah jadi “Berhenti
Mencari” ketika state mencari pokemon aktif.
d. State mencari pokemon hanya bisa dihentikan ketika
pokemon sudah ditemukan atau trainer memilih untuk
berhenti pada menu.
e. Jika menemui pokemon maka akan masuk ke Capture
Mode.
f. Untuk mempermudah boleh menambah menu go to
capture mode untuk berpindah dari mode normal ke
mode capture setelah menemukan pokemon dari
thread Cari Pokemon.

2. Pokedex
a. Melihat list pokemon beserta Affection Point (AP) yang
dimiliki.
b. Maksimal 7 pokemon yang dimiliki.
c. Jika menangkap lebih dari 7 maka pokemon yang baru
saja ditangkap akan langsung dilepas dan
mendapatkan pokedollar sesuai dengan tabel dibawah.
d. Setiap pokemon yang dimiliki, mempunyai Affection
Point (AP) dengan initial value 100 dan akan terus
berkurang sebanyak -10 AP/10 detik dimulai dari
waktu ditangkap (Gunakan Thread).
e. Jika AP bernilai 0, maka pokemon tersebut memiliki
90% chance untuk lepas tanpa memberikan pokedollar
ke trainer atau 10% chance untuk reset AP menjadi 50
AP.
f. AP tidak akan berkurang jika dalam Capture Mode.

g. Di Pokedex trainer juga bisa melepas pokemon yang
ditangkap dan mendapat pokedollar sesuai dengan
tabel dibawah.
h. Bisa memberi berry ke semua pokemon yang dimiliki
untuk meningkatkan AP sebesar +10 (1 berry untuk
semua pokemon yang ada di pokedex).

3. Shop
a. Membeli item dari soal2_pokezone.
b. Maksimal masing-masing item yang dapat dibeli dan
dipunya oleh trainer adalah 99.

ii. Capture Mode (3 Menu)
1. Tangkap → Menangkap menggunakan pokeball. Berhasil
ditangkap maupun tidak, pokeball di inventory -1 setiap
digunakan.
2. Item → Menggunakan item sesuai dengan tabel item dibawah
(hanya lullaby powder).
3. Keluar → Keluar dari Capture Mode menuju Normal Mode.
● Pokemon tersebut memiliki peluang untuk lari dari trainer
sesuai dengan persentase escape rate pada tabel dibawah
(gunakan thread).
e. soal2_pokezone.c mengandung fitur:
i. Shutdown game → Mematikan program soal2_pokezone dan
soal2_traizone (Gunakan fork-exec).
ii. Jual Item (Gunakan Thread)
1. Stock awal semua item adalah 100.
2. Masing-masing item akan bertambah +10 item/10 detik.
3. Maximum item yang dalam shop adalah 200.
4. List item ada pada tabel dibawah.
5. Gunakan thread untuk implementasi lullaby powder dibuatkan
masing-masing 1 thread.

iii. Menyediakan Random Pokemon (Gunakan Thread)
1. Setiap tipe pokemon memiliki peluang 1/8000 untuk jadi shiny
pokemon. (Random dulu antara normal, rare, legendary sesuai
rate mereka, baru setelah itu di random dengan peluang
1/8000 untuk tahu dia shiny atau tidak).
2. Shiny Pokemon meningkatkan escape rate sebesar +5%
(misal: tipe normal jadi 10%), capture rate berkurang menjadi
-20% (misal: tipe rare jadi 30%), dan pokedollar dari melepas
+5000 (misal: tipe legendary jadi 5200 pokedollar).
3. Setiap 1 detik thread ini akan mengkalkulasi random ulang lagi
untuk nantinya diberikan ke soal2_traizone.
---
**Jawaban**
---
```java
Soal meminta untuk membuat program game berbasis text-editor menggunakan thread, fork-exec dan IPC-Shared Memory.
```
---
**Soal 2:**
---
Qiqi adalah sahabat MamMam dan Kaka. Qiqi , Kaka dan MamMam sangat senang
bermain “Rainbow six” bersama-sama , akan tetapi MamMam sangat Toxic ia selalu
melakukan Team killing kepada Qiqi di setiap permainannya. Karena Qiqi orang yang
baik hati, meskipun marah Qiqi selalu berkata “Aku nggk marah!!”. Kaka ingin
meredam kemarahan Qiqi dengan membuatkannya sebuah game yaitu TapTap
Game. akan tetapi Kaka tidak bisa membuatnya sendiri, ia butuh bantuan mu. Ayo!!
Bantu Kaka menenangkan Qiqi.
TapTap Game adalah game online berbasis text console. Terdapat 2 program yaitu
tapserver.c dan tapplayer.c
Syarat :
- Menggunakan Socket, dan Thread
Hint :
- fwrite, fread
Spesifikasi Game :

CLIENT SIDE

Screen 1 :
1. Login
2. Register
Choices : {your input}
★ Pada screen 1 kalian dapat menginputkan “login”, setelah menekan enter
anda diminta untuk menginputkan username dan password seperti berikut
Screen 1 :
1. Login
2. Register
Choices : login
Username : { ex : qiqi }
Password : { ex : aku nggak marah!! }
★ Jika login berhasil maka akan menampilkan pesan “login success”, jika gagal
akan menampilkan pesan “login failed” (pengecekan login hanya mengecek
username dan password, maka dapat multi autentikasi dengan username dan
password yang sama)
★ Pada screen 1 kalian juga dapat menginputkan “register”, setelah menekan
enter anda diminta untuk menginputkan username dan password sama
halnya seperti login
★ Pada register tidak ada pengecekan unique username, maka setelah register
akan langsung menampilkan pesan “register success” dan dapat terjadi
double account
★ Setelah login berhasil maka anda berpindah ke screen 2 dimana
menampilkan 2 fitur seperti berikut.

Screen 2 :
1. Find Match
2. Logout
Choices : {your input}
★ Pada screen 2 anda dapat menginputkan “logout” setelah logout anda akan
kembali ke screen 1
★ Pada screen 2 anda dapat menginputkan “find”, setelah itu akan
menampilkan pesan “Waiting for player ...” print terus sampai menemukan
lawan
★ Jika menemukan lawan maka akan menampilkan pesan “Game dimulai
silahkan tap tap secepat mungkin !!”
★ Pada saat game dimulai diberikan variable health = 100,dan anda dapat
men-tap (menekan space pada keyboard tanpa harus menekan enter)
★ Pada saat anda men-tap maka akan menampilkan pesan “hit !!”, dan pada
lawan healthnya akan berkurang sebanyak 10 kemudian pada lawan
menampilkan pesan status healthnya sekarang. (conclusion : anda tidak bisa
melihat status health lawan)
★ Jika health anda <= 0 maka akan menampilkan pesan “Game berakhir kamu
kalah”, apabila lawan anda healthnya <= 0 maka akan menampilkan pesan
”Game berakhir kamu menang”
★ Setelah menang atau kalah maka akan kembali ke screen 2

SERVER SIDE

Pada saat program pertama kali dijalankan maka program akan membuat file
akun.txt jika file tersebut tidak ada. File tersebut digunakan untuk menyimpan
username dan password.

Pada saat user berhasil login maka akan menampilkan pesan “Auth success” jika
gagal “Auth Failed”.
Pada saat user sukses meregister maka akan menampilkan List account yang terdaftar (username dan password harus terlihat)

**Jawaban**
---
```c
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
```
---
```c
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
        //if (strcmp(receiveMessage,"minus")==0)
        //{
        //    if (data->health>0)
        //    {
        //        data->health-=10;
        //        printf("Health : %d\n",data->health);
        //    }
        //    memset(receiveMessage,'\0',sizeof(receiveMessage));
        //}
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
```
**Penjelasan**
---
Dimulai dari client :
```c
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
```
Potongan kode ini merupakan variable global beserta prototipe fungsi. Terdapat juga struct p_data untuk mendefinisikan player yang akan bermain. fungsi catch_ctrc_c_and_exit merupakan fungsi untuk menanggapi ketika user menekan tombol Ctrl+C atau exit.
```c
int main()
{
    signal(SIGINT, catch_ctrl_c_and_exit);
    pthread_t game_thread;
    pthread_create(&game_thread, NULL, thread_g, NULL);
    pthread_join(game_thread, NULL);
    return EXIT_SUCCESS;
}
```
potongan kode berikut berguna untuk memberi sinyal terhadap catch_ctrc_c_and_exit dan membuat thread yang bernama thread_g yang berisi:
```c
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
```
thread_g/thread game berfungsi untuk menyambungkan socket, lalu menyambungkan ke server. Setelah tersambung dengan server, nantinya akan ada opsi /pilihan menu.
```c
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
```
fungsi screenOne berguna sebagai tampilan awal dari game ini. Disini user akan diminta untuk melakukan login atau register.
```c
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
```
pada bagian ini merupakan menu login. Disini user akan diminta untuk menginputkan username dan juga password. Nantinya data ini akan dikirim, lalu dari server akan memberi jawaban apakah user sukses melakukan login atau gagal.
```c
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
```
Disini merupakan bagian untuk registrasi user baru. Nantinya user akan diminta untuk menginput username dan juga password yang diinginkan. Setelah itu, data akan dikirim keserver berupa kode registrasi, username dan password lalu menampilkan alert register success.
```c
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
```
Maingame berguna untuk menampilkan fitur yang bisa dipakai setelah berhasil login. Nantinya user akan memilih antara find/logout
```c
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
```
Potongan kode ini merupakan tahapan lanjut jika memilih find. Pertama akan membuat struct untuk player yang berisi socket dan health dari player tersebut. lalu membuat thread untuk fungsi wait_opponent. Jika lawan telah ketemu, maka user akan menerima pesan dari server yaitu "found".Lalu jika telah menerima pesan "found" maka akan membuat thread baru untuk menangani segala permintaan receive. Lalu ada juga thread yang berfungsi menangani segala permintaan send_msg. Lalu ada pengaturan termios:
```c
struct termios new;
tcgetattr(0,&old);
new= old;
new.c_lflag &= (~ICANON);
new.c_cc[VTIME] = 0;
new.c_cc[VMIN] = 1;
tcsetattr(0,TCSANOW,&new);
```
yang berfungsi agar ketika menginputkan spasi tidak perlu menekan enter.
```c
void *wait_opponent(){
    while(!found_match){
        printf("Waiting for player...\n");
        sleep(1);
    }
}
```
berguna untuk menunggu sambil mencetak hingga menemukan lawan
```c
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
```
recv_msg_handler menangani seluruh permintaan yang berkaitan dengan menerima pesan. Disini diproses jika server mengirim pesan menang kepada user, mengirim pesan kalah kepada user atau mengirim sisa darah yang ada pada user.
```c
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
```
berfungsi untuk mengirim data yang berupa spasi yang terus ditekan akan dikirim ke server dengan kode "tap" sambil mengeluarkan pesan "hit!!".Di bagian ini juga mengecek apakah player telah menang atau kalah agar nantinya bisa keluar dari infinite loop.

Bagian Server:
```c
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
```
Potongan kode ini untuk menjelaskan kegunaan variabel global yang ada beserta struct. port berguna mendefinisikan port, lalu cli_count untuk menghitung berapa orang yang berada dalam room(untuk dilakukan finding match/mencari lawan).Lalu struct client_t untuk menyimpan informasi mengenai server yang ada. Disini yang menajadi primary key nya adalah uid. Struct player_c berguna untuk menyimpan informasi berkaitan dengan dua pemain yang sedang berlawanan. struct queue_p berguna sebagai tempat mencari lawan.

```java
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
```
pada bagian ini ,dapat dianggap sebagai room yang berfungsi menaruh player yang sedang ingin mencari lawan. queue_add untuk menaruh player tersebut kedalam room dan queue remove berguna jika room sudah penuh/ 2 player telah bertanding, maka akan dihapus agar bisa digunakan untuk pemain lain untuk bertanding. Disini menggunakan mutex agar data yang dimasukkan teratur.
```java
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
```
Potongan kode ini  berguna untuk membuat socket untuk server yang akan dibind dan di listen. Informasi mengenai server akan ditaurh pada struct client_t. Lalu akan dibuat thread baru bernama handle_client.
```java
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
```
fungsi ini berguna untuk menerima koneksi dari client yang ingin terhubung ke server. Nanti client ini akan dianggap sebagai player yang ingin bermain dan diinisialisasi health nya menjadi 100 dan menyimpan data mengenai server juga. Lalu akan dibuat thread baru bernama playingHandling.
Playing Handling bagian 1:
```java
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
```
berguna untuk menerima pesan dari klien. Jika pesannya merupakan login, maka akan membaca 2 pesan berikutnya yang merupakan username dan password. Lalu file akun.txt akan dibuka dan dicek sesuai pattern penyimpanan username dan password, apakah sesuai username dan password yang diinput client terhadap akun.txt. Jika sesuai maka server akan menulis "Auth Success" sambil mengirim pesan balik ke client bahwasannya login berhasil. Jika gagal server akan menulis "Auth Failed" sambil mengirim pesan balik ke client bahwasannya login gagal.

PlayingHandling bagian 2:
```java
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
```
Jika pesan yang dikirim user adalah register, maka file akun.txt akan dibuka dan username dan password yang dikirim user akan disimpan diakhir file. Lalu file akun.txt ditutup dan dibuka kembali untuk menampilkan list nama user dan password yang terdaftar.

PlayingHandling bagian 3:
```java
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
```
Jika user mengirim pesan "find", maka user yang telah diubah menjadi player akan ditaruh dalam queue yang dianggap seperti room lalu menunggu hingga ada user yang ingin bermain. Jika sudah ada dua orang, maka server akan mengirim pesan balik yang menyatakan bahwa pemain telah ketemu. Lalu room akan menghapus kedua user itu agar bisa dipakai pemain-pemain yang lain. Nantinya user akan diisi dengan banyak value seperti health, dsb. Disini user akan menerima pesan, Jika seorang user melakukan "tap" maka server akan mengirim pengurangan health ke socket enemy dan mengirim balik "Health yang dimiliki oleh enemy yang diserang". Jika enemy yang diserang, healthnya telah mencapai kurang dari sama dengan nol, maka server akan mengirim pesan menang dan kalah.

**Soal 3:**
---
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya(tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder haUser akan dianggap sebagai silnya terdapat di working
directory ketika program kategori tersebut dijalankan.
● Semisal program dijalankan:

-# File kategori terletak di /home/izone/kategori
$ ./kategori -f path/to/file1.jpg path/to/file2.c path/to/file3.zip

#Hasilnya adalah sebagai berikut

/home/izone
|-jpg
|--file1.jpg
|-c
|--file2.c
|-zip
|--file3.zi
● Pada opsi -f tersebut, user bisa menambahkan argumen file yang bisa
dikategorikan sebanyak yang user inginkan seperti contoh di atas.

● Pada program kategori tersebut, folder jpg,c,zip tidak dibuat secara manual,
melainkan melalui program c. Semisal ada file yang tidak memiliki ekstensi,
maka dia akan disimpan dalam folder “Unknown”.

● Program kategori ini juga menerima perintah (*) seperti di bawah;
$ ./kategori \*

● Artinya mengkategori seluruh file yang ada di working directory ketika
menjalankan program C tersebut.

● Selain hal itu program C ini juga menerima opsi -d untuk melakukan kategori
pada suatu directory. Untuk opsi -d ini, user hanya bisa menginput 1 directory
saja, tidak seperti file yang bebas menginput file sebanyak mungkin.
$ ./kategori -d /path/to/directory/

● Hasilnya perintah di atas adalah mengkategorikan file di /path/to/directory dan
hasilnya akan disimpan di working directory di mana program C tersebut
berjalan (hasil kategori filenya bukan di /path/to/directory).

● Program ini tidak rekursif. Semisal di directory yang mau dikategorikan, atau
menggunakan (*) terdapat folder yang berisi file, maka file dalam folder
tersebut tidak dihiraukan, cukup file pada 1 level saja.

● Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan
secara paralel sehingga proses kategori bisa berjalan lebih cepat. Dilarang
juga menggunakan fork-exec dan system.

● Silahkan download soal3.zip sebagai percobaan. Namun silahkan
dicoba-coba sendiri untuk kemungkinan test case lainnya yang mungkin
belum ada di soal3.zip.

**Jawaban**
---
```c
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h> 
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#define MAX 1000

char cwd[MAX];

int isFileExist(char *path) //jika 0 bukan file
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}

char *get_filename_ext(char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}

void* playandcount(void *arg){ 
    char *fullname = (void *) arg;
    //cek exist ga
    int file_exist = isFileExist(fullname);
    char source[MAX], dest[MAX],path[MAX];
    if(file_exist){
        //cari extension
        char* ext = get_filename_ext(fullname);
        //jadi huruf kecil
        char *abspath = (void *) arg;
        if(strcmp(ext,"")!= 0){
            strcpy(source,abspath);
            strcpy(dest, cwd);
            strcat(dest, "/");
            char* file_path= strrchr(fullname, '/');
            strcpy(path,file_path);
            for(int i = 0; ext[i];i++){
                ext[i]= tolower(ext[i]);
            }
            mkdir(ext, 0777);
            strcat(dest, (ext));
            strcat(dest,path);
            rename(source,dest);
        }
        else{ 
            printf("2");
            mkdir("Unknown",0777);
            strcpy(dest, cwd);
            strcat(dest, "/");
            strcat(dest,"Unknown"); 
            char* file_path= strrchr(fullname, '/');
            strcat(dest,file_path);
            rename(abspath,dest);
        }
    }
    else printf("There's no file like that\n"); 
    pthread_exit(0);
}

int main(int argc, char** argv) {
    getcwd(cwd,sizeof(cwd));
    pthread_t tid[MAX];
    int i = 0; 
    int test;   
    if(strcmp(argv[1], "-f") == 0){
        for(test = 2; test < argc; test++){
            pthread_create(&(tid[i]),NULL,playandcount,argv[test]);
            pthread_join(tid[i],NULL);
            i++;
        }
    }
    else if(strcmp(argv[1],"*") == 0){
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                char filePath[1000];
                if(isFileExist(dir->d_name)){
                    strcpy(filePath, cwd);
                    strcat(filePath, "/");
                    strcat(filePath, dir->d_name);
                    printf("%s\n",filePath);
                    pthread_create(&(tid[i]),NULL,playandcount,filePath); 
                    pthread_join(tid[i],NULL);
                    i++;
                }
            }
            closedir(d);
        }
    }
    else if(strcmp(argv[1],"-d") == 0){
        DIR *d;
        struct dirent *dir;
        d = opendir(argv[2]);
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                char filePath[1000];
                strcpy(filePath,argv[2]);
                strcat(filePath, "/");
                strcat(filePath,dir->d_name);
                if(isFileExist(filePath)){
                    pthread_create(&(tid[i]),NULL,playandcount,filePath); 
                    pthread_join(tid[i],NULL);
                    i++;
                }
            }
            closedir(d);
        }
        else printf("No Dir\n");
    }
}
```
**Penjelasan**
---
```c
int isFileExist(char *path) //jika 0 bukan file
{
    struct stat path_stat;
    stat(path, &path_stat);
    return S_ISREG(path_stat.st_mode);
}
```
berguna untuk mengecek apakah path yang sedang kita tuju file/bukan. Jika bukan file akan mereturn 0.
```c
char *get_filename_ext(char *filename) {
    char *dot = strrchr(filename, '.');
    if(!dot || dot == filename) return "";
    return dot + 1;
}
```
berguna untuk mengambil suatu ekstensi dari suatu file tanpa menyertakan '.'
```c
int main(int argc, char** argv) {
    getcwd(cwd,sizeof(cwd));
    pthread_t tid[MAX];
    int i = 0; 
    int test;   
    if(strcmp(argv[1], "-f") == 0){
        for(test = 2; test < argc; test++){
            pthread_create(&(tid[i]),NULL,playandcount,argv[test]);
            pthread_join(tid[i],NULL);
            i++;
        }
    }
```
```getcwd(cwd,sizeof(cwd));``` digunakan untuk mendapatkan current working directory
```pthread_t tid[MAX];``` inisialisasi awal thread
```if(strcmp(argv[1], "-f") == 0){
        for(test = 2; test < argc; test++){
            pthread_create(&(tid[i]),NULL,playandcount,argv[test]);
            pthread_join(tid[i],NULL);
            i++;
        }
    }
``` 
Cek apakah argumen yang diberikan adalah -f jika true maka lanjut dimana user bisa menambahkan argumen file yang ingin dikategorikan sesuka hati user.
```c
else if(strcmp(argv[1],"*") == 0){
        DIR *d;
        struct dirent *dir;
        d = opendir(".");
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                char filePath[1000];
                if(isFileExist(dir->d_name)){
                    strcpy(filePath, cwd);
                    strcat(filePath, "/");
                    strcat(filePath, dir->d_name);
                    printf("%s\n",filePath);
                    pthread_create(&(tid[i]),NULL,playandcount,filePath); 
                    pthread_join(tid[i],NULL);
                    i++;
                }
            }
            closedir(d);
        }
    }
```
Pada potongan kode berikut ini berguna untuk mengecek jika mode yang dimasukkan user adalah "*" yang berarti bahwa user menginginkan untuk mengkategorikan file pada lokasi dimana file c ini berada. Fungsi opendir untuk menjadikan direktori file dijalankan sebagai pusat, lalu readdir untuk membuka direktori sekaligus mengecek apakah direktori kosong atau tidak. Nantinya akan dibuat thread yang meng-passing filePath yang merupakan path dari file c ini dijalankan. disini filePath hanya akan mengecek file, karena sudah diperiksa oleh fungsi isFileExist.
```c
else if(strcmp(argv[1],"-d") == 0){
        DIR *d;
        struct dirent *dir;
        d = opendir(argv[2]);
        if (d) {
            while ((dir = readdir(d)) != NULL) {
                char filePath[1000];
                strcpy(filePath,argv[2]);
                strcat(filePath, "/");
                strcat(filePath,dir->d_name);
                if(isFileExist(filePath)){
                    pthread_create(&(tid[i]),NULL,playandcount,filePath); 
                    pthread_join(tid[i],NULL);
                    i++;
                }
            }
            closedir(d);
        }
        else printf("No Dir\n");
    }
```
Potongan kode ini berguna untuk memeriksa apakah mode yang dimasukkan user adalah "-d". Jika iya, maka akan mengecek dengan opendir apakah direktori yang user masukkan ada/exist. Ketika direktori berhasil dibuka, akan melakukan iterasi pada seluruh file ataupun folder dalam suatu direktori. Lalu  direktori exist, maka akan membuat thread yang mempassing path dari suatu file. Disini yang akan diperiksa cuma file saja sebab telah diperiksa oleh fungsi isFileExist. 
```c
void* playandcount(void *arg){
    char *fullname = (void *) arg;
    //cek exist ga
    int file_exist = isFileExist(fullname);
    char source[MAX], dest[MAX],path[MAX];
    if(file_exist){
        //cari extension
        char* ext = get_filename_ext(fullname);
        //jadi huruf kecil
        char *abspath = (void *) arg;
        if(strcmp(ext,"")!= 0){
            strcpy(source,abspath);
            strcpy(dest, cwd);
            strcat(dest, "/");
            char* file_path= strrchr(fullname, '/');
            strcpy(path,file_path);
            for(int i = 0; ext[i];i++){
                ext[i]= tolower(ext[i]);
            }
            mkdir(ext, 0777);
            strcat(dest, (ext));
            strcat(dest,path);
            rename(source,dest);
        }
        else{ 
            printf("2");
            mkdir("Unknown",0777);
            strcpy(dest, cwd);
            strcat(dest, "/");
            strcat(dest,"Unknown"); 
            char* file_path= strrchr(fullname, '/');
            strcat(dest,file_path);
            rename(abspath,dest);
        }
    }
    else printf("There's no file like that\n"); 
    pthread_exit(0);
}
```
Fungsi ini berguna untuk melakukan inti dari yang diminta soal. Pertama akan mengecek apakah path yang dipassing adalah file atau tidak. Jika iya, maka akan mengambil ekstensi dari file tersebut dan mengubah ekstensi tersebut menjadi huruf kecil semua lalu membuat foldernya. Terdapat dua tipe file, yaitu yang mempunyai ekstensi dan yang tidak mempunyai. Jika get_filename_ext() dijalankan pada file yang mempunyai ekstensi akan mengembalikan string/char yang berupa ekstensi itu sendiri yang nantinya akan di compare untuk mengambil lokasi file yang ingin dipindahkan sebagai variable source dan loksai file ini dijalankan yang ditambahkan dengan ekstensinya lalu nantinya dipindahkan dengan fungsi rename(). Jika suatu file tidak mempunyai ekstensi yang berarti get_filename_ext() mengembalikan "", nantinya akan dibuat folder bernama Unknown pada variable dest yang telah ditambah dengan lokasi file ini dijalankan. Lalu diambil juga lokasi file yang ingin dipindahkan ke variable abspath, dan akan dipindahkan file tersebut menggunakan fungsi rename().

**Soal 4:**
---
Norland adalah seorang penjelajah terkenal. Pada suatu malam Norland menyusuri
jalan setapak menuju ke sebuah gua dan mendapati tiga pilar yang pada setiap
pilarnya ada sebuah batu berkilau yang tertancap. Batu itu berkilau di kegelapan dan
setiap batunya memiliki warna yang berbeda.
Norland mendapati ada sebuah teka-teki yang tertulis di setiap pilar. Untuk dapat
mengambil batu mulia di suatu pilar, Ia harus memecahkan teka-teki yang ada di
pilar tersebut. Norland menghampiri setiap pilar secara bergantian.
- Batu mulia pertama. Emerald. Batu mulia yang berwarna hijau mengkilat. Pada
batu itu Ia menemukan sebuah kalimat petunjuk. Ada sebuah teka-teki yang berisi:
1. Buatlah program C dengan nama "4a.c", yang berisi program untuk
melakukan perkalian matriks. Ukuran matriks pertama adalah 4x2, dan
matriks kedua 2x5. Isi dari matriks didefinisikan di dalam kodingan. Matriks
nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).
2. Tampilkan matriks hasil perkalian tadi ke layar.

- Batu kedua adalah Amethyst. Batu mulia berwarna ungu mengkilat. Teka-tekinya
adalah:

1. Buatlah program C kedua dengan nama "4b.c". Program ini akan
mengambil variabel hasil perkalian matriks dari program "4a.c" (program
sebelumnya), dan tampilkan hasil matriks tersebut ke layar.
(Catatan!: gunakan shared memory)
2. Setelah ditampilkan, berikutnya untuk setiap angka dari matriks
tersebut, carilah nilai faktorialnya, dan tampilkan hasilnya ke layar dengan
format seperti matriks.

Contoh: misal array [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12], ...],

maka:

1 2 6 24
120 720 ... ...
...

(Catatan! : Harus menggunakan Thread dalam penghitungan
faktorial)
- Batu ketiga adalah Onyx. Batu mulia berwarna hitam mengkilat. Pecahkan
teka-teki berikut!

1. Buatlah program C ketiga dengan nama "4c.c". Program ini tidak
memiliki hubungan terhadap program yang lalu.
2. Pada program ini, Norland diminta mengetahui jumlah file dan
folder di direktori saat ini dengan command "ls | wc -l". Karena sudah belajar
IPC, Norland mengerjakannya dengan semangat.
(Catatan! : Harus menggunakan IPC Pipes)
Begitu batu terakhir berhasil didapatkan. Gemuruh yang semakin lama semakin
besar terdengar. Seluruh tempat berguncang dahsyat, tanah mulai merekah. Sebuah
batu yang di atasnya terdapat kotak kayu muncul ke atas dengan sendirinya.

Sementara batu tadi kembali ke posisinya. Tanah kembali menutup, seolah tidak
pernah ada lubang merekah di atasnya satu detik lalu.
Norland segera memasukkan tiga buah batu mulia Emerald, Amethys, Onyx pada
Peti Kayu. Maka terbukalah Peti Kayu tersebut. Di dalamnya terdapat sebuah harta
karun rahasia. Sampai saat ini banyak orang memburu harta karun tersebut.
Sebelum menghilang, dia menyisakan semua petunjuk tentang harta karun tersebut
melalui tulisan dalam buku catatannya yang tersebar di penjuru dunia. "One Piece
does exist".

**Jawaban**

#4a
```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define LENGTH 4
#define WIDTH 2
#define WIDTH_B 5
#define MAX_THREAD 4

int matrixA[LENGTH][WIDTH];
int matrixB[WIDTH][WIDTH_B];
int matrixC[LENGTH][WIDTH_B];
int step_i = 0;

void* multiplicationMatrix(void* arg){
    int core = step_i++;
    for (int i = core; i < core+1; i++)
    {
        for (int j = 0; j < WIDTH_B; j++)  
            for (int k = 0; k < WIDTH; k++)  
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j]; 
    }
    
}

int main(){
    for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
           if(j==1) matrixA[i][j]=1;
           else if(i==0) matrixA[i][j]=1;
           else matrixA[i][j]=matrixA[i-1][j]+5;
        } 
    } 

    for (int i = 0; i < WIDTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) { 
           if(i==0) matrixB[i][j]=1;
           else matrixB[i][j]=j;
        } 
    } 

    pthread_t threads[MAX_THREAD];

    for (int i = 0; i < MAX_THREAD; i++){
        int *p;
        pthread_create(&threads[i],NULL, multiplicationMatrix, (void*)(p));
    }
    
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);  
    
    key_t key = 8799;
    int (*count)[10];
    int shmid = shmget (key, sizeof *count * 20, 
        IPC_CREAT | 0666);
    if (shmid < 1)
    {
        perror("exit");
        exit(0);
    }
    count = shmat(shmid, (void *)0, 0);
    printf("Hasil\n");
    for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) {
            count[i][j]=matrixC[i][j];
            printf("%d ",count[i][j]);
        }
        printf("\n");
    } 
    return 0;
}
```
#4b
```c
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>
#include<sys/types.h>
#include<sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define MAX_THREAD 20 

void* factorial(int fac){
    int hasil;
    if (fac%2==1)
    {
      hasil=(fac*((fac-1)/2))+(fac);
    } else hasil = (fac*(fac/2))+(fac/2);
    
    printf("%d ",hasil);
}
int main(){
  key_t key = 8799;
  int(*count)[10];
  int shmid = shmget(key, sizeof *count * 20, IPC_CREAT | 0666);
  if (shmid < 1)
  {
    perror("failed");
    exit(0);
  }
  count = shmat(shmid, (void *)0, 0);
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      printf("%d ",count[i][j]);
    }
    printf("\n");
  }
  pthread_t threads[MAX_THREAD];
  int k=0;
  for (int i = 0; i < 4; i++)
  {
    for (int j = 0; j < 5; j++)
    {
        int *p;
        pthread_create(&threads[k],NULL, factorial,(void *)count[i][j]);
        pthread_join(threads[i],NULL); 
        k++;
    }
    printf("\n");
  }

  return 0;
}
```
#4c
```c
#include <stdlib.h>
 #include <unistd.h>
 
 int pid;
 int pipe1[2];
 int pipe2[2];
 
 int main()
 {
   if (pipe(pipe1) == -1)
     exit(1);
 
   if ((fork()) == 0) 
   {
     
     // output to pipe1
     dup2(pipe1[1], 1);
     // close fds
     close(pipe1[0]);
     close(pipe1[1]);
     // exec
     char *argv1[] = {"ls", NULL};
         execv("/bin/ls", argv1);
   }
 
   if (pipe(pipe2) == -1) void* factorial(int fac){
    int hasil;
    if (fac%2==1)
    {
      hasil=(fac*((fac-1)/2))+(fac);
    } else hasil = (fac*(fac/2))+(fac/2);
    
    printf("%d ",hasil);
}
     exit(1);
 
   if (fork() == 0)
   {
     // input from pipe1
     dup2(pipe1[0], 0);
     // close fds
     close(pipe1[0]);
     close(pipe1[1]);
     // exec
     char *argv1[] = {"wc", "-l", NULL};
         execv("/usr/bin/wc", argv1);
   }
 }
```
**Penjelasan**
---
Pada 4a
```c
int main(){
    for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
           if(j==1) matrixA[i][j]=1;
           else if(i==0) matrixA[i][j]=1;
           else matrixA[i][j]=matrixA[i-1][j]+5;
        } 
    } 
```
Potongan kode tersebut digunakan untuk membuat matriks A sekaligus mendefinisikan isi dari matriks A.
```c
for (int i = 0; i < WIDTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) { 
           if(i==0) matrixB[i][j]=1;
           else matrixB[i][j]=j;
        } 
    } 
```
Potongan kode tersebut digunakan untuk membuat matriks B sekaligus mendefinisikan isi dari matriks B.
```c
for (int i = 0; i < MAX_THREAD; i++){
        int *p;
        pthread_create(&threads[i],NULL, multiplicationMatrix, (void*)(p));
    }
    
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);
```
Potongan kode ini digunakan untuk membuat thread dan juga untuk menjoinkan setiap threadnya. Thread ini berjumlah sebanyak 4 karena akan ada perkalian dengan menggunakan 4 baris Matriks A ke Matriks B.
```c
void* multiplicationMatrix(void* arg){
    int core = step_i++;
    for (int i = core; i < core+1; i++)
    {
        for (int j = 0; j < WIDTH_B; j++)  
            for (int k = 0; k < WIDTH; k++)  
                matrixC[i][j] += matrixA[i][k] * matrixB[k][j]; 
    }
    
}
```
Merupakan fungsi untuk perkalian matriks A dan matriks B kemudian valuenya akan disimpan kedalam matriks C
```c
 key_t key = 8799;
    int (*count)[10];
    int shmid = shmget (key, sizeof *count * 20, 
        IPC_CREAT | 0666);
    if (shmid < 1)
    {
        perror("exit");
        exit(0);
```
Membuat shared memory dengan menggunakan pointer bertipe array. Dikali 20 karena nantinya terdapat 20 data (matriks C 4 x 5) yang akan di shared.
```c
for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) {
            count[i][j]=matrixC[i][j];
            printf("%d ",count[i][j]);
        }
        printf("\n");
    }
```  
Potongan kode tersebut untuk mencetak hasil dari matriks yang sudah dikalikan sekaligus melakukan assignment hasil matriks C ke variable count yang akan digunakan untuk shared memory.

Pada 4b
```c
int main(){
  key_t key = 8799;
  int(*count)[10];
  int shmid = shmget(key, sizeof *count * 20, IPC_CREAT | 0666);
  if (shmid < 1)
  {
    perror("failed");
    exit(0);
  }
```
Membuat shared memory dengan menggunakan variable count yang memuat dua puluh data dari array sebelumnya.
```c
count = shmat(shmid, (void *)0, 0);
for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 5; j++)
    {
        printf("%d ",count[i][j]);
    }
    printf("\n");
}
```
Potongan kode berikut ini untuk mengambil data yang berjumlah dua puluh tadi yang telah ditaruh dalam shared memory ke dalam variable count. Variable ini nantinya akan berbentuk seperti array. Lalu akan ditambilkan layaknya matriks biasa.
```c
pthread_t threads[MAX_THREAD];
int k=0;
for (int i = 0; i < 4; i++)
{
    for (int j = 0; j < 5; j++)
    {
        int *p;
        pthread_create(&threads[k],NULL, factorial,(void *)count[i][j]);
        pthread_join(threads[i],NULL); 
        k++;
    }
    printf("\n");
}
```
Potongan kode berikut ini berguna untuk membuat thread sebanyak 20 kali dimana thread ini akan melakukan operasi pertambahan dari tiap-tiap data dengan rumus n+(n-1)+(n-2)+..+1.
```c
void* factorial(int fac){
    int hasil;
    if (fac%2==1)
    {
      hasil=(fac*((fac-1)/2))+(fac);
    } else hasil = (fac*(fac/2))+(fac/2);
    
    printf("%d ",hasil);
}
```
Potongan kode berikut ini untuk melakukan operasi pertambahan menggunakan rumus diatas, Disini terdapat cara cepatnya untuk melakukan perhitungan tersebut.

4c
```c
if (pipe(pipe1) == -1)
     exit(1);
 
   if ((fork()) == 0) 
   {
     
     // output to pipe1
     dup2(pipe1[1], 1);
     // close fds
     close(pipe1[0]);
     close(pipe1[1]);
     // exec
     char *argv1[] = {"ls", NULL};
         execv("/bin/ls", argv1);
   }
```
Berguna untuk membuat pipe pada pipe1 beserta fork dan menaruh hasil dari ls ke dalam pipe1[1].
```c
if (pipe(pipe2) == -1) 
     exit(1);
 
   if (fork() == 0)
   {
     // input from pipe1
     dup2(pipe1[0], 0);
     // close fds
     close(pipe1[0]);
     close(pipe1[1]);
     // exec
     char *argv1[] = {"wc", "-l", NULL};
         execv("/usr/bin/wc", argv1);
   }
```
Potongan kode diatas berguna untuk membuat pipe pada pipe2 sekaligus melakukan fork. Nantinya pipe1 yang sudah diisi dengan hasil dari ls akan menjadi input untuk melakukan perintah "wc -l".