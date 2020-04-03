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
