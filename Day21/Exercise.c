Exercise

1.get two input from user(//parent process)
name:
reg no:
age:

2.print the output from the child(//child process)

name:Sharanjana
reg no: 2022ict51
age:24


//use pipe


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipefd[2];
    pid_t pid;
    char buffer[100];

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close unused read end
        char name[50], reg_no[20];
        int age;

        printf("Enter Name: ");
        scanf("%s", name);
        printf("Enter Registration Number: ");
        scanf("%s", reg_no);
        printf("Enter Age: ");
        scanf("%d", &age);

        sprintf(buffer, "Name: %s\nRegistration Number: %s\nAge: %d\n", name, reg_no, age);
        write(pipefd[1], buffer, strlen(buffer) + 1);
        close(pipefd[1]); // Close write end
    } else { // Child process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], buffer, sizeof(buffer));
        printf("\nChild Process Output:\n%s", buffer);
        close(pipefd[0]); // Close read end
    }

    return 0;
}
