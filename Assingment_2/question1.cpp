/**********************************************
Author: Mitchell Panicciari
Date: 11/05/2015
Purpose: Assingment_2 Question_1
***********************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

const int MAX = 22; //Maximum size of the array
const int ALPHABET = 27; //26 letters in the alphabet + another for non alphabetical

/**********************************************
Description: Getting the input from the user and inserting the values in the userInput array
Parameters: char userInput[], int size, int i
Return value: Changing the array values for userInput in main through automatic pass by reference
***********************************************/
void GetInput(char userInput[], int size)
{
	int i;
	
	printf("Please enter up to 20 characters: ");
	fgets(userInput, size, stdin);
	userInput[strlen(userInput) - 1] = '\0'; //Making the last element in the array a null instead of \n
	
	for (i = 0; i < size; i++)
	{
		//Converting the whole contents of the array to lower case (if it is alphabetical)
		userInput[i] = tolower(userInput[i]);
	}

	return;
}

/**********************************************
Description: Looping through the array and counting each time a character occured in the string
Parameters: char userInput[], int size, int i, int counter[]
Return value: Changing the array values for userInput in main through automatic pass by reference
***********************************************/
void CountLetters(char userInput[], int size, int counter[])
{
	int i;
	
	//Setting size to the size of the string that was entered without this code if the user does not enter the full size of the array the unused elements will be counted as non-alphabetical
	size = strlen(userInput);
	
	do
	{
		for (i = 0; i < size; i++)
		{
			//Checking to see if the element at index i is alphabetical
			if (userInput[i] >= 'a' && userInput[i] <= 'z')
			{
				counter[userInput[i] - 'a']++;
			}
			else
			{
				//counter at the index of 26 corresponds to the non-alphabetical characters entered 
				counter[26]++;
			}
		}
	} while (userInput[i] != '\0');
	
	return;
}

/**********************************************
Description: Printing out how many times a character occured in the string
Parameters: int counter[], int i
Return value: Does not return any value
***********************************************/
void PrintResults(int counter[])
{
	int i;
	
	for (i = 0; i < 26; i++)
	{
		//Checking to see if the character occured in the string
		if (counter[i] != 0)
		{
			//Printing out the character and the position in the array that it occured
			printf("%c occurs %d time(s) in this string.\n", i + 'a', counter[i]);
		}
	}
	
	//Checking to see if any non-alphabetical characters occured in the string
	if (counter[26] != 0)
	{
		//Printing out how many times a non-alphabetical character occured
		printf("Non-alphabetical characters occurred %d time(s).\n", counter[26]);
	}
	
	return;
}

/**********************************************
Description: Main function to call the other functions in order that they need to be executed.
Parameters: char userInput[], constant int MAX, int counter[], constant int ALPHABET
Return value: 0
***********************************************/
int main()
{
	char userInput[MAX] = {'\0'}; //Setting the contents of the array to \0 to eliminate any garbage
	int counter[ALPHABET] = {0}; //Setting the contents of the array to 0 so that it can be incremented in CountLetters function
	
	GetInput(userInput, MAX);
	CountLetters(userInput, MAX, counter);
	PrintResults(counter);
	
	return(0);
}