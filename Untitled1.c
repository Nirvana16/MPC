#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define THREADS_MAX 4
void *function(void *param){
int id = (int)param;
int i, loops = 10;
for(i = 0; i < loops; i++) { printf("thread %d: loop %d\n", id, i); }
pthread_exit(NULL);
pthread_exit(NULL);
}
int main(void){
pthread_t threads[THREADS_MAX]; int i;
printf("pre-execution\n");
for (i = 0; i < THREADS_MAX; i++) { pthread_create(&threads[i], NULL, function, (void *)i); }
printf("mid-execution\n");
for (i = 0; i < THREADS_MAX; i++) {pthread_join(threads[i], NULL);}
printf("post-execution\n");
return EXIT_SUCCESS;
}
