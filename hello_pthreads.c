#include <stdio.h>       /* standard I/O routines                 */
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>     /* pthread functions and data structures */

/* function to be executed by the new thread */
void* PrintHello(void* data)
{
  int my_data = (int)data;     	/* data received by thread */

  /* sleep(1); */
  printf("Hello from new thread %lu - got %d\n", pthread_self(),my_data);
  /* pthread_exit(NULL); */			/* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
  int        rc;         	/* return value                           */
  pthread_t  thread_id;     	/* thread's ID (just an integer)          */
  int        tid,t=11;          /* data passed to the new thread          */

  /* create a new thread that will execute 'PrintHello' */
  tid=pthread_self();
  rc = pthread_create(&thread_id, NULL, PrintHello, (void*)tid);  
  if(rc)			/* could not create thread */
    {
      printf("\n ERROR: return code from pthread_create is %d \n", rc);
      exit(1);
    }
  sleep(1);
  printf("\n I am %u. Created new thread (%lu) ... \n", tid,thread_id);
    
  pthread_exit(NULL);		/* terminate the thread */
}
