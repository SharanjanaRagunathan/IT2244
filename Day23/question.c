Q1).Write a C program that creates two threads. Each thread should print 
a message indicating it is running. The main thread should wait for both 
threads to finish before exiting.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* threadFunc(void* arg) {
    int threadNum = *(int*)arg;
    printf("Thread %d is running\n", threadNum);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];
    int threadArgs[2] = {1, 2};

    // Create two threads
    for (int i = 0; i < 2; i++) {
        if (pthread_create(&threads[i], NULL, threadFunc, &threadArgs[i]) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    // Wait for both threads to complete
    for (int i = 0; i < 2; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Both threads have finished. Main thread exiting.\n");

    return EXIT_SUCCESS;
}

-----------------------------------------------------------------------

Q2).Write a program to create 5 threads. Each thread should print its thread
ID and then exit. The main thread should join all threads and print a 
completion message.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* threadFunc(void* arg) {
    long tid = (long)arg;
    printf("Thread %ld is running\n", tid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threads[5];

    // Create 5 threads
    for (long i = 0; i < 5; i++) {
        if (pthread_create(&threads[i], NULL, threadFunc, (void*)i) != 0) {
            perror("Failed to create thread");
            return EXIT_FAILURE;
        }
    }

    // Join all threads
    for (int i = 0; i < 5; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads have finished. Main thread exiting.\n");

    return EXIT_SUCCESS;
}

----------------------------------------------------------------------------------


Q3).Write a program that creates a thread which prints numbers from 1 to 10 
with a 1-second delay between each number.The main thread should wait for 
this thread to finish.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> // For sleep()

void* printNumbers(void* arg) {
    for (int i = 1; i <= 10; i++) {
        printf("%d\n", i);
        sleep(1);  // Delay for 1 second
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;

    // Create the thread
    if (pthread_create(&thread, NULL, printNumbers, NULL) != 0) {
        perror("Failed to create thread");
        return EXIT_FAILURE;
    }

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    printf("Counting completed. Main thread exiting.\n");

    return EXIT_SUCCESS;
}

---------------------------------------------------------------------------------


Q4).Create two threads where one thread increments a global counter 100 times
and the other thread decrements the same counter 100 times. 
Print the final value of the counter after both threads finish.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;               // Global counter
pthread_mutex_t lock;          // Mutex for synchronization

void* increment(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

void* decrement(void* arg) {
    for (int i = 0; i < 100; i++) {
        pthread_mutex_lock(&lock);
        counter--;
        pthread_mutex_unlock(&lock);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t t1, t2;

    // Initialize mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        perror("Mutex init failed");
        return EXIT_FAILURE;
    }

    // Create threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    // Wait for both threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy mutex
    pthread_mutex_destroy(&lock);

    printf("Final value of counter: %d\n", counter);
    return EXIT_SUCCESS;
}

------------------------------------------------------------------------

Q5)Implement a thread function that takes an integer argument, squares it,
and returns the result to the main thread using pthread_exit and pthread_join.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function that computes the square of the input integer
void* square(void* arg) {
    int num = *(int*)arg;
    int* result = malloc(sizeof(int)); // Allocate memory for result
    if (result == NULL) {
        perror("Failed to allocate memory");
        pthread_exit(NULL);
    }
    *result = num * num;
    pthread_exit(result); // Return result to main thread
}

int main() {
    pthread_t thread;
    int input = 7;  // Example input
    int* result;

    // Create the thread
    if (pthread_create(&thread, NULL, square, &input) != 0) {
        perror("Thread creation failed");
        return EXIT_FAILURE;
    }

    // Wait for the thread and retrieve the result
    if (pthread_join(thread, (void**)&result) != 0) {
        perror("Thread join failed");
        return EXIT_FAILURE;
    }

    printf("Square of %d is %d\n", input, *result);

    free(result); // Free the allocated memory
    return EXIT_SUCCESS;
}


