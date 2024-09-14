#include <stdio.h>
int main() {
float x1,y1,x2,y2, slope;
x1=3;
x2=2;
y2=1;
y1=8;
slope=(y2-y1)/(x2-x1);
printf("the slope of the line passing through (3,2) and (1,8) is: %.3f\n", slope);
return 0;
}
