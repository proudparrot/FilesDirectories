#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

void addFile(struct movie* list){
  printf("%s\n", list->year);
  return;
}

void makeFile(char* dir, struct movie* list){

  // Process through all in list
  while (list !=NULL){

    //to temporarily store string
    char* temp_str = malloc(sizeof(char));
    int str_len;

    //make fileName using list->year
    char* filePrefix = list->year;
    char* fileSuffix = "txt";
    sprintf(temp_str, "%s.%s", filePrefix, fileSuffix);
    str_len = strlen(temp_str);
    char fileName[str_len + 1];
    strcpy(fileName, temp_str);
    free(temp_str);

    // Create filePath
    temp_str = malloc(sizeof(char));
    sprintf(temp_str,"%s/%s", dir, fileName);
    str_len = strlen(temp_str);
    char filePath[str_len + 1];
    strcpy(filePath, temp_str);
    free(temp_str);

    // create file in directory
    open(filePath, O_RDWR | O_CREAT | O_APPEND, 0640);

    //on to next item in list
    list = list->next;
  }
  
}
