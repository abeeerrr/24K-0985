#include <stdio.h>
int main() {
float principle, rate, interest, timePeriod;
printf("Take value of your investment. Principle should be between Rs.100 and Rs.1,000,000\n");
scanf("%f", &principle);
printf("Take time period in years. Time duration should be between 1 and 10 years\n");
scanf("%f", &timePeriod);
printf("Enter your rate in percentage. Rate of interest should be between 5 and 10\n");
scanf("%f", &rate);
interest=((principle*rate*timePeriod)/100);
printf("interest value is Rs. %f\n", interest);
return 0;
}
