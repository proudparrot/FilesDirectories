#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* Citation: Code adapted from Example:
* Getting File and Directory Meta-Data
* modified to gaze file sizes
* instead of time modified
*/



/*
* Print the name of the file or directory in the current directory that was modified last among all files or directories that have the prefix student
*/
int findPrefix(void){
  // get prefix from user
  char *userPrefix;
  userPrefix = malloc(sizeof(char));
  printf("Enter the complete filename: ");
  scanf("%s", userPrefix);

  // Open the current directory
  DIR* currDir = opendir(".");
  struct dirent *aDir;
  struct stat dirStat;
  char entryName[256];

  // Go through all the entries
  while((aDir = readdir(currDir)) != NULL){

    if(strncmp(userPrefix, aDir->d_name, strlen(userPrefix)) == 0){
      // Get meta-data for the current entry
      stat(aDir->d_name, &dirStat);
      memset(entryName, '\0', sizeof(entryName));
      strcpy(entryName, aDir->d_name);
      // Close the directory
      closedir(currDir);
      free(userPrefix);
      printf("Now processing the choosen file named %s\n", entryName);
      return 1;
    }
  }
  // when file not found
  printf("the file %s was not found. Try again\n", userPrefix);
  closedir(currDir);
  free(userPrefix);
  return 0;
}