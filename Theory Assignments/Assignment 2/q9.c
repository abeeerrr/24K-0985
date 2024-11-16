/*Name/Roll Number: Abeer Fatima (24K-0985)

Q9: Write a C program to simulate a simple grid-based adventure game using a 2D array.
Game Description:
• The game consists of a 5x5 grid.
• Each cell can contain:
o An empty space (' ').
o An item ('I') that the player can collect.
o An obstacle ('X') that the player cannot pass through.
o The player's position, represented by 'P'.

Example Input:
char grid[5][5] = {
{' ', ' ', 'I', 'X', ' '},
{' ', 'X', ' ', ' ', ' '},
{'I', ' ', 'X', 'X', ' '},
{' ', ' ', ' ', 'I', 'X'},
{' ', 'X', ' ', ' ', 'P'}
};
Requirements:
1. Display the grid and prompt the player for a move (W: up, S: down, A: left, D: right, Q: quit).
2. Update the player's position based on valid moves.
3. Collect items when the player moves to a cell containing an item (remove item from grid).
4. Prevent movement into obstacles ('X').
5. Continue until the player chooses to quit.
6. The grid is fixed at 5x5.
7. Only valid moves are allowed.
8. Handle invalid input gracefully.
*/

#include <stdio.h>
#define SIZE 5


void displayGrid(char grid[SIZE][SIZE]) {
    printf("\nGrid:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

void findPlayer(char grid[SIZE][SIZE], int *playerRow, int *playerCol) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 'P') {
                *playerRow = i;
                *playerCol = j;
                return;
            }
        }
    }
}

int movePlayer(char grid[SIZE][SIZE], char move, int *playerRow, int *playerCol, int *itemsCollected) {
    int newRow = *playerRow;
    int newCol = *playerCol;

   
    switch (move) {
        case 'W': case 'w': newRow--; break; 
        case 'S': case 's': newRow++; break; 
        case 'A': case 'a': newCol--; break; 
        case 'D': case 'd': newCol++; break; 
        case 'Q': case 'q': return 0;        
        default:
            printf("Invalid input! Use W, S, A, D to move, or Q to quit.\n");
            return 1;
    }

    if (newRow < 0 || newRow >= SIZE || newCol < 0 || newCol >= SIZE) {
        printf("Error! You can't move outside the grid!\n");
        return 1;
    }

    if (grid[newRow][newCol] == 'X') {
        printf("Error! You can't move into an obstacle!\n");
        return 1;
    }

    if (grid[newRow][newCol] == 'I') {
        (*itemsCollected)++;
        printf("You collected an item! Total items collected: %d\n", *itemsCollected);
    }


    grid[*playerRow][*playerCol] = ' '; 
    grid[newRow][newCol] = 'P';         
    *playerRow = newRow;
    *playerCol = newCol;

    return 1;
}

int main() {
    char grid[SIZE][SIZE] = {
        {' ', ' ', 'I', 'X', ' '},
        {' ', 'X', ' ', ' ', ' '},
        {'I', ' ', 'X', 'X', ' '},
        {' ', ' ', ' ', 'I', 'X'},
        {' ', 'X', ' ', ' ', 'P'}
    };

    int playerRow, playerCol;
    int itemsCollected = 0;
    char move;

    findPlayer(grid, &playerRow, &playerCol);


    while (1) {
        displayGrid(grid);
        printf("\nMove (W: up, S: down, A: left, D: right, Q: quit): ");
        scanf(" %c", &move);

        if (!movePlayer(grid, move, &playerRow, &playerCol, &itemsCollected)) {
            printf("Game Over! Total items collected: %d\n", itemsCollected);
            break;
        }
    }

    return 0;
}
