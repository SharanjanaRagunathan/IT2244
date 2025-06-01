//Give list of numbers then calculate the sum and multiplication on using for loop

 

#include <stdio.h>
int main() {
    int n, sum = 0, product = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
        product *= numbers[i];
    }
    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);

    return 0;
}
