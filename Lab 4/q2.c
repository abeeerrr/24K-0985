/*Name: Abeer Fatima (24K-0985)
 *File: q1.c
  Task 2: Create a calculator asking for operator (+ or - or * or /) and 
  operands and performs calculation according to the user input using switch statement.
 */
 
 #include <stdio.h>
 int main(){
  int x, y;
  char operator;
   printf("take two numbers\n");
   scanf("%d%d",&x,&y);
   printf("choose an operator from +,-,*,/\n");
   scanf("%c",&operator);
   
   switch(operator){
      case '+':
	    printf("x+y is the answer\n");
		break;
	  
	  case '-':
	    printf("x-y is the answer\n");
		break;
	 
      case '*':
		printf("x*y is the answer\n");
		break;
	  
	  case '/':
		if("y == o"){
		 printf("ERROR\n");
		 }
		 else {
		  printf("x/y is the answer\n");
		  }
		break;
		
	  default:
	   printf("invalid input! please use integers/n");
	               }
	   return 0;
	   }
   
 
 