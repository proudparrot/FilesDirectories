#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* exact copy from Program 1: movies
* used to process a file
* to a create and return a linked list of movie data
*/

// global variable to store number of lines
//int totalLines;

/* struct for movie information */
struct movie
{
    char* title;
    char* year;
    char* language;
    char* rating;
    struct movie* next;
};

/* Parse the current line which is space delimited and create a
*  movie struct with the data in this line
*/
struct movie* createMovie(char* currLine)
{
    struct movie* currMovie = malloc(sizeof(struct movie));

    // For use with strtok_r
    char* saveptr;

    // The first token is the Title
    char* token = strtok_r(currLine, ",", &saveptr);
    currMovie->title = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->title, token);

    // The next token is the year
    token = strtok_r(NULL, ",", &saveptr);
    currMovie->year = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->year, token);

    // The next token is the language
    token = strtok_r(NULL, ",", &saveptr);
    currMovie->language = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->language, token);

    // The last token is the rating
    token = strtok_r(NULL, "\n", &saveptr);
    currMovie->rating = calloc(strlen(token) + 1, sizeof(char));
    strcpy(currMovie->rating, token);

    // Set the next node to NULL in the newly created movie entry
    currMovie->next = NULL;

    return currMovie;
}

/*
* Return a linked list of movies by parsing data from
* each line of the specified file.
*/
struct movie* processFile(char* filePath)
{
    // Open the specified file for reading only
    FILE* movieFile = fopen(filePath, "r");

    char* currLine = NULL;
    size_t len = 0;
    size_t nread;
    char* token;
    //int tally = 0;

    // The head of the linked list
    struct movie* head = NULL;
    // The tail of the linked list
    struct movie* tail = NULL;

    // Ignore the first line
    getline(&currLine, &len, movieFile);

    // Read the file line by line
    while ((nread = getline(&currLine, &len, movieFile)) != -1)
    {
        // Get the number of lines in file
        //tally++;

        // Get a new movie node corresponding to the current line
        struct movie* newNode = createMovie(currLine);

        // Is this the first node in the linked list?
        if (head == NULL)
        {
            // This is the first node in the linked link
            // Set the head and the tail to this node
            head = newNode;
            tail = newNode;
        }
        else
        {
            // This is not the first node.
            // Add this node to the list and advance the tail
            tail->next = newNode;
            tail = newNode;
        }
    }
    free(currLine);
    fclose(movieFile);
    //printf("Processed file %s and parsed data for %d movies\n", filePath, tally);
    //totalLines = tally;
    return head;
}

/*
* Print data for the given movie
*/
void printMovie(struct movie* aMovie) {
    printf("%s, %s %s, %s\n", aMovie->title,
        aMovie->language,
        aMovie->year,
        aMovie->rating);
}
/*
* Print the linked list of movies
*/
void printMovieList(struct movie* list)
{
    while (list != NULL)
    {
        printMovie(list);
        list = list->next;
    }
}