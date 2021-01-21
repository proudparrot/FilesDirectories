#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>






// create new directory
void createDir(void){
  // constant directory prefix
  char* onid;
  onid = malloc(sizeof(char));
  strcpy(onid,"sharmabh.movies.");
  
  // to store directory extension
  char* dirExt;
  dirExt = malloc(sizeof(char));

  // to store directory name
  char* dirName;
  dirName = malloc(sizeof(char));

  // generate a random number for suffix
  int num = 0+random( )%99999;

  // convert int to str and store in dirExt
  sprintf(dirExt, "%d", num);
  dirName = strcat(onid, dirExt);
  
  // create directory and print message
  mkdir(dirName, 0750);
  printf("Created directory with name %s\n", dirName);

  // purge malloc memory
  //free(onid);
  //free(dirExt);
  //free(dirName);
}

