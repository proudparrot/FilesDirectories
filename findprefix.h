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
void findPrefix(void){
  // get prefix from user
  #define PREFIX
  // Open the current directory
  DIR* currDir = opendir(".");
  struct dirent *aDir;
  struct stat dirStat;
  char entryName[256];

  // Go through all the entries
  while((aDir = readdir(currDir)) != NULL){

    if(strncmp(PREFIX, aDir->d_name, strlen(PREFIX)) == 0){
      // Get meta-data for the current entry
      stat(aDir->d_name, &dirStat);

      printf("%s  %u\n", aDir->d_name, dirStat.st_mode);
      
    }
  }
  // Close the directory
  closedir(currDir);
  #undef PREFIX
}