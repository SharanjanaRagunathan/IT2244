exercise
IPC using Message Queue
read inputs from the parent process
Enter Name:hi
Enter RegNo:2314
Enter Age:24

Message send successfully

give the output from the child process

Received Name:hi
Received RegNo:2314
Received Age:24



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_buffer {
    long msg_type;
    char name[50];
    int reg_no;
    int age;
};

int main() {
    key_t key = ftok("progfile", 65);  // Generate unique key
    int msgid = msgget(key, 0666 | IPC_CREAT);  // Create message queue

    pid_t pid = fork();  // Create child process

    if (pid > 0) {  // Parent process
        struct msg_buffer message;
        message.msg_type = 1;

        // Get input from user
        printf("Enter Name: ");
        scanf("%s", message.name);
        printf("Enter RegNo: ");
        scanf("%d", &message.reg_no);
        printf("Enter Age: ");
        scanf("%d", &message.age);

        // Send message from Parent
        msgsnd(msgid, &message, sizeof(message) - sizeof(long), 0);
        printf("Message sent successfully from Parent!\n");

    } else if (pid == 0) {  // Child process
        struct msg_buffer message;

        // Receive message in Child
        msgrcv(msgid, &message, sizeof(message) - sizeof(long), 1, 0);
        printf("\nReceived from Parent:\n");
        printf("Name: %s\n", message.name);
        printf("RegNo: %d\n", message.reg_no);
        printf("Age: %d\n", message.age);

        // Remove message queue after reading
        msgctl(msgid, IPC_RMID, NULL);
    } else {
        printf("Fork failed!\n");
    }

    return 0;
}
