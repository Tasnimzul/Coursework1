#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;


void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
    if (ptr != NULL) {
        strcpy(time, ptr);
        ptr = strtok(NULL, &delimiter);
    if (ptr != NULL) {
        *steps = atoi(ptr);
            }
        }
    }
}

int ordering(const void *x, const void *y){
    return(*((FitnessData *)y)).steps - (*((FitnessData *)x)).steps;
}
//https://www.youtube.com/watch?v=rHoOWG6Ihs4 used as a reference in using qsort

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
        if (date_token == NULL||time_token == NULL|| steps_token < 0 || steps_token == NULL){
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
