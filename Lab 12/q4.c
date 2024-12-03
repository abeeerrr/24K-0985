/* Name/Roll Number: Abeer Fatima (24K-0985)
q4: Create a nested structure for a library management system. Use a structure Book (fields:
title, author, publicationYear) inside a structure Library. Input details of 5
books and display the titles of all books published after the year 2000. The structure
variable must be created using DMA. [self learning]
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    int publicationYear;
  };

   struct Library {
    struct Book* books;
    int bookCount;
    };

int main() {
    int i;
    struct Library* library = (struct Library*)malloc(sizeof(struct Library));
    if (library==NULL) {
        printf("Error! Dynamic memory allocation for library has failed!\n");
        return 1;
    }

    library->bookCount = 5;

    library->books = (struct Book*)malloc(library->bookCount*sizeof(struct Book));
    if (library->books==NULL) {
        printf("Error! Dynamic memory allocation for books has failed!\n");
        free(library);
        return 1;
    }

    printf("take the details of %d books: \n", library->bookCount);
    for (i=0; i<library->bookCount; i++) {
        printf("Book %d: \n", i + 1);
        printf("Title: ");
        scanf(" %[^\n]", library->books[i].title); 
        printf("Author: ");
        scanf(" %[^\n]", library->books[i].author);
        printf("Publication Year: ");
        scanf("%d", &library->books[i].publicationYear);
    }

    printf("Books published after the year 2000:\n");
    int found=0;
    for (i=0; i<library->bookCount; i++) {
        if (library->books[i].publicationYear>2000) {
            printf("%s\n", library->books[i].title);
            found = 1;
        }
    }

    if (!found) {
        printf("No books were published after the year 2000.\n");
    }

    free(library->books);
    free(library);

    return 0;
}
