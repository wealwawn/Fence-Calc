#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
// Here are all the function prototypes. Above are two additional libraries included, math.h, and stdbool.h
void displayWelcome(void);
double getPerimeter (void);
int getCorners (void);
int getGates (void);
char getFenceType (void);
int computePanels (double perimeter, int panelLength);
int computePosts (int numCorners, int numGates, int numPanels);
void displayResults (double perimeter, int numPosts, int numGates, char fenceType, int numPanels);
void displayCredits (void);
// Program:	Project 3
// Author:		Fence-Calc
// Course:		Cop 2220C

//The main function
int main (void)
{
	//assigned a static number to the panel length because all of the lengths were the same
	double perimeter;
	int panelLength = 8;
	char fenceType, keepGoing;
	int numCorners, numGates, numPanels, numPosts;
	//Do while loop contains all the function necessary to have the program repeat
	do
	{
		perimeter = getPerimeter ();
		numCorners = getCorners ();
		numGates = getGates ();
		fenceType = getFenceType ();
		numPanels = computePanels (perimeter, panelLength);
		numPosts = computePosts (numCorners, numGates, numPanels);
		displayResults(perimeter, numPosts, numGates, fenceType, numPanels);
        fflush(stdin);
        printf("Enter y to start over from the beginning \n");
        scanf("%c", &keepGoing);
	}
	while (keepGoing == 'y');
	displayCredits ();
	return 0;
}

//This function is displayWelcome. It accepts no parameters. It prints out a welcome message.
void displayWelcome ()
{
	printf("Welcome to FenceFinder! Where we find facts about your fence to be!\n ");
return 0;
}

/*This is the getPerimeter function. It accepts no parameters
 It has a do while loop that asks the user for the perimeter
 When scanning for the user input, we assign the return of the
 scan function to varCheck, which will be 0 if its not a double,
 1 if it is, then an if statement to reset the buffer to char c
 if varCheck is not 1 and repeats the loop,
re-prompting the user, rescanning until they give an appropriate data type,
 then returning the double perimeter*/
double getPerimeter ()
{
	double perimeter;
	bool varCheck;
	char c;
	do
	{
		printf("Please enter the perimeter of the fence: \n");
		varCheck = scanf("%lf", &perimeter);
		if (varCheck != 1)
			scanf("%c", &c);
	}
	while (varCheck != 1 || perimeter <= 0);
	return perimeter;
}

/*This is the getCorners function. It accepts no parameters
 It has a do while loop that asks the user for the number of corners
 When scanning for the user input, we assign the return of the
 scan function to varCheck, which will be 0 if its not a double,
 1 if it is, then an if statement to
 reset the buffer to char c if varCheck is not 1
 and repeats the loop, re-prompting the user, rescanning until they
 give an appropriate data type, then returning the int numCorners*/
int getCorners ()
{
	int numCorners;
	char c;
	bool varCheck;
	do
	{
		printf("Please enter the number of corners the fence has: \n");
		varCheck = scanf("%d", &numCorners);
		if (varCheck != 1)
			scanf("%c", &c);
	}
	while (varCheck != 1 || numCorners < 0);
	return numCorners;
}

/*This is the getGates function. It accepts no parameters
 It has a do while loop that asks the user for the number of gates
 When scanning for the user input, we assign the return of the
 scan function to varCheck, which will be 0 if its not a double,
 1 if it is, then an if statement to
 reset the buffer to char c if varCheck is not 1
 and repeats the loop, re-prompting the user, rescanning until they
 give an appropriate data type, then returning the int numGates*/
int getGates ()
{
	int numGates;
	char c;
	bool varCheck;
	do
	{
		printf("Please enter the number of gates the fence has: \n");
		varCheck = scanf("%d", &numGates);
		if (varCheck != 1)
			scanf("%c", &c);
	}
	while (varCheck != 1 || numGates < 0);
	return numGates;
}

/*This is the getFenceType function. It accepts no parameters.
It asks the user for the type of fence and takes the input and
store is in the fenceType variable, returning that to main
*/
char getFenceType ()
{
	char fenceType;
		printf("Please enter the type of the fence(b, s, or v): \n");
		scanf(" %c", &fenceType);
	return fenceType;
}

/* This is the computePanels function. It takes two parameters
the double perimeter and integer panelLength
It takes the perimeter, divides it by panel length, and then
Uses the ceil function to round to the next highest integer
Then we cast the double numPanels that we stored the result in
to return it
*/
int computePanels (double perimeter, int panelLength)
{
	double numPanels;
	numPanels = ceil (perimeter / panelLength);
	(int) numPanels;
	return numPanels;
}

/* This is the computePosts function. It takes three parameters
Integer numCorners, integer numGates, integer numPanels
It assigns the numPosts variable to the sum of all the input parameters
the it returns the numPosts
*/
int computePosts (int numCorners, int numGates, int numPanels)
{
	int numPosts;
	numPosts = numCorners + numGates + numPanels;
	return numPosts;
}

