/**************************************************************\
*                                                              *
* Name		  : 3-1.c                                          *
* Description :                                                *
* Asks user for an ISBN number, validates the input, and       *
* calculates whether the value entered is a valid ISBN.        *
*                                                              *
* The program will run to completion once, letting the user    *
* know the validity of the ISBN entered                        *
*                                                              *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 2015-01-09: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
#include <stdio.h>

#define DIG_MIN 0		// Minimum individual digit value acceptable for ISBN entry
#define DIG_MAX 9		// Maximum individual digit value acceptable for ISBN entry
#define ENOUGH_CHARS 10		// Define the exact # of characters and digits that are required for a valid ISBN number

void wipeInput(void);
void getInput(char *string);

int main(void)
{
	
	char isbn[21];		// Stores the user inputted ISBN
	int i = 0;		// Iteration counter for for loop
	int i_max;		// Variable value to terminate the for loop
	int gcount = 0;		// Counts the number of good values (digits) found in user string isbn[]
	int analyze;		// Stores isbn characters as digits for analysis
	int total = 0;		// Running total of weighted ISBN digits for final calculation
	
	printf("Enter an ISBN to validate: ");
	
	do 
	{
		getInput(&isbn[0]);					// Call getInput() function (ask user to input ISBN number)
		if (strlen(isbn) > 20) isbn[21] = '\0';			// Limit the # of characters analysed to 20 if ISBN string entered is > 20 chars	
		
		for (i = 0; (i+1) <= strlen(isbn); i++)
		{
			analyze = isbn[i] - '0'; 			// Convert character to integer for analysis.
			
			if (analyze >= DIG_MIN && analyze <= DIG_MAX)	// If character is an integer (0 to 9), then
				total = total + (analyze * (10-gcount++));	// find the weighted value and add to running total.
				
			else if (isbn[i] == 'x' || isbn[i] == 'X') 	// If character is 'x' or 'X' (implies 10) then
				total = total + (10 * (10-gcount++));	// find the weighted value and add to running total.
				
			else if (isbn[i] == '-');			// If character is '-' then ignore and move along to next character.
			
			else						// If unexpected character encountered, ask for new input.
			{
				printf("Invalid character entered, please re-enter: ");
				getInput(&isbn[0]);
				
				i = 0; 
				gcount = 0;				// Reset counters to restart the input validation process for a new user input
				total = 0;
			}
		}
		
		if (gcount != ENOUGH_CHARS) 	// If we didn't get ENOUGH_CHARS (10) digits out of this process, then ask the user for new input.
		{		
			gcount = 0;					// Reset counters to restart the input validation process for a new user input
			total = 0;				
			printf("Invalid data entered, too few/too many digits, please re-enter: ");
		}
	} while (gcount != ENOUGH_CHARS);	// Restart loop if we didn't get ENOUGH_CHARS (10) digits out of this process.
	
	if (total % 11 == 0)
		printf("The ISBN %s, is VALID\n", isbn);
	else
		printf("The ISBN %s, is NOT VALID\n", isbn);
	
	return 0;
	
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

/**************************************************************\
*                                                              *
* Name       : getInput()                                      *
* Parameters : char *string (points to &isbn in main)          * 
* Returns    : none                                            *
* Description:                                                 *
* This module requests ISBN input from the user and stores it  *
* in the &isbn address, which is then used in main()           *
*                                                              *
****************************************************************
* MODIFICATION HISTORY                                         *
*                                                              *
* 2015-01-09: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
void getInput(char *string)
{
	int status; 						// Used to verify if scanf() functions have received appropriate data
	
	status = scanf("%s", string);
	wipeInput();
	while (status == 0 || strlen(string) < ENOUGH_CHARS)	// Run invalid entry loop if scanf does not receive at least ENOUGH_CHARS characters
	{	
		printf("Invalid data entered, too few/too many digits, please re-enter: ");
		status = scanf("%s", string);			// Allow user another attempt to enter an ISBN
		wipeInput();
	}
}
