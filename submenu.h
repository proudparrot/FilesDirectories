#include <stdio.h>

/* Citation: Functions mainMenu, choices,
processChoiceInput, getChoiceInput
are adapted from Assignment 1: Movies
written by Abhash Sharma*/

/* Present Choices to User*/
void subchoices(void)
{
    printf("\n");
    printf("Which file you want to process?\n");
    printf("Enter 1 to pick the largest file\n");
    printf("Enter 2 to pick the smallest file\n");
    printf("Enter 3 to specify the name of a file\n");
    //printf("\n");
}

/* Process user's choice input */
int processSubChoiceInput(int userChoice)
{
    // when user's input is invalid
    if (userChoice < 1 || userChoice > 3)
    {
        printf("You entered an incorrect choice. Try again\n");
        return 0;
    }
    return userChoice;
}


/* Get user's Input*/
int getSubChoiceInput(void)
{
    int numInput = 0;
    printf("Enter a choice from 1 to 3: ");
    scanf("%d", &numInput);
    return processSubChoiceInput(numInput);
}


/* Displays prompt to user, Returns integer value of user's choice*/
int subMenu(void)
{
    // to repeat choice prompt until valid input
    int validity = 0;
    // Get a valid input from user
    do
    {
        // Display a menu of interactive choices to user
        subchoices();
        // Get and Process user's input
        validity = getSubChoiceInput();
    } while (validity == 0);
    return validity;
}