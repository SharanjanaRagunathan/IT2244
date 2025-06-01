
//system calls-1 

#include<stdio.h>
#include<unistd.h>
int main()
{
	printf("\nHello world");
	int f=fork();
	int p=getpid();
	printf("\n the pid is %d",p);
	printf("\n the fork is %d",f);
	
	return 0;
}

---------------------------------------------------------------------------------------------
/*fork()*/



#include<stdio.h>
#include<unistd.h>
int main()
{
	fork();
	fork();
	printf("\nHello world\n");
	return 0;
}

//output

Hello world

Hello world

Hello world
Hello world

---------------------------------------------------------------------------------------------
//print only 1 for each parent and child



#include<stdio.h>
#include<unistd.h>
int main()
{
    int f = fork();

    if (f == 0) {
        printf("\nI am the child process\n");
    } else {
        printf("\nI am the parent process");
    }
    return 0;
}

//outputs
I am the parent process
I am the child process

---------------------------------------------------------------------------------------------
//print one parent process and two child processes for the parent process


#include<stdio.h>
#include<unistd.h>

int main() {

    printf("\nA (Parent process)\n");
        printf("I'm A my ID is %d\n",getpid());
        printf("I'm A my parent ID is %d\n",getppid());
		
    int f1 = fork();
    if (f1 == 0) {
        printf("B (Child of A)\n");
                printf("I'm B my parent ID is %d\n",getppid());
    } else {
        int f2 = fork();
        if (f2 == 0) {
            printf("C (Child of A)\n");
                        printf("I'm C my parent ID is %d\n",getppid());
        }
    }
    return 0;
}

//outputs
A (Parent process)
I'm A my ID is 24467
I'm A my parent ID is 2151
B (Child of A)
I'm B my parent ID is 24467
C (Child of A)
I'm C my parent ID is 24467


