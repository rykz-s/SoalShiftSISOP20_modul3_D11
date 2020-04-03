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
