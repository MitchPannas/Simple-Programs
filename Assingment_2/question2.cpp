/**********************************************
Author: Mitchell Panicciari
Date: 11/05/2015
Purpose: Assingment_2 Question_2
***********************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int MAX = 12; //Maximum size of the array
const int ROT = 13; //13 corresponding to the amount each letter is moved in the ROT13 process

/**********************************************
Description: Getting the input from the user and inserting the values in the userInput array
Parameters: char userInput[], int size
Return value: Changing the array values for userInput in main through automatic pass by reference
***********************************************/
void GetInput(char userInput[], int size)
{
	printf("Please enter up to 10 characters: ");
	fgets(userInput, size, stdin);
	userInput[strlen(userInput) - 1] = '\0'; //Making the last element in the array a null instead of \n

	return;
}

/**********************************************
Description: Looping through the array and converting all alphabetical characters with the rot13 process, non alphabetical characters are ignored and not changed 
Parameters: char userInput[], int size, int i, const int ROT 
Return value: Changing the array values for userInput in main through automatic pass by reference
***********************************************/
void Rotate13(char userInput[], int size)
{
	int i;
	
	for (i = 0; i < size; i++)
	{
		//Finding out if the value at the current index is not an alphabetical character - If it is non-alphabetical then leave it unchanged
		if (userInput[i] < 'A' || userInput[i] > 'Z' && userInput[i] < 'a' || userInput[i] > 'z')
		{
			userInput[i] = userInput[i];
		}
		else 
			//If the value at the current index is alphabetical apply the rot13 process to it
			if (userInput[i] >= 'A' && userInput[i] < 'N' || userInput[i] >= 'a' && userInput[i] < 'n')
			{
				userInput[i] += ROT;
			}
			else
			{
				userInput[i] -= ROT; 
			}
	}
	
	return;
}

/**********************************************
Description: Printing out the converted values of the array of userInput
Parameters: char userInput[], int size
Return value: Does not return any value
***********************************************/
void PrintResults(char userInput[], int size)
{
	printf("The new string is: %s\n", userInput);
	
	return;
}

/**********************************************
Description: Asking the user if they would like to enter another set of values
Parameters: char keepGoing
Return value: Returns the value char in keepGoing
***********************************************/
char WantAnotherGo(void) 
{
	char keepGoing;
	
	do
	{
		printf("Do you wish to enter another value? (Y for yes, N for no): ");
		scanf("%c%*c", &keepGoing);
		keepGoing = tolower(keepGoing);
		
		if (keepGoing != 'y' && keepGoing != 'n')
		{
			printf("Invalid input.\n");
		}

	} while (keepGoing != 'y'  && keepGoing != 'n');
	
	
	return(keepGoing);
}

/**********************************************
Description: Main function to call the other functions in order that they need to be executed. Also looping through those functions until the user chooses to stop
Parameters: char userInput[], constant int MAX, char keepGoing
Return value: 0
***********************************************/
int main()
{
	char userInput[MAX] = {'\0'};
	char keepGoing;
	
	do
	{
		GetInput(userInput, MAX);
		Rotate13(userInput, MAX);
		PrintResults(userInput, MAX);
		keepGoing = WantAnotherGo(); 
	} while (keepGoing == 'y');
	
	return(0);
}