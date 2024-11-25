
/* Name/Roll Number: Abeer Fatima (24K-0985)
Q: Take the following structures and create functions that perform CRUD (create, read, update delete) operations in a file or multiple files depending on the need based on your understanding. Add a comment that exlpains your choice.

struct player{
char name[20];
char team[20];
};

struct bowl{
char type[10]; // seemer, pacer, spinner// N/A
char arm[5]; //left or right
struct player ply;
};

struct bat{
char type[10]; // top order, middle order, lower order
char handed[8]; //lefty or righty
struct bowl ply2;
};

// suppose that you have to store data for 5 players with at least 3 bowlers. The rest will be N/A.

*/

#include <stdio.h>
#include <string.h>

struct player {
    char name[20];
    char team[20];
};

struct bowl {
    char type[10];  // Seemer, Pacer, Spinner, etc.
    char arm[6];    // Left or Right
    struct player ply;
};

struct bat {
    char type[10];  // Top-order, Middle-order, Lower-order
    char handed[8]; // Lefty or Righty
    struct bowl ply2;
};

void createPlayer(struct player *p, const char *name, const char *team);
void createBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team);
void createBatsman(struct bat *bt, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team);
void readPlayer(struct player *p);
void readBowler(struct bowl *b);
void readBatsman(struct bat *b);
void updatePlayer(struct player *p, const char *name, const char *team);
void updateBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team);
void updateBatsman(struct bat *b, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team);
void deletePlayer(struct player *p);
void deleteBowler(struct bowl *b);
void deleteBatsman(struct bat *b);
void storePlayerData(const char *filename, struct player players[], int size);
void storeBowlerData(const char *filename, struct bowl bowlers[], int size);
void storeBatsmanData(const char *filename, struct bat batsmen[], int size);
void retrievePlayerData(const char *filename, struct player players[], int *size);
void retrieveBowlerData(const char *filename, struct bowl bowlers[], int *size);
void retrieveBatsmanData(const char *filename, struct bat batsmen[], int *size);

int main() {
    struct player players[5];
    struct bowl bowlers[3];
    struct bat batsmen[2];
    int playerSize, bowlerSize, batsmanSize;

    createPlayer(&players[0], "mark", "india");
    createPlayer(&players[1], "trishul", "india");
    createPlayer(&players[2], "mosambi ka juice", "pakistan");
    createPlayer(&players[3], "sir aashir", "pakistan");
    createPlayer(&players[4], "gopi bahu", "india");

    createBowler(&bowlers[0], "pacer", "left", "david", "usa");
    createBowler(&bowlers[1], "pacer", "right", "michaelangelo", "australia");
    createBowler(&bowlers[2], "seemer", "right", "steven", "germany");

    createBatsman(&batsmen[0], "lefty", "top-order", "seemer", "left", "basheer", "japan");
    createBatsman(&batsmen[1], "right", "middle", "seemer", "pacer", "jude bellingham", "england");
    
    printf("Players:\n");
    storePlayerData("players.txt", players, 5);
    retrievePlayerData("players.txt", players, &playerSize);
    for (int i = 0; i < playerSize; i++) {
        readPlayer(&players[i]);
    }

    printf("\nBowlers:\n");
    storeBowlerData("bowlers.txt", bowlers, 3);
    retrieveBowlerData("bowlers.txt", bowlers, &bowlerSize);
    for (int i = 0; i < bowlerSize; i++) {
        readBowler(&bowlers[i]);
    }

    printf("\nBatsmen:\n");
    storeBatsmanData("batsmen.txt", batsmen, 2);
    retrieveBatsmanData("batsmen.txt", batsmen, &batsmanSize);
    for (int i = 0; i < batsmanSize; i++) {
        readBatsman(&batsmen[i]);
    }

    return 0;

    
}

void createPlayer(struct player *p, const char *name, const char *team) {
    strcpy(p->name, name);
    strcpy(p->team, team);
}

void createBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->arm, arm);
    strcpy(b->ply.name, name);
    strcpy(b->ply.team, team);
}

