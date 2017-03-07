/*****************
This program is used to count how many combinations
are there in a pattern lock (3*3)

First, encode every dots
	o	o	o		1	2	3
	o	o	o	->  4	5	6
	o	o	o  		7	8	9
	
	if you draw a pattern(L), it can be record as 14789 (number)
	
Second, try every number between 1234 (the min number that is rational) and 987654321 (the max)
the conditions below are not except
	1. 1231.2323.4444
	2. 1789 (should be 14789)
	3. 2310.5460
	
	then count how many combinations are excepted.
*****************/ 
#include <stdio.h>
#include <math.h>
#define Size 10 

int check (int, int);

int main ()
{
	int number=1234; //the min way to complete a pattern lock
	int count=0;
	int numBit = 9; 
	
	while (number<987654321) 
	{		
		count+=check(number,numBit); 
		number++;
		printf("%d\n", count);
	}
	
	
}

int check (int number, int numBit)
{
	int array[Size]={0};
	int i, j, littleCount=0;
	
	for (i=0; i<numBit; i++)
	{
		array[i]=number/pow(10,numBit-i-1);
		number-=array[i]*pow(10,numBit-i-1);
	}
	
	for (i=0; i<numBit; i++)
	{
		for (j=0; j<numBit; j++)
			if (array[j]==array[i])
				littleCount++;
	}
	
	if (littleCount!=numBit)
		return 0;
	
	for (i=0; i<numBit-1; i++)
	{
		if (array[i]==1)
		{ 
			if (array[i+1]==3||array[i+1]==7||array[i+1]==9)
				return 0;	
		} 
		else if (array[i]==2)
		{ 
			if (array[i+1]==8)
				return 0;	
		} 
		else if (array[i]==3)
		{ 
			if (array[i+1]==1||array[i+1]==7||array[i+1]==9)
				return 0;
		} 
		else if (array[i]==4)
		{ 
			if (array[i+1]==6)
				return 0;	
		}
		else if (array[i]==6)
		{
			if (array[i+1]==4)
				return 0;
		}
		else if (array[i]==7)
		{ 
			if (array[i+1]==3||array[i+1]==1||array[i+1]==9)
				return 0;
		} 
		else if (array[i]==8)
		{ 
			if (array[i+1]==2)
				return 0;
		} 
		else if (array[i]==9)
		{ 
			if (array[i+1]==3||array[i+1]==7||array[i+1]==1)
				return 0;																				
		} 
		else if (array[i]==0)
			return 0;
	}
		
	if (array[numBit-1]==0)
		return 0;
	
	return 1;	
} 