/* This is the computePosts function. It takes five parameters
Double Perimeter, integers numPosts, numGates, and numPanels, and the char fenceType
It prints a small statement, after that, a series of ifs determine which fence type to print
This way the user gets more than a single char for the printout!
*/
void displayResults (double perimeter, int numPosts, int numGates, char fenceType, int numPanels)
{
	printf("Here are the facts about your fence! \n");
	if (fenceType == 'b')
		printf("Perimeter: %.4lf \n Number of Posts: %d \n Number of Gates: %d \n  Fencetype: Board on Board \n Number of Panels: %d \n", perimeter, numPosts, numGates, numPanels);
	if (fenceType == 's')
		printf("Perimeter: %.4lf \n Number of Posts: %d \n Number of Gates: %d \n  Fencetype: Shadowbox \n Number of Panels: %d \n", perimeter, numPosts, numGates, numPanels);
	if (fenceType == 'v')
		printf("Perimeter: %.4lf \n Number of Posts: %d \n Number of Gates: %d \n  Fencetype: Vinyl \n Number of Panels: %d \n", perimeter, numPosts, numGates, numPanels);
}

/*This is the displayCredits function. It takes no parameters.
It displays the author to the use at the end of the program
*/
void displayCredits ()
{
	printf("FenceFinder has been brought to you by Justin Nunley");
    return 0;
}

/*
Test Data

Test 1 Input
Perimeter: 42
Corners: 3
Gates: 2
Type of Fence: v

Test 1 Expected Results
Perimeter: 42
Number of Posts:11
Number of Gates:2
Fencetype: Vinyl
Number of Panels:6

Test 1 Actual Results
Here are the facts about your fence!
Perimeter: 42.0000
 Number of Posts: 11
 Number of Gates: 2
  Fencetype: Vinyl
 Number of Panels: 6
Enter y to start over from the beginning
FenceFinder has been brought to you by Justin Nunley
Process returned 0 (0x0)   execution time : 12.671 s
Press any key to continue.

Test 2 Input
Perimeter:50 feet
Corners: 1
Gates:0
Type of Fence: s

Test 2 Expected Results
Perimeter: 72
Number of Posts:10
Number of Gates:0
Fencetype: Shadowbox
Number of Panels:9

Test 2 Actual Results
Here are the facts about your fence!
Perimeter: 72.0000
 Number of Posts: 10
 Number of Gates: 0
  Fencetype: Shadowbox
 Number of Panels: 9
Enter y to start over from the beginning
FenceFinder has been brought to you by Justin Nunley
Process returned 0 (0x0)   execution time : 4200.671 s
Press any key to continue.

Test 3 Input
Perimeter:48
Corners:2
Gates: 1
Type of Fence:b
(At the end, y)
Perimeter:96
Corners:4
Gates:2
Type of Fence:s
(y again)
Perimeter:127.2
Corners:6
Gates:2
Type of Fence:v

Test 3 Expected Results
Perimeter: 48
Number of Posts:9
Number of Gates:1
Fencetype: Board on Board
Number of Panels:6

Perimeter: 96
Number of Posts:18
Number of Gates:2
Fencetype: Shadowbox
Number of Panels:12

Perimeter: 42
Number of Posts:24
Number of Gates:2
Fencetype: Vinyl
Number of Panels:16

Test 3 Actual Results
Please enter the perimeter of the fence:
48
Please enter the number of corners the fence has:
2
Please enter the number of gates the fence has:
1
Please enter the type of the fence(b, s, or v):
b
Here are the facts about your fence!
Perimeter: 48.0000
 Number of Posts: 9
 Number of Gates: 1
  Fencetype: Board on Board
 Number of Panels: 6
Enter y to start over from the beginning
y
Please enter the perimeter of the fence:
96
Please enter the number of corners the fence has:
4
Please enter the number of gates the fence has:
2
Please enter the type of the fence(b, s, or v):
s
Here are the facts about your fence!
Perimeter: 96.0000
 Number of Posts: 18
 Number of Gates: 2
  Fencetype: Shadowbox
 Number of Panels: 12
Enter y to start over from the beginning
y
Please enter the perimeter of the fence:
127.2
Please enter the number of corners the fence has:
6
Please enter the number of gates the fence has:
2
Please enter the type of the fence(b, s, or v):
v
Here are the facts about your fence!
Perimeter: 127.2000
 Number of Posts: 24
 Number of Gates: 2
  Fencetype: Vinyl
 Number of Panels: 16
Enter y to start over from the beginning
FenceFinder has been brought to you by Justin Nunley
Process returned 0 (0x0)   execution time : 259.671 s
Press any key to continue.


*/
