#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define BUFFER_SIZE 100

pthread_mutex_t mutex;
sem_t p,c;

void *producer()
{
	int value;
   while(1) {
       sem_wait(&p);
       pthread_mutex_lock(&mutex);
       sem_getvalue(&p, &value);
       usleep(1e5);
       printf("producing %dth buffer\n",BUFFER_SIZE-value);
       pthread_mutex_unlock(&mutex);
       sem_post(&c);
   }
}

void *consumer()
{
		int value;
      while(1) {
       sem_wait(&c);
       pthread_mutex_lock(&mutex);
       sem_getvalue(&c, &value);
       usleep(1e5);
       printf("consuming %dth buffer\n",value);
       pthread_mutex_unlock(&mutex);
       sem_post(&p);
   }
}

int main()
{
	sem_init(&p,0, BUFFER_SIZE);
	sem_init(&c,0, 0);
	pthread_mutex_init(&mutex, NULL);
	pthread_t producer_thread,consumer_thread;
	pthread_create(&consumer_thread,NULL,consumer,NULL);
	pthread_create(&producer_thread,NULL,producer,NULL);
	pthread_join(producer_thread,NULL);
	pthread_join(consumer_thread,NULL);
	pthread_mutex_destroy(&mutex);
    sem_destroy(&p);
    sem_destroy(&c);
	return 0;
}