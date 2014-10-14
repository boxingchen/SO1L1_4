/* File: lab1_4.c */
/* Alexander Ustyuzhanin, IE SO1 group 1, WS14, 06.10.2014 */

#define _CRT_SECURE_NO_WARNINGS											// suppress warnings about unsafe scanf (C4996)
#include <stdio.h>														// for the IO functions
#include <stdlib.h>														// for system("pause")

int main()
{
	short int year;														// a variable for storing the year value
	short int day;														// needed to run cycles
	short int month;													// needed for the CASE statement
	short int oddDays=0;												// initialize the counters for number of days
	short int evenDays=0;	
	enum months{January=1, February, March, April, May, June, July, August, September, October, November, December};	// I'll use enumeration for convinience

	printf("Enter the desired year: ");
	if(!((scanf("%hd",&year)>0)))										// I check whether scanf function performed correctly
	{																	// if not display the error message and exit the program
		printf("Sorry, could not read the year. Wrong input?\n");
		system("pause");
		return 0;
	}

	if(!year)															// as far as I know there is no 0 year
	{
		printf("Year %hd does not exist\n", year);
		system("pause");
		return 0;
	}

	if(year%4)															// check if this is a leap year or not. If year%4 gives anything but 0, it's not a leap year.
	{
		printf("This is a non-leap year\n");
		for(month=January; month<December+1; month++)					// proceed to count the number of days in each month. Cycle exit condition is reaching 13th month (December+1)
		{
			switch(month)
			{
			case January:												// all these have 31 days
			case March:
			case May:
			case July:
			case August:
			case October:
			case December:
				for(day=1; day<32; day++)
				{
					if(day%2)											// if the date is divisible by 2, the remainder will be 0				
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			case February:												// a special case for February - 28 days!
				for(day=1; day<29; day++)
				{
					if(day%2)
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			case April:													// these months have 30 days
			case June:
			case September:
			case November:
				for (day=1; day<31; day++)
				{
					if(day%2)
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			}
		}
	}
	else																// if it IS the leap year, we're running the same cycles, only February has 29 days instead of 28
	{																	// I just copy-pasted it, so forgive me for not commenting (yeah I'm lazy)		
		printf("This is a leap year\n");
		for(month=January; month<December+1; month++)
		{
			switch(month)
			{
			case January:
			case March:
			case May:
			case July:
			case August:
			case October:
			case December:
				for(day=1; day<32; day++)
				{
					if(day%2)
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			case February:
				for(day=1; day<30; day++)								// as you can see, one day longer than in a non-leap year
				{
					if(day%2)
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			case April:
			case June:
			case September:
			case November:
				for(day=1; day<31; day++)
				{
					if(day%2)
					{
						oddDays++;
					}
					else
					{
						evenDays++;
					}
				}
				break;
			}
		}
	}

	printf("Total number of odd days: %hi\n", oddDays);					// displaying the results
	printf("Total number of even days: %hi\n", evenDays);
	printf("Total number of days: %hi\n", oddDays+evenDays);			// the sum of days is calculated and displayed just to make sure everything is calculated correctly
	system("pause");													// give the user a chance to see stuff before the window closes
	return 0;															// the return value for int main()
}