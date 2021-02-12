#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUMBER_OF_THREADS 10

void *print_hello_world(void *tid)
{
  /*输出线程的标识符，，然后退出*/
  printf("Hello World.Greetings from thread %d\n",tid);
  pthread_exit(NULL);
}

int main(int argc,char *argv[])
{
  /*主程序创建10个线程，然后退出*/
  pthread_t threads[NUMBER_OF_THREADS];
  int status,i;
  void *tret;
  for(i=0;i<NUMBER_OF_THREADS;i++)
  {
    printf("Main here.Creating thread %d\n",i);
    status=pthread_create(&threads[i],NULL,print_hello_world,(void *)i);

    if(status !=0)
    {
      printf("Opos.pthread_create returned error code %d\n",status);
      exit(-1);
    }
    /*以下为增加的部分*/
    status=pthread_join(threads[i],&tret);
    if(status!=0)
    {
      printf("Pthread_join error %d\n",status);
      exit(-1);
    }
  }
}
