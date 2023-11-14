#include "FitnessDataStruct.h"

int main(){

    FILE *file = fopen("FitnessData_2023.csv", "r");
    
    char choice;
    char filename;

    printf("A: Insert filename to be imported\n");
    printf("B: View total number of records\n");
    printf("C: View time and date of your fewest steps\n");
    printf("D: View time and date of your highest steps\n");
    printf("E: View your mean steps count\n");
    printf("F: View longest continuous period for step count > 500\n");
    printf("Q: Exit the program\n");
    choice = getchar();
    while (getchar() != '\n');
    switch (choice){
     
    case 'A':
    case 'a':
     printf("Input filename:\n");
     scanf("%s", filename);
     if (file == NULL){
        perror("Error: could not open file\n");
        return 1;
    }

    }
}