void createBatsman(struct bat *bt, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team) {
    strcpy(bt->type, type);
    strcpy(bt->handed, handed);
    strcpy(bt->ply2.type, bowlType);
    strcpy(bt->ply2.arm, arm);
    strcpy(bt->ply2.ply.name, name);
    strcpy(bt->ply2.ply.team, team);
}

void readPlayer(struct player *p) {
    printf("Name: %s, Team: %s\n", p->name, p->team);
}

void readBowler(struct bowl *b) {
    printf("Bowler Type: %s, Arm: %s\n", b->type, b->arm);
    readPlayer(&b->ply);
}

void readBatsman(struct bat *b) {
    printf("Batsman Type: %s, Handed: %s\n", b->type, b->handed);
    readBowler(&b->ply2);
}

void updatePlayer(struct player *p, const char *name, const char *team) {
    strcpy(p->name, name);
    strcpy(p->team, team);
}

void updateBowler(struct bowl *b, const char *type, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->arm, arm);
    strcpy(b->ply.name, name);
    strcpy(b->ply.team, team);
}

void updateBatsman(struct bat *b, const char *type, const char *handed, const char *bowlType, const char *arm, const char *name, const char *team) {
    strcpy(b->type, type);
    strcpy(b->handed, handed);
    strcpy(b->ply2.type, bowlType);
    strcpy(b->ply2.arm, arm);
    strcpy(b->ply2.ply.name, name);
    strcpy(b->ply2.ply.team, team);
}

void deletePlayer(struct player *p) {
    strcpy(p->name, "");
    strcpy(p->team, "");
}

void deleteBowler(struct bowl *b) {
    strcpy(b->type, "");
    strcpy(b->arm, "");
    strcpy(b->ply.name, "");
    strcpy(b->ply.team, "");
}

void deleteBatsman(struct bat *b) {
    strcpy(b->type, "");
    strcpy(b->handed, "");
    strcpy(b->ply2.type, "");
    strcpy(b->ply2.arm, "");
    strcpy(b->ply2.ply.name, "");
    strcpy(b->ply2.ply.team, "");
}

void storePlayerData(const char *filename, struct player players[], int size) {
    int i;
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    for (i = 0; i < size; i++) {
        fprintf(fptr, "%s %s\n", players[i].name, players[i].team);
    }
    fclose(fptr);
}

void storeBowlerData(const char *filename, struct bowl bowlers[], int size) {
    int i;
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    for (i = 0; i < size; i++) {
        fprintf(fptr, "%s %s %s %s\n", bowlers[i].type, bowlers[i].arm, bowlers[i].ply.name, bowlers[i].ply.team);
    }
    fclose(fptr);
}

void storeBatsmanData(const char *filename, struct bat batsmen[], int size) {
    int i;
    FILE *fptr = fopen(filename, "w");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    for (i = 0; i < size; i++) {
        fprintf(fptr, "%s %s %s %s %s %s\n", batsmen[i].type, batsmen[i].handed, batsmen[i].ply2.type, batsmen[i].ply2.arm, batsmen[i].ply2.ply.name, batsmen[i].ply2.ply.team);
    }
    fclose(fptr);
}

void retrievePlayerData(const char *filename, struct player players[], int *size) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    *size = 0;
    while (fscanf(fptr, "%s %s", players[*size].name, players[*size].team) != EOF) {
        (*size)++;
    }
    fclose(fptr);
}

void retrieveBowlerData(const char *filename, struct bowl bowlers[], int *size) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    *size = 0;
    while (fscanf(fptr, "%s %s %s %s", bowlers[*size].type, bowlers[*size].arm, bowlers[*size].ply.name, bowlers[*size].ply.team) != EOF) {
        (*size)++;
    }
    fclose(fptr);
}

void retrieveBatsmanData(const char *filename, struct bat batsmen[], int *size) {
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL) {
        perror("File doesn't exist");
        return;
    }
    *size = 0;
    while (fscanf(fptr, "%s %s %s %s %s %s", batsmen[*size].type, batsmen[*size].handed, batsmen[*size].ply2.type, batsmen[*size].ply2.arm, batsmen[*size].ply2.ply.name, batsmen[*size].ply2.ply.team) != EOF) {
        (*size)++;
    }
    fclose(fptr);
}