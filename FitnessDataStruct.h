
#ifndef FITNESS_DATA_STRUCT_H
#define FITNESS_DATA_STRUCT_H

#include <stdio.h>
#include <stdlib.h>

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


#endif // FITNESS_DATA_STRUCT_H