/* Name/Roll Number: Abeer Fatima (24K-0985)
q1: Write a program that contains a structure named Employee which contains the following
data members:
? employeeCode
? employeeName
? dateOfJoining
Perform the following operations:
1. Define a function that assigns user-defined values to these variables.
2. Create an array of 4 Employee structs and initialize them with user-defined values.
3. Define a function that asks the user to enter the current date, calculates the tenure of each
employee, and checks if the tenure is more than three years. Display the details of
employees with tenure of more than three years and the count of such employees.
*/

#include <stdio.h>
#include <string.h>

struct Employee {
    int employeeCode;
    char employeeName[50];
    int dateOfJoining[3];
      };

void assignEmployee(struct Employee *emp) {
    printf("Enter employee code: ");
    scanf("%d", &emp->employeeCode);
    getchar();
    printf("Enter employee name: ");
    fgets(emp->employeeName, sizeof(emp->employeeName), stdin);
    emp->employeeName[strcspn(emp->employeeName, "\n")] = '\0'; 
    printf("Enter date of joining (day month year): ");
    scanf("%d %d %d", &emp->dateOfJoining[0], &emp->dateOfJoining[1], &emp->dateOfJoining[2]);
}

void calculateAndDisplayTenure(struct Employee employees[], int size) {
    int currentDay, currentMonth, currentYear;
    printf("Enter current date (day month year): ");
    scanf("%d %d %d", &currentDay, &currentMonth, &currentYear);

    int count = 0;
    printf("\nEmployees with tenure of more than 3 years:\n");
    for (int i = 0; i < size; ++i) {
    	
        int yearDiff = currentYear - employees[i].dateOfJoining[2];
        int monthDiff = currentMonth - employees[i].dateOfJoining[1];
        int dayDiff = currentDay - employees[i].dateOfJoining[0];

        if (monthDiff < 0 || (monthDiff == 0 && dayDiff < 0)) {
            yearDiff--;
        }

        if (yearDiff > 3) {
            printf("\nEmployee Code: %d\n", employees[i].employeeCode);
            printf("Employee Name: %s\n", employees[i].employeeName);
            printf("Date of Joining: %02d/%02d/%04d\n",
                   employees[i].dateOfJoining[0],
                   employees[i].dateOfJoining[1],
                   employees[i].dateOfJoining[2]);
            printf("Tenure: %d years\n", yearDiff);
            count++;
        }
    }

    printf("Total number of employees with tenure more than 3 years: %d\n", count);
}

int main() {
    const int SIZE = 4;
    struct Employee employees[SIZE];

    for (int i=0; i < SIZE; ++i) {
        printf("Enter details for employee %d:\n", i + 1);
        assignEmployee(&employees[i]);
    }

    calculateAndDisplayTenure(employees, SIZE);
 return 0;
}
