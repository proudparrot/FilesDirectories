#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

/*
* function makeFile takes directory name and a linked list structure
* adds file to directory with directory name based on year data in linked list
*/

void makeFile(char* dir, struct movie* list){

  // Process through all in list
  while (list !=NULL){

    char fileName[10];
    //make fileName using list->year
    char* filePrefix = list->year;
    char* fileSuffix = "txt";
    sprintf(fileName, "%s.%s", filePrefix, fileSuffix);

    // Create filePath
    char filePath[35];
    sprintf(filePath,"%s/%s", dir, fileName);
    

    // create file in directory
    // Citation: example of writing to a file and reading from it
    // Citation: CS344 W21 Mod3 Files -> Reading and Writing Files
    int fd;
    fd = open(filePath, O_RDWR | O_CREAT | O_APPEND, 0640);
    char* movieTitle = list->title;
    write(fd, strcat(movieTitle,"\n"), strlen(movieTitle));
    close(fd);

    //on to next item in list
    list = list->next;
  }
  return;
}
