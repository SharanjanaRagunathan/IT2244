//Ternary operator
test_condition ? expression1 : expression2;

 

#include<stdio.h>
int main(){

int age;
printf("Enter your current age: ",age);
scanf("%d", &age);

(age>=18?printf("You're Eligible"):printf("You're Not Eligible\n"));

return 0;
}
