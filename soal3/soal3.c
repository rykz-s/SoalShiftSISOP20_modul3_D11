#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h> 
#include<sys/types.h>
#include<sys/wait.h>
#include<dirent.h>
#define MAX 256

pthread_t tid[MAX];
char cwd[MAX];

void* playandcount(void *arg){ //ini dah hampir bisa harusnya tp knp mkdirnya+file yg dipindah ga sesuai argumen yg kita pingin
    FILE *fp1, *fp2;
   // printf("cur directory : %s\n", cwd); 
    char* ext;
    char* fullname = arg;
    //printf("testing %s\n", fullname);
    ext = strchr(fullname,'.') + 1;
//line 23 salah penempatan jadinya kayak fungsi \*
    mkdir(ext, 0777);
    mkdir("Unknown", 0777);
    struct dirent *de;
    DIR *dr = opendir(cwd);
    char source[MAX], dest[MAX];
    while ((de = readdir(dr))){
        if(!(strcmp(de->d_name, ".")) || !(strcmp(de->d_name, "..")))
            continue;
        char* fullname = de->d_name;
        char* ext;
        ext = strchr(fullname, '.'); 
        if(ext != NULL){
            printf("\ninilho yg dimaksud : %s\n", ext);
            strcpy(source, cwd);
            strcat(source, "/");
            strcpy(dest, source);
            strcat(dest, (ext+1));
            strcat(dest, "/");
            strcat(dest, fullname);
            printf("Dest : %s\n", dest);
            strcat(source,fullname);
            printf("Source :  %s\n", source);
            fp1 = fopen(source, "r");
            fp2 = fopen(dest, "w");
              if (!fp1) {
                printf("Unable to open source file to read!!\n");
                fclose(fp2);
                return 0;
        }
            if (!fp2) {
                printf("Unable to open target file to write\n");
                return 0;
        }
            int ch;
            while ((ch = fgetc(fp1)) != EOF) {
                        fputc(ch, fp2);
                }
                /* closing the opened files */
                fclose(fp1);
                fclose(fp2);
                /* removing the source file */
                remove(source);
            }
            /*else{ niatnya masu masukin file yg gapunya ekstensi
                strcpy(source, cwd);
            strcat(source, "/");
            strcpy(dest, source);
            strcat(dest, (ext+1));
            strcat(dest, "/");
            strcat(dest, fullname);
            printf("Dest  else: %s\n", dest);
            strcat(source,fullname);
            printf("Source else:  %s\n", source);
            fp1 = fopen(source, "r");
            fp2 = fopen(dest, "w");
              if (!fp1) {
                printf("Unable to open source file to read!!\n");
                fclose(fp2);
                return 0;
        }
            if (!fp2) {
                printf("Unable to open target file to write\n");
                return 0;
        }
            int ch;
            while ((ch = fgetc(fp1)) != EOF) {
                        fputc(ch, fp2);
                }
                //closing the opened files 
                fclose(fp1);
                fclose(fp2);
                //removing the source file 
                remove(source);
            }*/
        }
    return NULL;
    }

int main(int argc, char** argv) {
    getcwd(cwd,sizeof(cwd));
    int i = 0; 
    int test;   
    if(strcmp(argv[1], "-f") == 0){
        for(test = 2; test < argc; test++){
            pthread_create(&(tid[i]),NULL,playandcount,argv[test]);
            pthread_join(tid[i],NULL);
            i++;
        }
    }
}
