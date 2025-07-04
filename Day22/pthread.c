#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

//normal C function that is executed as a thread 
// when its name is specified in pthread_create()

void *helloworld(void *vargp)
{
	sleep(1);
	printf("Hello World \n");
	return NULL;
}

int main(){
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, helloworld, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
	exit(0);
}