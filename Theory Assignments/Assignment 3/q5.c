/* Name/Roll Number: Abeer Fatima (24K-0985)
q5: You're building an inventory system for a pet shop called "Pets in Heart" that keeps track of
different species of animals and their specific supplies (e.g., food, toys, bedding). The shop
inventory system uses a 2D dynamic array char** speciesSupplies where:
? Rows are explicitly set for each species (e.g., "Dogs," "Cats," "Parrots"), and each row
corresponds to a different species.
? Columns are dynamically allocated for each species to hold their specific supplies (e.g.,
"Food," "Leash," "Toys").
Task:
Write a C program that:
1. Initialize the Inventory: Allocate memory for a specified number of species, with each
species having its own list of supplies (initially empty).
2. Add Supplies: For each species, dynamically allocate memory for a list of supplies and allow
the user to add supplies for that species.
3. Update Supplies: Let users update the name of a supply item for a specific species.
4. Remove Species: Allow users to delete a species and free the associated memory (both for
the species and its supplies).
5. Display Inventory: Show the current supplies for each species in the inventory.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUPPLY_NAME 50

void initializeInventory(char ***speciesSupplies, int *numSpecies);
void addSupplies(char **speciesSupplies, int *numSupplies);
void updateSupply(char **speciesSupplies, int numSupplies);
void removeSpecies(char ***speciesSupplies, int *numSpecies, int speciesIndex);
void displayInventory(char **speciesSupplies, int numSupplies);
void freeInventory(char ***speciesSupplies, int numSpecies);

int main() {
    char ***speciesSupplies = NULL; 
    int numSpecies = 0; 

    while (1) {
        int choice;
        printf("\n=== Pets in Heart Inventory System ===\n");
        printf("1. Initialize Inventory\n");
        printf("2. Add Supplies\n");
        printf("3. Update Supplies\n");
        printf("4. Remove Species\n");
        printf("5. Display Inventory\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeInventory(&speciesSupplies, &numSpecies);
                break;
            case 2: {
                int speciesIndex;
                printf("take species index to add supplies (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    addSupplies(speciesSupplies[speciesIndex], &speciesSupplies[speciesIndex][0]);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 3: {
                int speciesIndex;
                printf("take species index to update supplies (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    updateSupply(speciesSupplies[speciesIndex], &speciesSupplies[speciesIndex][0]);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 4: {
                int speciesIndex;
                printf("take species index to remove (0 to %d): ", numSpecies - 1);
                scanf("%d", &speciesIndex);
                if (speciesIndex >= 0 && speciesIndex < numSpecies) {
                    removeSpecies(&speciesSupplies, &numSpecies, speciesIndex);
                } else {
                    printf("Invalid species index!\n");
                }
                break;
            }
            case 5:
                for (int i = 0; i < numSpecies; i++) {
                    printf("\nSpecies %d:\n", i);
                    displayInventory(speciesSupplies[i], &speciesSupplies[i][0]);
                }
                break;
            case 6:
                freeInventory(&speciesSupplies, numSpecies);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

void initializeInventory(char ***speciesSupplies, int *numSpecies) {
    printf("Enter the number of species: ");
    scanf("%d", numSpecies);

    *speciesSupplies = (char **)malloc(*numSpecies * sizeof(char *));
    for (int i = 0; i < *numSpecies; i++) {
        (*speciesSupplies)[i] = NULL; 
    }

    printf("Inventory initialized for %d species.\n", *numSpecies);
}

void addSupplies(char **speciesSupplies, int *numSupplies) {
    int count;
    printf("Enter the number of supplies to add: ");
    scanf("%d", &count);

    speciesSupplies = (char **)realloc(speciesSupplies, (*numSupplies + count) * sizeof(char *));
    for (int i = 0; i < count; i++) {
        speciesSupplies[*numSupplies + i] = (char *)malloc(MAX_SUPPLY_NAME * sizeof(char));
        printf("enter the name of supply %d: ", i + 1);
        scanf("%s", speciesSupplies[*numSupplies + i]);
    }
    *numSupplies += count;

    printf("Supplies added successfully.\n");
}

void updateSupply(char **speciesSupplies, int numSupplies) {
    int index;
    printf("Enter supply index to update (0 to %d): ", numSupplies - 1);
    scanf("%d", &index);

    if (index >= 0 && index < numSupplies) {
        printf("Enter new name for supply %d: ", index + 1);
        scanf("%s", speciesSupplies[index]);
        printf("Supply updated successfully.\n");
    } else {
        printf("Invalid supply index!\n");
    }
}

void removeSpecies(char ***speciesSupplies, int *numSpecies, int speciesIndex) {
 
    char **supplies = (*speciesSupplies)[speciesIndex];
    int i = 0;
    while (supplies[i] != NULL) {
        free(supplies[i]);
        i++;
    }
    free(supplies);

    for (int i = speciesIndex; i < *numSpecies - 1; i++) {
        (*speciesSupplies)[i] = (*speciesSupplies)[i + 1];
    }

    *numSpecies -= 1;
    *speciesSupplies = (char **)realloc(*speciesSupplies, *numSpecies * sizeof(char *));

    printf("Species removed successfully.\n");
}

void displayInventory(char **speciesSupplies, int numSupplies) {
    for (int i = 0; i < numSupplies; i++) {
        printf("  %d: %s\n", i + 1, speciesSupplies[i]);
    }
}

void freeInventory(char ***speciesSupplies, int numSpecies) {
    for (int i = 0; i < numSpecies; i++) {
        char **supplies = (*speciesSupplies)[i];
        int j = 0;
        while (supplies[j] != NULL) {
            free(supplies[j]);
            j++;
        }
        free(supplies);
    }
    free(*speciesSupplies);
}
