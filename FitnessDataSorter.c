#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"



int main() {
    char filename[1000];
    printf("Input filename:");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL){
         printf("Error: invalid file\n");
         return 1;
         }
    int data_size = 1500;
    char data_line[data_size];
    FitnessData stepcount[1500];


    int line_count = 0;
    while(fgets(data_line, data_size, file)!= NULL){
        char date_token[11];
        char time_token[6];
        int steps_token;
        tokeniseRecord(data_line, ',', date_token, time_token, &steps_token);
        if (strlen(date_token) != 10||strlen(time_token) != 5|| steps_token < 0){
        printf("Error: invalid file\n");
        return 1;
        }
        else if (file == NULL){
          printf("Error: invalid file\n");
        return 1;  
        }
        strcpy(stepcount[line_count].date, date_token);
        strcpy(stepcount[line_count].time, time_token);
        stepcount[line_count].steps = steps_token;
        line_count++;

        }
    fclose(file);

    qsort(stepcount, line_count, sizeof(FitnessData), ordering);

    strcat(filename, ".tsv");
    FILE *sortedfile = fopen(filename, "w");

    for (int i=0; i < line_count; i++){
        fprintf(sortedfile, "%s\t%s\t%d\n", stepcount[i].date, stepcount[i].time, stepcount[i].steps);
    }
    fclose(sortedfile);
    return 0;
}
