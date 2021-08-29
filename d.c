#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define UNUSED(x) (void)(x)

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
static unsigned n_ready = 0;

static unsigned n; //this will become ptr and rad from main

static unsigned *fibs = NULL;

static void *back_worker(void *unused) {
	UNUSED(unused);

	fibs[0] = 0;
	fibs[1] = 1;

	pthread_mutex_lock(&mutex);
	n_ready = 2;
	pthread_cond_signal(&cond);
	pthread_mutex_unlock(&mutex);

	for(unsigned int i =2; i < n; ++i){
		fibs[i] = fibs[i-2] + fibs[i-1];

		pthread_mutex_lock(&mutex);
		n_ready = i + 1;
		pthread_cond_signal(&cond);
      	pthread_mutex_unlock(&mutex);
	}
	return NULL;
}

static void *front_worker(void *unused) {
	UNUSED(unused);

	for(unsigned i = 0 ; i < n ; ++i){
		pthread_mutex_lock(&mutex);
      	while (i >= n_ready)
        	pthread_cond_wait(&cond, &mutex);
	pthread_mutex_unlock(&mutex);
	printf("%u\n",fibs[i]);
	}
	return NULL;
}

int main(){
	//read n;
	//
	fibs = malloc(sizeof(unsigned) *n);

	pthread_t back_thread;
	if(errno = pthread_create(&back_thread,NULL,front_worker,NULL)){
		perror(NULL);
		exit(1);
	}
	pthread_t front_thread;
   	if (errno = pthread_create(&front_thread, NULL, front_worker, NULL)) {
      perror(NULL);
      exit(1);
   }

	pthread_join(back_thread,NULL);
	pthread_join(front_thread,NULL);

	pthread_cond_destroy(&cond);
   	pthread_mutex_destroy(&mutex);
	free(fibs);
	fibs = NULL;
	
	return 0;
}
