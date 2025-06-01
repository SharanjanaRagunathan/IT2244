//FORK
 
#include<stdio.h>
#include<unistd.h>
int main()
{
    fork();
	printf("Hello World\n");	
	return 0;
}

--------------------------------------------------------------------------------------
//parent child
 
#include<stdio.h>
#include<unistd.h>
int main()
{
    int id=fork();
	if(id==0)
	{
	   printf("I am child\n");
	}	
	else{
		printf("I am parent\n");
	}
	return 0;
}
--------------------------------------------------------------------------------------
//print numbers from 1 to 10 and
//1 to 5 should print by child process and
//from 6 to 10 should be parent process
//calculate sum of those numbers
 

#include <stdio.h>
#include <unistd.h>

int main() {
    int id = fork();
    int Csum = 0;
    int Psum = 0;
	
    if (id == 0) 
	{
        printf("Child process:\n");
        for (int i = 1; i <= 5; i++) 
		{
            printf("%d\n", i);
            Csum += i;
        }
        printf("Child sum: %d\n", Csum);
    } 
	 
        printf("Parent process:\n");
        for (int i = 6; i <= 10; i++) 
		{
            printf("%d\n", i);
            Psum += i;
        }
        printf("Parent sum: %d\n", Psum);
		
	printf("Total sum (Child + Parent): %d\n", Psum+Csum);
    return 0;
}
--------------------------------------------------------------------------------------
