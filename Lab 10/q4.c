/*
Name/Roll Number: Abeer Fatima (24K-0985)

Q4: Write a program that use a structure to hold information about movies, such as title,
genre, director, release year, and rating. Write a program that allows users to add new
movies, search for movies by genre, and display all movie details.

*/
#include <stdio.h>
#include <string.h>

struct Movie {
    char title[100];
    char genre[50];
    char director[100];
    int releaseYear;
    float rating;
};

void addMovie(struct Movie movies[], int *count);
void searchByGenre(struct Movie movies[], int count, char genre[]);
void displayAllMovies(struct Movie movies[], int count);

int main() {
    struct Movie movies[100]; 
    int count = 0;           
    int choice;

    do {
       
        printf("\nMenu:\n");
        printf("1. Add New Movie\n");
        printf("2. Search Movies by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addMovie(movies, &count); 
                break;
            case 2: {
                char genre[50];
                printf("Enter genre to search: ");
                scanf(" %[^\n]", genre); 
                searchByGenre(movies, count, genre); 
                break;
            }
            case 3:
                displayAllMovies(movies, count); 
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Error! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}


void addMovie(struct Movie movies[], int *count) {
    if (*count >= 100) {
        printf("Cannot add more movies. The list is full.\n");
        return;
    }

    printf("Enter movie title: ");
    scanf(" %[^\n]", movies[*count].title); 
    printf("Enter movie genre: ");
    scanf(" %[^\n]", movies[*count].genre);
    printf("Enter movie director: ");
    scanf(" %[^\n]", movies[*count].director);
    printf("Enter release year: ");
    scanf("%d", &movies[*count].releaseYear);
    printf("Enter movie rating (0.0 to 10.0): ");
    scanf("%f", &movies[*count].rating);

    (*count)++; 
    printf("Movie added successfully!\n");
}

void searchByGenre(struct Movie movies[], int count, char genre[]) {
    int found = 0;
    printf("\nMovies in genre \"%s\":\n", genre);
    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, genre) == 0) {
            printf("Title: %s, Director: %s, Release Year: %d, Rating: %.1f\n",
                   movies[i].title, movies[i].director, movies[i].releaseYear, movies[i].rating);
            found = 1;
        }
    }
    if (!found) {
        printf("No movies found in this genre.\n");
    }
}

void displayAllMovies(struct Movie movies[], int count) {
    if (count == 0) {
        printf("No movies to display.\n");
        return;
    }

    printf("\nAll Movies:\n");
    for (int i = 0; i < count; i++) {
        printf("Title: %s, Genre: %s, Director: %s, Release Year: %d, Rating: %.1f\n",
               movies[i].title, movies[i].genre, movies[i].director, movies[i].releaseYear, movies[i].rating);
    }
}
