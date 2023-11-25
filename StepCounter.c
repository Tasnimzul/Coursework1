#include "FitnessDataStruct.h"

int main(){

    FILE *file = fopen("FitnessData_2023.csv", "r");
    
    char choice;
    char filename[20];
    int line_count = 0;
    int fewest;

    int data_size = 1000;
    char data_line[data_size];
    FITNESS_DATA stepcount[1000];
    char str_steps_token[15];

     while(fgets(data_line, data_size, file)!= NULL){
        char date_token[11];
        char time_token[6];
        char str_steps_token[15];
        tokeniseRecord(data_line, ",", date_token, time_token, str_steps_token);
        line_count++;
     }


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
         printf("Input filename:");
         scanf("%s", filename);
         FILE *file = fopen(filename, "r");
         if (file == NULL){
         perror("Error: could not open file\n");
         return 1;
         }
         break;

    case 'B':
    case 'b':
         printf("Total records: %d\n", line_count);
         break;

    case 'C':
    case 'c':
         fewest = atoi(str_steps_token);
         for (int i = 1; i <= line_count; i++){
            while(fgets(data_line, data_size, file)!= NULL){
            if (stepcount[i].steps < fewest){
                fewest = stepcount[i].steps;
            }
            }
         }
         printf("Your fewest stepcount is %d\n", fewest);
         break;

    case 'D':
    case 'd':
         break;

    case 'E':
    case 'e':
         break;

    case 'F':
    case 'f':
         break;

    case 'Q':
    case 'q':
         break;

}
}