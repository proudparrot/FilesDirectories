// make sure header files are not compiled twice
#ifndef processdir
#define processdir

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "createlist.h"
#include "filemaker.h"

/*
* takes a file name as filePath
* Creates a new directory with name sharmabh.movies.randomNumber
* randomNumber is an integer between 0 and 99999
* generates a linked, invokes processFile from createlist.h
*/




// create new directory
void createDir(char* filePath){
  // constant directory prefix
  char* temp;
  int len;
  temp = malloc(sizeof(char));
  strcpy(temp,"sharmabh.movies.");
  len = strlen(temp);
  char onid[len + 1];
  strcpy(onid, temp);
  free(temp);

  // to store directory extension
  temp = malloc(sizeof(char));
  // generate a random number for suffix
  int num = 0+random( )%99999;
  // convert int to str and store in dirExt
  sprintf(temp, "%d", num);
  len = strlen(temp);
  char dirExt[len+1];
  strcpy(dirExt, temp);
  free(temp);

  // to store directory name
  temp = malloc(sizeof(char));
  temp = strcat(onid, dirExt);
  len = strlen(temp);
  char dirName[len+1];
  strcpy(dirName, temp);

  
  
  // create directory and print message
  mkdir(dirName, 0750);
  printf("Created directory with name %s\n", dirName);

  // get a linked list of movies from filePath
  // Process file and print message
  struct movie* list = processFile(filePath);
  makeFile(dirName, list);
}

// end the condition for compilation of this header file
#endif