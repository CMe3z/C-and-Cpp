/**************************************************************\
*                                                              *
* Name		: 2-1.c                                              *
* Purpose:                                                     *
* Asks user for hour, minute and how many consecutive minutes  *
* should be displayed, while validating all inputs.            *
*                                               	             *
* The program will add 1 minute to the time that has been      *
* entered and display the new time - repeating until the       *
* number of requested minutes has been displayed               *
*															   *
****************************************************************
* MODIFICATION HISTORY:                                        *
* 2014-12-07: Chad Medeiros - created                          *
*                                                              *
\**************************************************************/
#include <stdio.h>

void wipeInput(void);

int main(void)
{

	int hour;			
	int minute;			
	int askmin;			
	char apm;			
	int status;			

	// Ask for hour
	printf("Enter the hour: "); 					
	status = scanf("%d", &hour); 					// Read user input to 'hour' variable
	wipeInput();									// Clear any extra data that may be in buffer	
	while (status == 0 || hour < 1 || hour > 12) 	// Run invalid entry loop if scanf does not receive any numerical data
		{
			printf("Invalid value entered. Must be 1 to 12, please re-enter: ");
			status = scanf("%d", &hour); 			// Allow user another attempt to enter a number
			wipeInput();
		}
		
	// Ask for minute
	printf("Enter the minute: "); 					
	status = scanf("%d", &minute); 					// Read user input to 'minute' variable
	wipeInput();									
	while (status == 0 || minute < 0 || minute > 59) 		
		{
			printf("Invalid value entered. Must be 0 to 59, please re-enter: ");
			status = scanf("%d", &minute); 			
			wipeInput();
		}
		
	// Ask for AM or PM ('A' or 'P')
	printf("Enter A (for AM) or P (for PM): ");  	
	status = scanf("%c", &apm); 					// Read user input to 'apm' variable
	wipeInput();									
	while (status == 0 || apm != 'A'  && apm != 'P') 		
		{
			printf("Invalid value entered.  Must be \'A\' or \'P\', please re-enter: ");
			status = scanf("%c", &apm); 			// Allow user another attempt to enter A or P
			wipeInput();
		}
		
	// Ask for # minutes to display
	printf("Enter how many minutes to display: "); 	
	status = scanf("%d", &askmin); 					// Read user input to 'askmin' variable
	wipeInput();										
	while (status == 0 || askmin < 0 || askmin > 60) 		
		{
			printf("Invalid value entered. Must be 0 to 60, please re-enter: ");
			status = scanf("%d", &askmin);
			wipeInput();
		}

	// Output the time for the next 'askmin' number of minutes
	printf("The new time is\n");
	for ( ; askmin > 0; askmin--) {
		
		if (++minute == 60) {
			hour = hour + 1;
			minute = 0;
		
			if (hour == 12) {
				if (apm == 'A') apm = 'P';
				else apm = 'A';
			}	
			
			if (hour == 13) hour = 1;		
		}	
							
		printf("%d:%02d %cM\n", hour, minute, apm);
	}
	
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
