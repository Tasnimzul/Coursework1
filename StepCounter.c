#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
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

int main() {
    char choice;
    char filename[100];
    int fewest;
    int largest;
    int sum = 0;
    int counter = 0;
    int max_continuous = 0;
    int start = 0;
    int data_size = 1000;
    char data_line[data_size];
    FITNESS_DATA stepcount[1000];
    int line_count = 0;

FILE *file = fopen("FitnessData_2023.csv", "r");
if (file == NULL){
     return 1;
}

     while(fgets(data_line, data_size, file)!= NULL){
        char date_token[11];
        char time_token[6];
        char str_steps_token[15];
        tokeniseRecord(data_line, ",", date_token, time_token, str_steps_token);
        stepcount[line_count].steps = atoi(str_steps_token);
        strcpy(stepcount[line_count].date, date_token);
        strcpy(stepcount[line_count].time, time_token);

        line_count++;
        }

fclose(file);

while (1){

    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice:");
    choice = getchar();
    while (getchar() != '\n');

    switch (choice){ 
    
    case 'A':
    case 'a':
           printf("Input filename:");
           scanf("%s", filename);
           file = fopen(filename, "r");
           if (file == NULL){
                printf("Error: Could not find or open the file.\n");
                return 1;
           }
           else {
                printf("File successfully loaded.\n");
           }
           fclose(file);
           break;

    case 'B':
    case 'b':
           printf("Total records: %d\n", line_count);
           break;

    case 'C':
    case 'c':
           fewest = stepcount[0].steps;
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps < fewest) {
                fewest = stepcount[i].steps;
           }
           }
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps == fewest) {
                printf("Fewest Steps: %s %s\n", stepcount[i].date, stepcount[i].time);
           }
           }
           break;

    case 'D':
    case 'd':
           largest = stepcount[0].steps;
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps > largest) {
                largest = stepcount[i].steps;
           }
           }
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps == largest) {
                printf("Largest Steps: %s %s\n", stepcount[i].date, stepcount[i].time);
           }
           }
           break;

    case 'E':
    case 'e':
           for (int i = 0; i < line_count; i++){
               sum += stepcount[i].steps;
           }
           printf("Mean step count: %d\n", sum/line_count);
           break;

    case 'F':
    case 'f':
           for (int i = 0; i < line_count; i++){
              if(stepcount[i].steps > 500){
                     counter++;
              }
              else{
                      if (counter > max_continuous){
                             max_continuous = counter;
                             start = i - counter;
                     }
               counter = 0;
              }
           }
           printf("Longest period start: %s %s\n", stepcount[start].date, stepcount[start].time);
           printf("Longest period end: %s %s\n", stepcount[start+max_continuous-1].date, stepcount[start+max_continuous-1].time);
           break;

    case 'Q':
    case 'q':
           return 0;
           break;

    default :
           printf("Invalid choice. Try again.\n");
           break;

     }
}
return 0;
}