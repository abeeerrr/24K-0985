/* Name/Roll Number: Abeer Fatima/24K-0985
Q14: Develop a program that uses logical operators to determine if a person is eligible for a loan
based on age, income, and credit score.
*/

#include <stdio.h>
int main() {
	
	int age;
	int creditScore;
    float income;
    
    printf("take your age\n");
    scanf("%d",&age);
    
    printf("take your creditScore\n");
    scanf("%d",&creditScore);
    
    printf("take your income\n");
    scanf("%f",&income);
    
    if (age >= 18 && income >= 50000 && creditScore >= 500) {
        printf("You are eligible for a loan.\n");
    }
    else{
    	printf("you are not eligible for a loan.\n");
	}
	
	return 0;
    
}
