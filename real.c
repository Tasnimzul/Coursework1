#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

int main() {

FILE *file = fopen("FitnessData_2023.csv", "r");
    
    char choice;
    char filename[100];
    int fewest;
    int largest;
    int sum = 0;

    int data_size = 1000;
    char data_line[data_size];
    FITNESS_DATA stepcount[1000];

    int line_count = 0;
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
           printf("Input filename:");
           scanf("%s", filename);
           FILE *file = fopen(filename, "r");
           if (file == NULL){
                printf("Error: Could not find or open the file.\n");
                return 1;
           }
           else {
                printf("File successfully loaded.\n");
           }
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
           break;

    case 'Q':
    case 'q':
           return 0;
           break;

    default :
           printf("Invalid choice. Try again.\n");
           return 0;

}
}
  