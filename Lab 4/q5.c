/*Name: Abeer Fatima (24K-0985)
 *File: q5.c
  Task 5: Write a program in C to calculate and print the Electricity bill of a given customer. The
  customer id., name and unit consumed by the user should be taken from the keyboard and display the 
  total amount to pay to the customer. The charges are as follows:
  
  Unit                           Charge/Unit

Up to 199                         @16.20
200 and above but less than 300   @20.10
300 and above but less than 500   @27.10
500 and above                     @35.90

If the bill exceeds Rs. 18000 then a surcharge of 15% will be charged on top of the bill.

Test Input:
1001 //Customer ID
James //Customer Name
800 //Units Consumed

Expected Output:
Customer ID :1001
Customer Name: James
Units Consumed :800
Amount Charges @Rs. 35.90 per unit: 28720
Surcharge Amount: 4308
Net Amount Paid by the Customer: 33028.00
 */
 
 #include <stdio.h>
 int main(){
 
 int customerID, unitsConsumed;
 float amountCharged = 0, amountPaid = 0, surchargeAmount = 0;
 char customerName[50];
 
 printf("enter the customer ID\n");
 scanf("%d",&customerID);
 printf("customer name\n");
 scanf("%s",&customerName);
 printf("enter units consumed\n");
 scanf("%d",&unitsConsumed);
 
 
   if(unitsConsumed<=199){
     amountCharged = unitsConsumed*16.10;
        }
   else if(unitsConsumed>=200 && unitsConsumed<=300){
     amountCharged = unitsConsumed*20.10;
        }
	else if(unitsConsumed>=300 && unitsConsumed<=500){
	 amountCharged = unitsConsumed*27.10;
	   }
	else if(unitsConsumed>=500){
	 amountCharged = unitsConsumed*35.90;
	   }
	if(amountCharged>18000){
	surchargeAmount = amountCharged*0.15;
	   }
	   else {
	   surchargeAmount = 0;
	   }
	   
	 amountPaid = amountCharged + surchargeAmount;
	   
	   
	
printf("customerID=%d\n",customerID);
printf("customerName=%s\n",customerName);
printf("unitsConsumed=%d\n",unitsConsumed);
printf("amountCharged=Rs.%.2f\n",amountCharged);
printf("surchargeAmount=Rs.%.2f\n",surchargeAmount);
printf("amountPaid=Rs.%.2f\n");

return 0;
}

	
   
  
 