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

// looking for file with prefix movies_
#define PREFIX "movies_"

/*
* print file with prefix movies_
* with smallest size
*/
void findSmallest(void){
  // Open the current directory
  DIR* currDir = opendir(".");
  struct dirent *aDir;
  off_t smallestFile;
  struct stat dirStat;
  char entryName[256];
  // Go through all the entries
  while((aDir = readdir(currDir)) != NULL){
    // match file with prefix
    if(strncmp(PREFIX, aDir->d_name, strlen(PREFIX)) == 0){
      // Get meta-data for the current entry
      stat(aDir->d_name, &dirStat);
      // change entryName when size of file is smaller
      // than size in smallestFile
      if (dirStat.st_size < smallestFile){
        smallestFile = dirStat.st_size;
        memset(entryName, '\0', sizeof(entryName));
        strcpy(entryName, aDir->d_name);
      }
    }   
  }
  // Close the directory
  closedir(currDir);
  printf("Now processing the choosen file named %s\n", entryName);
}
