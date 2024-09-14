#include <stdio.h>
int main(){
float salary, taxRate, tax;
printf("Take your salary\n");
scanf("%f",&salary);
printf("Enter the tax rate\n");
scanf("%f",&taxRate);
tax=(salary*taxRate)/100);
salary=salary-tax;
printf("tax payable is: %f\n", tax);
printf("salary after tax is: %f\n", salary);
return 0;
}
