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
    
    
}