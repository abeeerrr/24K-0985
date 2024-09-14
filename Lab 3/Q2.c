#include <stdio.h>
int main() {
int x,y,z;
printf("take any two numbers\n");
scanf("%d%d", &x,&y);
z=x;
x=y;
y=z;
printf(x,"swapped value\n");
printf(y,"swapped value\n");
		
return 0;
}
			