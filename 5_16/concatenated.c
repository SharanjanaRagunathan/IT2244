/*write a c program that:
Accpets an array of integer from the user.
concatenates the two strings displays the concatenated results*/

#include <stdio.h>
#include <string.h>
int main() {
 char str1[100], str2[100], result[200];
 printf("Enter first string: ");
 fgets(str1, sizeof(str1), stdin);
 printf("Enter second string: ");
 fgets(str2, sizeof(str2), stdin);
 str1[strcspn(str1, "\n")] = '\0';
 str2[strcspn(str2, "\n")] = '\0';
 strcpy(result, str1);
 strcat(result, str2);
 printf("Concatenated string: %s\n", result);
 return 0;
}