/* Name/Roll Number: Abeer Fatima (24K-0985)
q1: Create a program to calculate the average marks of a class of students using a structure.
The program should ask for the number of students and input their details dynamically.
*/

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    int rollNumber;
    float marks;
     };


int main() {
    int numStudents;
    float totalMarks = 0;

    printf("take the number of students: ");
    scanf("%d", &numStudents);

    
	struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    
	if (students==NULL) {
        printf("Error! Dynamic memory allocation has failed!\n");
        return 1;
    }

    for (int i=0; i<numStudents; ++i) {
        printf("Enter details for student %d:\n", i+1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name); 
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);
        printf("Marks: ");
        scanf("%f", &students[i].marks);

        totalMarks += students[i].marks;
    }

    float averageMarks = totalMarks / numStudents;
    printf("\nThe average marks of the class is: %.2f\n", averageMarks);

    free(students);

    return 0;
}
