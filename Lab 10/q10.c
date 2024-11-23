/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q10: Design a structure to store information about travel packages, including package name,
destination, duration, cost, and number of seats available. Write a program that allows
users to book a travel package and display available packages.

*/

#include <stdio.h>
#include <string.h>

struct TravelPackage {
    char packageName[100];
    char destination[100];
    int duration; 
    double cost;  
    int seatsAvailable; 
};

void displayPackages(struct TravelPackage packages[], int count) {
    if (count == 0) {
        printf("No packages available.\n");
        return;
    }
    
    printf("\nAvailable Travel Packages:\n");
    for (int i = 0; i < count; i++) {
        printf("Package Name: %s\n", packages[i].packageName);
        printf("Destination: %s\n", packages[i].destination);
        printf("Duration: %d days\n", packages[i].duration);
        printf("Cost: $%.2f\n", packages[i].cost);
        printf("Seats Available: %d\n\n", packages[i].seatsAvailable);
    }
}

void bookPackage(struct TravelPackage packages[], int count, int packageIndex) {
    if (packageIndex < 0 || packageIndex >= count) {
        printf("Invalid package selection.\n");
        return;
    }
    
    if (packages[packageIndex].seatsAvailable > 0) {
        packages[packageIndex].seatsAvailable--;
        printf("Booking successful! Remaining seats for %s: %d\n",
               packages[packageIndex].packageName, packages[packageIndex].seatsAvailable);
    } else {
        printf("Sorry, no seats available for this package.\n");
    }
}

int main() {
    struct TravelPackage packages[100]; 
    int count = 0;
    int choice, packageIndex;

    strcpy(packages[count].packageName, "Home");
    strcpy(packages[count].destination, "Jubail");
    packages[count].duration = 7;
    packages[count].cost = 1500.00;
    packages[count].seatsAvailable = 10;
    count++;

    strcpy(packages[count].packageName, "Concertsss");
    strcpy(packages[count].destination, "Seoul");
    packages[count].duration = 10;
    packages[count].cost = 2000.00;
    packages[count].seatsAvailable = 5;
    count++;

    strcpy(packages[count].packageName, "Animeeeee");
    strcpy(packages[count].destination, "Tokyo");
    packages[count].duration = 14;
    packages[count].cost = 2500.00;
    packages[count].seatsAvailable = 8;
    count++;

    while (1) {
        
        printf("\nTravel Package Menu:\n");
        printf("1. Display Available Packages\n");
        printf("2. Book a Travel Package\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:               
                displayPackages(packages, count);
                break;

            case 2:                
                displayPackages(packages, count);
                printf("Enter the package number to book (starting from 0): ");
                scanf("%d", &packageIndex);
                bookPackage(packages, count, packageIndex);
                break;

            case 3:
                printf("Exiting the program.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
