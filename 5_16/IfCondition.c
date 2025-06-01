//if else
	
if(condition){
	//body of if statement
}
else{
	//body of the else statement
}
#Exercise
//Enter your age and verify you are eligible or not for the election voting



 
#include<stdio.h>
int main(){

int age;
printf("Enter your current age: ",age);
scanf("%d", &age);

if(age>=18){
	printf("You're Eligible for the voting\n");
}
else if(age=0){
	printf("Invalid Input\n");
}
else{
	printf("You're Not Eligible for the voting\n");
}
return 0;
}
