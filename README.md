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
```
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
```
```
---
**Soal 3:**
---
Buatlah sebuah program dari C untuk mengkategorikan file. Program ini akan
memindahkan file sesuai ekstensinya (tidak case sensitive. JPG dan jpg adalah
sama) ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working
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
```
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

void* playandcount(void *arg){ //ini dah hampir bisa harusnya tp knp mkdirnya+file yg dipindah ga sesuai argumen yg kita pingin

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
```
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
Cek apakah argumen yang diberikan adalah -f jika true maka lanjut dimana user bisa menambahkan argumen file yang ingin dikategorikan.
```
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
Pada fungsi playandcount terdapat cara untuk membuat folder sesuai ekstensi file yang ada dan juga folder unknown untuk file tanpa ekstensi. 

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
```
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
```
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
```
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
 }
 ```
 **Penjelasan**
 ---
Pada 4a
```
int main(){
    for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH; j++) { 
           if(j==1) matrixA[i][j]=1;
           else if(i==0) matrixA[i][j]=1;
           else matrixA[i][j]=matrixA[i-1][j]+5;
        } 
    } 
```
Potongan kode tersebut digunakan untuk membuat matriks A
```
for (int i = 0; i < WIDTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) { 
           if(i==0) matrixB[i][j]=1;
           else matrixB[i][j]=j;
        } 
    } 
```
Potongan kode tersebut digunakan untuk membuat matriks B
```
for (int i = 0; i < MAX_THREAD; i++){
        int *p;
        pthread_create(&threads[i],NULL, multiplicationMatrix, (void*)(p));
    }
    
    for (int i = 0; i < MAX_THREAD; i++)  
        pthread_join(threads[i], NULL);
```
Potongan kode ini digunakan untuk membuat thread dan juga untuk menjoinkan setiap threadnya
```
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
```
 key_t key = 8799;
    int (*count)[10];
    int shmid = shmget (key, sizeof *count * 20, 
        IPC_CREAT | 0666);
    if (shmid < 1)
    {
        perror("exit");
        exit(0);
```
Membuat shared memory
```
for (int i = 0; i < LENGTH; i++) { 
        for (int j = 0; j < WIDTH_B; j++) {
            count[i][j]=matrixC[i][j];
            printf("%d ",count[i][j]);
        }
        printf("\n");
    }
```  
Potongan kode tersebut untuk mencetak hasil dari matriks yang sudah dikalikan.

Pada 4b
```
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
Membuat shared memory
```
