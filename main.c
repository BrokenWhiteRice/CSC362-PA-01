#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char inputFileName[100], outputFileName[100], first, second;
    FILE *inputFile, *outputFile;
    int inputChar, outputSize = 0, inputSize = 0, nonOutputLetters = 0;

    // User input for file names
    printf("Enter the input file name: ");
    fgets(inputFileName, sizeof(inputFileName), stdin);
    inputFileName[strcspn(inputFileName, "\n")] = 0; // Remove newline character

    printf("Enter the output file name: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);
    outputFileName[strcspn(outputFileName, "\n")] = 0; // Remove newline character

    // User input for two letters
    do {
        printf("Enter two letters separated by a blank space: ");
        scanf(" %c %c", &first, &second);
        while (getchar() != '\n'); // Clear the input buffer
    } while (!isalpha(first) || !isalpha(second) || tolower(first) >= tolower(second));

    // Open files
    inputFile = fopen(inputFileName, "r");
    outputFile = fopen(outputFileName, "w");
    if (inputFile == NULL || outputFile == NULL) {
        perror("Error opening file");
        return 1;
    }





// Calculate and print the report
    double percentageChange = ((double)outputSize / inputSize) * 100;
    printf("Size of %s is: %d\n", inputFileName, inputSize);
    printf("Size of %s is: %d\n", outputFileName, outputSize);
    printf("Letters not output is: %d\n", nonOutputLetters);
    printf("Difference in size is: %.2f%%\n", percentageChange);

    return 0;
}
