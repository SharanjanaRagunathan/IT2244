//writer process1

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024   // size of shared memory segment

int main(){
	key_t key = ftok("shmfile",51);  // Generate unique key
	int shmid = shmget(key,SHM_SIZE,IPC_CREAT | 0666); // create shared memory segment
	if(shmid == -1){
		perror("sgmget");
		exit(1);
	}
	char *shmaddr = (char*) shmat(shmid,NULL,0); // Attach to shared memory
	
	if(shmaddr == (char*) -1){
		perror("shmat");
		exit(1);
	}
	printf("Write Data: ");
	fgets(shmaddr, SHM_SIZE , stdin); // Write data to shared memory
	
	printf("Data written in memory: %s\n", shmaddr);
	shmdt(shmaddr); // detach from Shared memory
	
	return 0;
}

//Reader
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

#define Shared_size 1024

int main()
{
	key_t key = ftok("shmfile",51);
	int shmid=shmget(key, Shared_size, IPC_CREAT | 0666);
	if(shmid=-1)
	{
		perror("Segement");
		exit(1);
	}
	
	char* shmaddr = (char*) shmat(shmid, NULL, 0);
	if(shmaddr == (char*)-1)
	{
		perror("shmat");
		exit(1);
	}
	printf("data read from memory : $s\n",shmaddr);
	shmdt(shmaddr);
	shmctl(shmid,IPC_RMID,NULL);
}

// To run the file

//  vi writer.c
//  touch shmfile
//  chmod 644 shmfile
//  gcc writer.c -o writer
//  ./writer

//  vi Reader.c
//  gcc Reader.c -o Reader
//  ./Reader
