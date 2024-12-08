/* Name/Roll Number: Abeer Fatima (24K-0985)
q2: Write a program that organizes a digital cricket match, "Cricket Showdown," where two players,
Player 1 and Player 2, compete over 12 balls. Each player takes turns to score runs on each ball.
Players can enter scores between 0 and 6 for each ball, and if a score outside this range is entered,
it will be disregarded, but the ball will still be marked.
1. Define a structure Player with the following members:
a. ballScores[12]: An array to store the score for each ball.
b. playerName: A string to hold the player's name.
c. totalScore: An integer to store the total score for each player.
2. Define functions:
a. playGame(struct Player player): This function prompts each player to enter their
score for each of the 12 balls.
b. validateScore(int score): This function checks if the score is between 0 and 6
(inclusive). If it’s not, the score is disregarded, but the ball is still marked.
c. findWinner(struct Player player1,struct Player player2): Determines the winner based
on the total score.
d. displayMatchScoreboard(struct Player player1,struct Player player2): Displays a
summary of each player’s performance, including each ball’s score, the average
score, and total score.
*/

#include <stdio.h>
#include <string.h>

#define BALLS 12

struct Player {
    int ballScores[BALLS];
    char playerName[50];
    int totalScore;
};

void playGame(struct Player *player);
int validateScore(int score);
void findWinner(struct Player player1, struct Player player2);
void displayMatchScoreboard(struct Player player1, struct Player player2);

int main() {
    struct Player player1, player2;

    printf("enter the name of Player 1: ");
    scanf("%s", player1.playerName);
    printf("enter the name of Player 2: ");
    scanf("%s", player2.playerName);

    player1.totalScore = 0;
    player2.totalScore = 0;

    printf("\n--- Player 1's Turn ---\n");
    playGame(&player1);

    printf("\n--- Player 2's Turn ---\n");
    playGame(&player2);

    displayMatchScoreboard(player1, player2);

    findWinner(player1, player2);

    return 0;
}

void playGame(struct Player *player) {
    printf("Player: %s\n", player->playerName);
    for (int i = 0; i < BALLS; i++) {
        int score;
        printf("Enter score for ball %d: ", i + 1);
        scanf("%d", &score);

        if (validateScore(score)) {
            player->ballScores[i] = score;
            player->totalScore += score;
        } else {
            printf("Invalid score! Score must be between 0 and 6. This ball is marked as 0.\n");
            player->ballScores[i] = 0;
        }
    }
}

int validateScore(int score) {
    return (score >= 0 && score <= 6);
}

void findWinner(struct Player player1, struct Player player2) {
    printf("\n--- Match Result ---\n");
    if (player1.totalScore > player2.totalScore) {
        printf("Winner: %s with %d runs!\n", player1.playerName, player1.totalScore);
    } else if (player2.totalScore > player1.totalScore) {
        printf("Winner: %s with %d runs!\n", player2.playerName, player2.totalScore);
    } else {
        printf("It's a tie! Both players scored %d runs.\n", player1.totalScore);
    }
}

void displayMatchScoreboard(struct Player player1, struct Player player2) {
    printf("\n--- Match Scoreboard ---\n");

    printf("Player: %s\n", player1.playerName);
    printf("Scores per ball: ");
    for (int i = 0; i < BALLS; i++) {
        printf("%d ", player1.ballScores[i]);
    }
    printf("Total Score: %d\n", player1.totalScore);
    printf("Average Score: %.2f\n\n", player1.totalScore / (float)BALLS);

    printf("Player: %s\n", player2.playerName);
    printf("Scores per ball: ");
    for (int i = 0; i < BALLS; i++) {
        printf("%d ", player2.ballScores[i]);
    }
    printf("Total Score: %d\n", player2.totalScore);
    printf("Average Score: %.2f\n", player2.totalScore / (float)BALLS);
}

