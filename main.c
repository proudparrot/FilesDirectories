#include <stdio.h>
#include "mainmenu.h"
#include "submenu.h"
#include "findsmallest.h"
#include "findlargest.h"
#include "findprefix.h"

int main(void) {
  // Display Prompt and get input
    int choice = mainMenu();

    // Continue Until User wants to Exit
    while (choice != 2)
    {
        // Process Choice (1-3)
        if (choice == 1)
        {
            int subchoice = subMenu();
            if (subchoice == 1){
              findLargest();
            } else if (subchoice == 2){
              findSmallest();
            } else{
              printf("name file option\n");
              findPrefix();
            }
        }
        // Repeat Prompt After Processing
        choice = mainMenu();
    }
  return 0;
}