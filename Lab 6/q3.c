/*Name/Roll Number: Abeer Fatima (24K-0985)
Q3: Using the above program integrate the number if it is a prime or composite number.

*/

#include <stdio.h>

int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i=2; i*i <= num; i=i+1) {
        if (num%i==0) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int num;

    
    printf("take any number\n");
    scanf("%d", &num);

    
    while (num != 0) {

        
        if (num > 0 && num < 10) {
            printf("it is a single-digit number\n");
        } else if (num >= 10) {
            printf("it is a multiple-digit number\n");
        }

    
        if (num > 1) {
            
			if (isPrime(num)) {
                printf("it is prime\n");
            }
			 else {
                printf("it is composite\n");
            }
        } 
		else if (num==1) {
            printf("it is neither prime nor composite\n");
        }

        
        printf("take any number\n");
        scanf("%d", &num);
    }

    return 0;
}
	
	
