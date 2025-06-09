Exercise

1.get two input from user(//parent process)
name:
reg no:
age:

2.print the output from the child(//child process)

name:Sharanjana
reg no: 2022ict51
age:24

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    char name[50];
    char regno[20];
    int age;

    // Taking input in the parent process
    printf("Enter Name: ");
    scanf("%s", name);
    printf("Enter Reg No: ");
    scanf("%s", regno);
    printf("Enter Age: ");
    scanf("%d", &age);

    pid_t pid = fork();  // Creating the child process

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) { // Child process
        printf("\nChild Process Output:\n");
        printf("Name: %s\n", name);
        printf("Reg No: %s\n", regno);
        printf("Age: %d\n", age);
    }
    else { // Parent process
        wait(NULL); // Wait for child to finish
        printf("\nParent Process Completed!\n");
    }

    return 0;
}

