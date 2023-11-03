#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
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
    int data_size = 5000;
    char data_line[data_size];
    FITNESS_DATA stepcount[5000];

    int line_count = 0;

    while(fgets(data_line, data_size, file)!= NULL){
        char date[11];
        char time[6];
        char str_steps[15];
        tokeniseRecord(data_line, ",", date, time, str_steps);
        stepcount[line_count].steps = atoi(str_steps);
        strcpy(stepcount[line_count].date, date);
        strcpy(stepcount[line_count].time, time);

        line_count++;
        }
    
    printf("Number of records in file: %d\n", line_count);

    for (int line_count=0; line_count<3; line_count++){
    printf("%s/%s/%d\n", stepcount[line_count].date, stepcount[line_count].time, stepcount[line_count].steps);
    }

    fclose(file);
    return 0;
}