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


int main() {
    char filename[100];
    printf("Input filename:");
    scanf("%s", filename);
    FILE *file = fopen(filename, "r");
    if (file == NULL){
         printf("Error: Could not find or open the file.\n");
         return 1;
         }
    int data_size = 1000;
    char data_line[data_size];
    FitnessData stepcount[1000];
    int line_count = 0;

    if (fgets(data_line, data_size, file)== NULL){
        printf("Error: invalid file");
        return 1;
    }

    while(fgets(data_line, data_size, file)!= NULL){
        char date_token[11];
        char time_token[6];
        int steps_token;
        tokeniseRecord(data_line, ',', date_token, time_token, &steps_token);
        strcpy(stepcount[line_count].date, date_token);
        strcpy(stepcount[line_count].time, time_token);
        stepcount[line_count].steps = steps_token;

        line_count++;
        }
    fclose(file);

    for(int i = 0; i < line_count; i++){
        for(int j = 0; j < line_count; j++){
            if(stepcount[j].steps < stepcount[j+1].steps){
                FitnessData data = stepcount[j];
                stepcount[j] = stepcount[j+1];
                stepcount[j+1] = data;
                // sources : https://www.sanfoundry.com/c-program-sort-array-descending-order/
            }
        }
    }

    strcat(filename, ".tsv");
    FILE *sortedfile = fopen(filename, "w");

    for (int i=0; i<line_count; i++){
        fprintf(sortedfile, "%s\t%s\t%d\n", stepcount[i].date, stepcount[i].time, stepcount[i].steps);
    }
    fclose(sortedfile);
    return 0;
}
