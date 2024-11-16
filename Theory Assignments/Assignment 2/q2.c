/* Name/Roll Number: Abeer Fatima

q2: A popular beverage company is looking to optimize their marketing campaigns by understanding the
frequency of characters used in their promotional slogans. They believe that analyzing these patterns
can help them tailor their messaging to specific demographics and improve brand recall. You've been
tasked with creating a C code function to analyze the character frequency in a list of slogans provided
by the marketing team. This analysis will help identify the most common letters used in their slogans,
which can inform future marketing strategies.
Input:
slogans = ["buy now", "save big", "limited offer"]
Expected Output:
? For "buy now": {'b': 1, 'u': 1, 'y': 1, ' ': 1, 'n': 1, 'o': 1, 'w': 1}
? For "save big": {'s': 1, 'a': 1, 'v': 1, 'e': 1, ' ': 1, 'b': 1, 'i': 1, 'g': 1}
? For "limited offer": {'l': 1, 'i': 1, 'm': 1, 't': 1, 'e': 2, 'd': 1, ' ': 1, 'o': 1, 'f': 1, 'r': 1}

*/

#include <stdio.h>

void countLetters(char str[][50], int n);
void frequency(char str[][50], int n, int i, int j);

int main(){
    int n;
    printf("Enter number of slogans: ");
    scanf("%d", &n);
    char str[n][50];

    for(int i=0; i<n; i++){
        printf("Slogan %d: ", i+1);
        fgets(str[i], 50, stdin);
    }

    for(int i=0; i<n; i++){
        printf("\nFor %s", str[i]);
        countLetters(str, i);
    }
}

void countLetters(char str[][50], int n){
    int i, j;
    for(j=0; str[n][j]!='\0'; j++){
        if(str[n][j]==' '){
            i=j;
        }
    }
    j=j-i-2;
    frequency(str, n, i, j);
    return;
}

void frequency(char str[][50], int n, int a, int b){
    int s=a+b+1, fre[s];
    for(int i=0; i<s; i++){
        fre[i]=1;
    }
    for(int i=0; i<s; i++){
        for(int j=i+1; j<s; j++){
            if(str[n][i]==str[n][j]) fre[i]++;
            if(i<a && j<a) if(str[n][i]==str[n][j]) fre[i]--;
            if(i>b && j>b) if(str[n][i]==str[n][j]) fre[i]--;
            if(str[n][i]==str[n][j]) str[n][j]='0';
        }
        if(str[n][i]!='0') printf("'%c': %d", str[n][i], fre[i]);
    }
    return;
}