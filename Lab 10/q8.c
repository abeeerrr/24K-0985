/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q8Create a structure to store details about cars in a dealership, including make, model,
year, price, and mileage. Write a program that allows users to add new cars, display a
list of available cars, and search for cars by make or model.

*/
#include <stdio.h>
#include <string.h>

struct Car {
    char make[50];
    char model[50];
    int year;
    double price;
    double mileage;
};

void addCar(struct Car *car) {
    printf("Enter car make: ");
    scanf("%s", car->make);
    
    printf("Enter car model: ");
    scanf("%s", car->model);
    
    printf("Enter car year: ");
    scanf("%d", &car->year);
    
    printf("Enter car price: ");
    scanf("%lf", &car->price);
    
    printf("Enter car mileage: ");
    scanf("%lf", &car->mileage);
}

void displayCars(struct Car cars[], int count) {
    if (count == 0) {
        printf("No cars available.\n");
        return;
    }
    
    printf("\nAvailable Cars:\n");
    for (int i = 0; i < count; i++) {
        printf("Car %d:\n", i + 1);
        printf("Make: %s\n", cars[i].make);
        printf("Model: %s\n", cars[i].model);
        printf("Year: %d\n", cars[i].year);
        printf("Price: %.2lf\n", cars[i].price);
        printf("Mileage: %.2lf\n\n", cars[i].mileage);
    }
}

void searchCars(struct Car cars[], int count, const char *searchTerm) {
    int found = 0;
    printf("\nSearch Results for '%s':\n", searchTerm);
    
    for (int i = 0; i < count; i++) {
        if (strstr(cars[i].make, searchTerm) != NULL || strstr(cars[i].model, searchTerm) != NULL) {
            printf("Car %d:\n", i + 1);
            printf("Make: %s\n", cars[i].make);
            printf("Model: %s\n", cars[i].model);
            printf("Year: %d\n", cars[i].year);
            printf("Price: %.2lf\n", cars[i].price);
            printf("Mileage: %.2lf\n\n", cars[i].mileage);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No cars found matching '%s'.\n", searchTerm);
    }
}

int main() {
    struct Car cars[100]; 
    int count = 0;  
    int choice;
    
    while (1) {
        printf("\nCar Dealership Menu:\n");
        printf("1. Add a new car\n");
        printf("2. Display available cars\n");
        printf("3. Search cars by make/model\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                
                if (count < 100) {
                    addCar(&cars[count]);
                    count++;
                } else {
                    printf("Car dealership is full. Cannot add more cars.\n");
                }
                break;
                
            case 2:
               
                displayCars(cars, count);
                break;
                
            case 3:
                
                {
                    char searchTerm[50];
                    printf("Enter make or model to search for: ");
                    scanf("%s", searchTerm);
                    searchCars(cars, count, searchTerm);
                }
                break;
                
            case 4:
            
                printf("Exiting the program.\n");
                return 0;
                
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}
