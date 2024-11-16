/*Name/Roll Number: Abeer Fatima (24K-0985)
Q6: Two friends, A and B, are playing the game of matchsticks. In this game, a group of N matchsticks is
placed on the table. The players can pick any number of matchsticks from 1 to 4 (both inclusive)
during their chance. The player who takes the last matchstick wins the game. If A starts first, how
many matchsticks should he pick on his 1st turn such that he is guaranteed to win the game or
determine if it’s impossible for him to win? Write a function which returns -1 if it’s impossible for A to
win the game, else return the number of matchsticks he should pick on his 1st turn such that he is
guaranteed to win.
*/

#include <stdio.h>

int winningFirstMove(int m) {
    if (m % 5 == 0) {
        return -1; 
    }
    return m % 5; 
}

int main() {
    int m;

    printf("take the number of matchsticks: ");
    scanf("%d", &m);

    int result = winningFirstMove(m);

    if (result == -1) {
        printf("It is impossible for A to guarantee a win.\n");
    } 
	else {
      printf("A should pick %d matchstick(s) on his first turn to guarantee a win.\n", result);
         }

    return 0;
}
