#include <stdio.h>
int main() {
int distance, fuelCostComing, fuelCostGoing;
float fuel1, fuel2, totalFuelCost, totalFuelUsed, fuelcost1, fuelcost2;
distance=1207;
fuelCostComing=118;
fuelCostGoing=123;
printf("How much fuel was consumed per km while travelling to B\n");
scanf ("%f", &fuel1);
printf("How much fuel was consumed per km while travelling back to A\n");
scanf("%f", &fuel2);
totalFuelUsed=(fuel1*distance)+(fuel2*distance);
fuelcost1=fuel1*fuelCostComing*distance;
fuelcost2=fuel2*fuelCostGoing*distance;
totalFuelCost=fuelcost2+fuelcost1;
printf("total fuel consumed: %.2f liters\n", totalFuelUsed);
printf("total fuel cost: %.2f Rs\n", totalFuelCost); 
return 0;
}
