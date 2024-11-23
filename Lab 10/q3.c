/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q3: Write a program that uses structures to manage flight information, including flight
number, departure city, destination city, date, and available seats. Create functionalities
to book a seat and display flight details.

*/

#include <stdio.h>
#include <string.h>

struct Flight {
    int flightNumber;
    char departureCity[50];
    char destinationCity[50];
    char date[20];
    int availableSeats;
};

void displayFlightDetails(struct Flight flight) {
    printf("\nFlight Details:\n");
    printf("Flight Number: %d\n", flight.flightNumber);
    printf("Departure City: %s\n", flight.departureCity);
    printf("Destination City: %s\n", flight.destinationCity);
    printf("Date: %s\n", flight.date);
    printf("Available Seats: %d\n", flight.availableSeats);
}

void bookSeat(struct Flight *flight) {
    if (flight->availableSeats > 0) {
        flight->availableSeats--; 
        printf("\nSeat booked successfully! Remaining seats: %d\n", flight->availableSeats);
    } else {
        printf("\nSorry! No seats available on this flight.\n");
    }
}

int main() {
    
    struct Flight flight1 = {10985, "Dammam", "Doha", "2024-12-22", 10};

    int choice;
    do {
        
        printf("\nMenu:\n");
        printf("1. Display Flight Details\n");
        printf("2. Book a Seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayFlightDetails(flight1); 
                break;
            case 2:
                bookSeat(&flight1); 
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Error! Try again!\n");
        }
    } while (choice != 3);

    return 0;
}
