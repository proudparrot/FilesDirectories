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
#include <time.h>
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
  char* onid = "sharmabh.movies.";

  //to store directory name
  char* dirName;
  dirName = malloc(25);
  strcpy(dirName, onid);

  // to store directory extension
  char dirExt[6];
  // generate a random number for suffix
  // Citation: https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
  srandom(time(0));
  int num = 0+random( )%99999;
  // convert int to str and store in dirExt
  sprintf(dirExt, "%d", num);
  strcat(dirName, dirExt);

  
  // create directory and print message
  mkdir(dirName, 0750);
  printf("Created directory with name %s\n", dirName);

  // get a linked list of movies from filePath
  // Process file and print message
  struct movie* list = processFile(filePath);
  makeFile(dirName, list);
  free(dirName);
  return;
}

// end the condition for compilation of this header file
#endif