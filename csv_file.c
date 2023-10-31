#include <stdio.h>
int main() {
    char filename [] = "Fitness_Data";
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("");
        return 1;
        }
        fclose(file);
        return 0;
        }