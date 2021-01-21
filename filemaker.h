#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void createFilename(void){
  return;
}

void makeFile(char* dir){
  // Open the new directory passed in dir
  // Citation: CS344 W21 Module3 Directories Example1
  DIR* newDir = opendir(dir);
  struct dirent *nDir;
  
  // Add new file to new directory
  // Citation: CS344 W21 Module3 Files Example1
  int file_descriptor;
	char* newFilePath = "YYYY.txt";

  // flags: the arguments are OR-ed togther
  // O_RDWR reading and writing
  // O_CREAT create an empty file if the file doesn't exist
  // O_APPEND append to end of file
  // mode:
  // 0640 Owner can read and write the file and group has read only
	file_descriptor = open(newFilePath, O_RDWR | O_CREAT | O_APPEND, 0640);
	if (file_descriptor == -1){
		printf("open() failed on \"%s\"\n", newFilePath);
		perror("Error");
		exit(1);
	}
	
	printf("file_descriptor = %d\n", file_descriptor);
	
  // Go through all the entries
  while((nDir = readdir(newDir)) != NULL){
    printf("%s  %lu\n", nDir->d_name, nDir->d_ino);    
  }
  // Close the directory
  closedir(newDir);
  return;
}
