/**************************************************************\
*                                                              *
* Name		: 2-2.c                                              *
* Purpose:                                                     *
* Asks user to enter two integer numbers. Uses Euclid's 	     *
* algorithm (recursively) to determine the greatest common     *
* divisor and lowest common multiple of the two factors.	     *
*   														                               *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 2014-12-08: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
#include <stdio.h>

void wipeInput(void);
void interchange(int *u, int *v);
int gcd_lcm(int factor1, int factor2, int *gcd, int *lcm);

int main(void) 
{

	int fac1; 			// Input variable to hold first factor
	int fac2;			// Input variable to hold second factor
	int gcd;			// Greatest Common Divisor, calculated by gc_lcm()
	int lcm;			// Lowest Common Multiple, calculated by gc_lcm()
	int status;			// Input-type validation status; 

	// Ask for factor 1
	printf("Enter Factor1: "); 					
	status = scanf("%d", &fac1); 					// Read user input to 'fac1' variable
	wipeInput();									// Clear any extra data that may be in buffer	
	while (status == 0) 							// Run invalid entry loop if scanf does not receive any numerical data
		{
			printf("Invalid number entered, please re-enter: ");
			status = scanf("%d", &fac1); 			// Allow user another attempt to enter a number
			wipeInput();
		}

	// Ask for factor 2
	printf("Enter Factor2: "); 					
	status = scanf("%d", &fac2); 					// Read user input to 'fac2' variable
	wipeInput();									
	while (status == 0) 			
		{
			printf("Invalid number entered, please re-enter: ");
			status = scanf("%d", &fac2); 			
			wipeInput();
		}
	
	// Figure out GCD & LCM
	gcd_lcm(fac1, fac2, &gcd, &lcm);
	
	// Print final results:
	printf("The GCD of %d and %d is %d.  The LCM is %d", fac1, fac2, gcd, lcm);
	
return 0;
}

/**************************************************************\
*                                                              *
* Name       : gcd_lcm()                                       *
* Parameters : factor1, factor2, *gcd, *lcm                    *
* Returns    : none                                            *
* Description:                                                 *
* This module swaps the values of two variables when they are  *
* passed to it.                                                *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2014-12-08: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/

int gcd_lcm(int factor1, int factor2, int *gcd, int *lcm) 
{

	/* Check if first factor is smaller than second, and swap if true.
	   First factor must be greater than second for algorithm to work.  */
	if (factor1 < factor2) interchange(&factor1, &factor2);
	
	// If second factor is equal to 0, then current first factor is the GCD
	if (factor2 == 0) 
		*gcd = factor1;
		
	/* If second factor isn't equal to 0, then send the modulo forward, 
	   along with the current second factor, to be analysed in another pass */
	else if (factor1 >= factor2 && factor2 > 0) 
		gcd_lcm(factor2, (factor1 % factor2), gcd, lcm);
	
	// Once all calculations are made, finally calculate LCM
	*lcm = (factor1 * factor2)/ *gcd;
	
}
		
/**************************************************************\
*                                                              *
* Name       : interchange()                                   *
* Parameters : *u, *v                                          *
* Returns    : none                                            *
* Description:                                                 *
* This module swaps the values of two variables when they are  *
* passed to it.                                                *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2014-12-08: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
void interchange(int *u, int *v) 
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}
		
/**************************************************************\
*                                                              *
* Name       : wipeInput()                                     *
* Parameters : none                                            *
* Returns    : none                                            *
* Description:                                                 *
* This module clears any extra data that may be in buffer,     *
* such as any non-numerical data trailing the numerical entry. *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2014-11-04: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
void wipeInput(void)
{
   int ch;  			// Temporary variable to read data into

   while((ch = getc(stdin)) != EOF && ch != '\n');
}
