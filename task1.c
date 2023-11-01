#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	char steps[];
} FITNESS_DATA;

// Define any additional variables here

// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {       
        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

}

// Complete the main function
int main() {
    FILE *file = fopen("FitnessData_2023.csv", "r");
    if (file == NULL){
        perror("File opening failure");
        return 1;
    }
    int data_size = 30;
    char data_line[data_size];
    int line = 0;
    FITNESS_DATA onestep[3];

    while (fgets(data_line, data_size, file) != NULL) {
        line++;
        if (line <= 3) {
            tokeniseRecord(data_line, ",", onestep[line].date, onestep[line].time, onestep[line].steps);
            printf("%s/%s/%s\n", onestep[line].date, onestep[line].time, onestep[line].steps);
        }
    }

    printf("Number of records in file: %d\n", line);
    
    fclose(file);
    return 0;
}