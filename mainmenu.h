#include <stdio.h>

/* Citation: Functions mainMenu, choices,
processChoiceInput, getChoiceInput
are adapted from Assignment 1: Movies
written by Abhash Sharma*/

/* Present Choices to User*/
void choices(void)
{
    printf("\n");
    printf("1. Select file to process\n");
    printf("2. Exit the program\n");
    printf("\n");
}

/* Process user's choice input */
int processChoiceInput(int userChoice)
{
    // when user's input is invalid
    if (userChoice < 1 || userChoice > 2)
    {
        printf("You entered an incorrect choice. Try again\n");
        return 0;
    }
    return userChoice;
}


/* Get user's Input*/
int getChoiceInput(void)
{
    int numInput = 0;
    printf("Enter a choice from 1 or 2: ");
    scanf("%d", &numInput);
    return processChoiceInput(numInput);
}


/* Displays prompt to user, Returns integer value of user's choice*/
int mainMenu(void)
{
    // to repeat choice prompt until valid input
    int validity = 0;
    // Get a valid input from user
    do
    {
        // Display a menu of interactive choices to user
        choices();
        // Get and Process user's input
        validity = getChoiceInput();
    } while (validity == 0);
    return validity;
}