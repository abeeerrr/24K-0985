/*Name: Abeer Fatima (24K-0985)
 *File: q4.c
  Task 4: An online shopping store is providing discounts on the items due to the Eid. If the cost of items is less
  than 2000 it will give a discount up to 5%. If the cost of shopping is 2000 to 4000, a 10% discount will be applied.
  If the cost of shopping is 4000 to 6000, a 20% discount will be applied. If it's more than 6000 then a 35% discount 
  will be applied to the cost of shopping. Print the actual amount, saved amount and the amount after discount. The Minimum 
  amount eligible for discount is 500.
 */
 
 #include <stdio.h>
 int main(){
 float actualAmount, savedAmount, amountAfterDiscount, discount;
 
 printf("enter the actual amount\n");
 scanf("%f", &actualAmount);
 
 
 if(actualAmount<500){
 printf("The minimum amount eligble for a discount is 500\n");
 return 0;
 }
 
  if(actualAmount<2000){
  discount = actualAmount*0.05;
  }
  else if(actualAmount>=2000 &&actualAmount<=4000){
  discount = actualAmount*0.1;
  }
  else if(actualAmount>=4000 && actualAmount<=6000){
  discount = actualAmount*0.2;
  }
  else if(actualAmount>6000){
  discount = actualAmount*0.35;
  }
  
   amountAfterDiscount = actualAmount - discount;
   savedAmount = actualAmount - amountAfterDiscount;
   
   printf("actualAmount: %.2f\n", actualAmount);
   printf("savedAmount: %.2f\n", savedAmount);
   printf("amountAfterDiscount: %.2f\n", amountAfterDiscount);
   
   return 0;
   }
 
 
  