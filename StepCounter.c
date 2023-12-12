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

    FILE *file;
    char choice;
    char filename[1500];
    int fewest;
    int largest;
    float sum = 0;
    int counter = 0;
    int max_continuous = 0;
    int start = 0;
    int data_size = 1500;
    char data_line[data_size];
    FITNESS_DATA stepcount[1500];
    int line_count = 0;
    int i;
    int fewest_index;
    int largest_index;


while (1){

    printf("Menu Options:\n");
    printf("A: Specify the filename to be imported\n");
    printf("B: Display the total number of records in the file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: Quit\n");
    printf("Enter choice: ");
    choice = getchar();
    while (getchar() != '\n');

    switch (choice){ 
    
    case 'A':
    case 'a':
           printf("Input filename: ");
           scanf("%s", filename);
           file = fopen(filename, "r");
           if (file == NULL){
                printf("Error: Could not find or open the file.\n");
                return 1;
           }
           else {
               printf("File successfully loaded.\n");

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
           }
           getchar();
           break;

    case 'B':
    case 'b':
           printf("Total records: %d\n", line_count);
           break;

    case 'C':
    case 'c':
           fewest_index = 0;
           fewest = stepcount[0].steps;
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps < fewest) {
                fewest = stepcount[i].steps;
                fewest_index = i;
           }
           }
           
           printf("Fewest steps: %s %s\n", stepcount[fewest_index].date, stepcount[fewest_index].time);
          
           break;

    case 'D':
    case 'd':
           largest_index = 0;
           largest = stepcount[0].steps;
           for (int i = 0; i < line_count; i++) {
           if (stepcount[i].steps >= largest) {
                largest = stepcount[i].steps;
                largest_index = i;
           }
           }
           
           printf("Largest steps: %s %s\n", stepcount[largest_index].date, stepcount[largest_index].time);

           break;

    case 'E':
    case 'e':
           for (int i = 0; i < line_count; i++){
               sum += stepcount[i].steps;
           }
           printf("Mean step count: %.0f\n", sum/line_count);
           break;

    case 'F':
    case 'f':
    // reference: https://stackoverflow.com/a/53197403
           for (int i = 0; i < line_count; i++){
              if(stepcount[i].steps > 500){
                     counter++;
                     if (counter > max_continuous){
                             max_continuous = counter - 1;
                             start = i - counter + 1;
              }
              }
              else{
              counter = 0;
                     }
           }
           printf("Longest period start: %s %s\n", stepcount[start].date, stepcount[start].time);
           printf("Longest period end: %s %s\n", stepcount[start+max_continuous].date, stepcount[start+max_continuous].time);
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