/* Name/Roll Number: Abeer Fatima, 24K-0985
Q4: Create a program that checks if a person is eligible to vote based on their age and citizenship
status.
*/

#include <stdio.h>
int main () {
int age;
char citizenship;

printf("enter your age\n");
scanf("%d",&age);
printf("do you have citizenship? (y/n): \n");
scanf(" %c",&citizenship);

if(age<0){
printf("invalid age entered\n");
}
if(citizenship!='y' && citizenship!='n'){
printf("error! input either y or n\n");

return 0;
}

if(age>=18 && citizenship=='y'){
printf("you are eligible to vote\n");
}
else{
printf("you are not eligible to vote\n");
}

return 0;
}