/* Name/Roll Number: Abeer Fatima/24K-0985
Q12: Create a program that calculates the final grade of a student based on multiple criteria,
including attendance, assignment scores, and exam results, using nested decision structures.
*/

#include <stdio.h>
int main() {
	
	float attendance;
	float assignmentScore;
	float examResult;
	float finalGrade;
	
	printf("take your attendance\n");
	scanf("%f", &attendance);
	
	printf("take your assignmentScore\n");
	scanf("%f", &assignmentScore);
	
	printf("take your examResult\n");
	scanf("%f", &examResult);
	
 
 if (attendance<70) { //total attendance is 100
 	printf("you're a failure\n");
 	}
 else if (assignmentScore<15) { //total assignmentScore is 35
    printf("you're a failure\n");
 }
 else if (examResult<60) { //total examResult is 100
 	printf("you're a failure\n");
 }
 else {
 	finalGrade = attendance*0.2 + (assignmentScore/35)*100*0.3 + examResult*0.5;
 }
 
 if (finalGrade>=90) {
 	printf("finalGrade is A\n");
 }
 else if (finalGrade>=80 && finalGrade<90) {
 	printf("finalGrade is B\n");
 }
 else if (finalGrade>=70 && finalGrade<80) {
 	printf("finalGrade is C\n");
 }
 else if (finalGrade>=60 && finalGrade<70) {
 	printf("finalGrade is D\n");
 }
 else if (finalGrade>=50 && finalGrade<60) {
 	printf("finalGrade is F\n");
 }
 
 return 0;
 
}
	
	
	