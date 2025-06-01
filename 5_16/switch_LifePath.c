/*Q1)write a code for small astrology based on your life path number for that get the date of birth from user then calculate life path number.(use switch case)
calculation for life path number
a=date%10
b=date/10
c=a+b

::if life path number
      ::1-lucky
	  ::2-carefully do your work
	  ::3-stronger
	  ::4-happy
	  ::5-can get help
	  ::6-doubt
	  ::7-sad
	  ::8-like
	  ::9-courage*/

#include <stdio.h>

int calculate_life_path_number(int date) {
    int a = date % 10;  
    int b = date / 10;  
    int life_path = a + b;

    return life_path;
}

int main() {
    int date_of_birth, life_path;

    printf("Enter your birth date (DD): ");
    scanf("%d", &date_of_birth);

    if (date_of_birth < 1 || date_of_birth > 31) {
        printf("Invalid date entered. Please enter a valid date between 1 and 31.\n");
        return 1;
    }

    life_path = calculate_life_path_number(date_of_birth);

    switch (life_path) {
        case 1:
            printf("Life Path Number 1: Lucky\n");
            break;
        case 2:
            printf("Life Path Number 2: Carefully do your work\n");
            break;
        case 3:
            printf("Life Path Number 3: Stronger\n");
            break;
        case 4:
            printf("Life Path Number 4: Happy\n");
            break;
        case 5:
            printf("Life Path Number 5: Can get help\n");
            break;
        case 6:
            printf("Life Path Number 6: Doubt\n");
            break;
        case 7:
            printf("Life Path Number 7: Sad\n");
            break;
        case 8:
            printf("Life Path Number 8: Like\n");
            break;
        case 9:
            printf("Life Path Number 9: Courage\n");
            break;
        default:
            printf("Error in calculation.\n");
    }

    return 0;
}
