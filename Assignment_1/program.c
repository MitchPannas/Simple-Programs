/**********************************************
Author(s): Mitchell Smoothy, Mitchell Panicciari
Date: 17/03/2015
Purpose: Assignment 1
Student Numbers: 32675342, 32674186
***********************************************/

#include <stdio.h>

int main()
{
	int side1, side2, side3;
	
	printf("Please enter first number: ");
	scanf("%d%*c", &side1);
	
	printf("Please enter second number: ");
	scanf("%d%*c", &side2);
	
	printf("Please enter the third number: ");
	scanf("%d%*c", &side3);

	/* Using selection to determine type of triangle */

	if (side1 + side2 < side3 || side1 + side3 < side2 || side2 + side3 < side1)
	{
		printf("Invalid triangle.");
	}
	else
		if (side1 == side2 && side2 == side3)
		{
			printf("This is an equilateral triangle.");
		}
		else
			if (side1 == side2 || side2 == side3 || side3 == side1)
			{
				printf("This is an isosceles triangle.");
			}
			else
				{
					printf("This is a scalene triangle.");
				}
			
	return(0);
}
