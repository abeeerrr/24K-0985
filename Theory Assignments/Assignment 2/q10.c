/*Name/Roll Number: Abeer Fatima (24K-0985)

Q10: In the figures below, a star pattern is illustrated for the values N = 3 and N = 5. Your task is to create
a C program that can print this pattern for odd values of N. Your solution should include the following
components:
1. Include meaningful, properly written English comments that explain the steps of your
program. (Worth 2 points)
2. In the header of the file, describe the pattern. Include information about the length of sides,
the position of the center, and any other relevant details. (Worth 1 points)
3. Prompt the user to enter the value of N. (Worth 1 points)
4. Run your program with an input value of 7. Capture a screenshot and save it as
'K23xxxx_Q01a.png.' (Worth 1 points)
5. Run your program again with an input value of 21. Capture a screenshot and save it as
'K23xxxx_Q01b.png.' (Worth 1 points)
6. For this question, submit only three files, 2 png image files and 1 .c file containing your code,
and there's no need to create a separate folder for Q01. (Worth 1 point)
The remaining marks will be based on the correctness, completeness, and the approach you take in
implementing the program.
*/

#include <stdio.h>

int main(){
    int space , a , spaceinner , star , i , j , l;

    printf("Enter any number :");
    scanf("%d", &a);

    space = (a*2)-2;
    spaceinner = 0;

 for(i = 0; i <  a-1; i++){
    for(j = 0; j < space; j++){
           printf(" ");
        }
        printf("*");
        for(l = 0; l < spaceinner; l++){
            printf(" ");
        }

    if(l != 0)
            printf("*");
    
        printf("\n");

        space--;
        if(i == 0)
            spaceinner++;
        else
            spaceinner+=2;
    }


    for(i = 0 ;  i < a; i++){
        printf("*");
    }

    for(i = 0;  i < spaceinner; i++){
        printf(" ");
    }

    for(i = 0 ;  i < a; i++){
        printf("*");
    }


    printf("\n");
    spaceinner = (spaceinner*2)-1;
    space = 1;

    for(i = 0; i < a-1;  i++){
        for(j = 0; j  < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0 ; l < spaceinner; l++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        spaceinner-=2;
        space++;

    }

    space = a-2;
    spaceinner = 1;
    for(i = 0; i < a-2; i++){
        for(j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        for(l = 0; l < space; l++){
            printf(" ");
        }
        printf("*");
        for(j = 0;  j < spaceinner; j++){
            printf(" ");
        }
        printf("*");
        for( j = 0; j < space; j++){
            printf(" ");
        }
        printf("*");
        printf("\n");
        space --;
        spaceinner+=4;
                }
   
    spaceinner+=2;
    printf("*");
    for(j = 0; j < spaceinner; j++){
        printf(" ");
    }
    printf("*");
    return 0;
}

