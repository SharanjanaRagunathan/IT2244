Area calculation program
Circle => C
Triangle => T
Square => S
Rectangle => R
Enter Your choice :C

Circle area calculation 

Enter the radius:20.9
Area is:1371.58



#include <stdio.h>
#include <math.h>

int main() {
    char choice;
    double radius, area;
    double base, height;
    double side;
    double length, width;

    printf("Choose a shape for area calculation:\n");
    printf("C => Circle\nT => Triangle\nS => Square\nR => Rectangle\n");
    printf("Enter your choice: ");
    scanf(" %c", &choice);

    switch (choice) {
        case 'C':
        case 'c':
            printf("Enter the radius: ");
            scanf("%lf", &radius);
            area = M_PI * radius * radius;
            printf("Area of Circle: %.2f\n", area);
            break;
        case 'T':
        case 't':
            printf("Enter the base and height: ");
            scanf("%lf %lf", &base, &height);
            area = 0.5 * base * height;
            printf("Area of Triangle: %.2f\n", area);
            break;
        case 'S':
        case 's':
            printf("Enter the side length: ");
            scanf("%lf", &side);
            area = side * side;
            printf("Area of Square: %.2f\n", area);
            break;
        case 'R':
        case 'r':
            printf("Enter the length and width: ");
            scanf("%lf %lf", &length, &width);
            area = length * width;
            printf("Area of Rectangle: %.2f\n", area);
            break;
        default:
            printf("Invalid choice! Please enter C, T, S, or R.\n");
            break;
    }

    return 0;
}


---------------------------------------
use pipe

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefd[2]; // Pipe for communication
    pid_t pid;
    char choice;
    double values[2], area;

    // Create a pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) { // Parent process
        close(pipefd[0]); // Close reading end of pipe
        
        printf("Choose a shape for area calculation:\n");
        printf("C => Circle\nT => Triangle\nS => Square\nR => Rectangle\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);
        
        switch (choice) {
            case 'C':
            case 'c':
                printf("Enter the radius: ");
                scanf("%lf", &values[0]);
                break;
            case 'T':
            case 't':
                printf("Enter the base and height: ");
                scanf("%lf %lf", &values[0], &values[1]);
                break;
            case 'S':
            case 's':
                printf("Enter the side length: ");
                scanf("%lf", &values[0]);
                break;
            case 'R':
            case 'r':
                printf("Enter the length and width: ");
                scanf("%lf %lf", &values[0], &values[1]);
                break;
            default:
                printf("Invalid choice!\n");
                return 1;
        }

        // Send data to child
        write(pipefd[1], &choice, sizeof(choice));
        write(pipefd[1], values, sizeof(values));
        close(pipefd[1]); // Close writing end of pipe

        wait(NULL); // Wait for child to finish
    } else { // Child process
        close(pipefd[1]); // Close writing end of pipe

        // Read data from parent
        read(pipefd[0], &choice, sizeof(choice));
        read(pipefd[0], values, sizeof(values));

        switch (choice) {
            case 'C':
            case 'c':
                area = 3.141592653589793 * values[0] * values[0];
                break;
            case 'T':
            case 't':
                area = 0.5 * values[0] * values[1];
                break;
            case 'S':
            case 's':
                area = values[0] * values[0];
                break;
            case 'R':
            case 'r':
                area = values[0] * values[1];
                break;
        }

        printf("Area: %.2f\n", area);
        close(pipefd[0]); // Close reading end of pipe
    }

    return 0;
}



