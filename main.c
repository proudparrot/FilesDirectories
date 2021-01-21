#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

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
          int subchoice = 0;
          while(subchoice == 0){
            subchoice = subMenu();
            if (subchoice == 1){
              subchoice = findLargest();
              break;
            } else if (subchoice == 2) {
              subchoice = findSmallest();
              break;
            } else if (subchoice == 3) {
              subchoice = findPrefix();
            }
          } 
        }
        // Repeat Prompt After Processing
        choice = mainMenu();
    }
  return 0;
}