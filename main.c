//Quan Pham
//CSC 362
//Richard Fox
//Programming Assignment 1
//This program is used to test the difference between 2 file by comparing each of their character and lengths
//Firstly, we ask the user to enter 2 files
//After that, we put 2 files through a while loop
//Then, we have another if - else statement to compare 2 files' length
#include <stdio.h>
#include <ctype.h>

int main() {
    char input_filename[20], output_filename[20];//Store the file name
    char first, second;
    int input_size = 0, output_size = 0, letters_not_output = 0;
    FILE *input_file, *output_file;//File pointers for the two files

    // Get user input for filenames and letters
    printf("Enter the input file name: ");
    scanf("%s", input_filename);

    printf("Enter the output file name: ");
    scanf("%s", output_filename);
//To enter b,p and e,x
    do {
        printf("Enter two letters separated by a blank space: ");
        scanf(" %c %c", &first, &second);
    } while (!isalpha(first) || !isalpha(second) || tolower(first) > tolower(second));

    // Open files for reading and writing
    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error opening input file!\n");
        return 1;
    }
    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        printf("Error opening output file!\n");
        fclose(input_file);
        return 1;
    }

    // Process characters
    char ch;
    // read the file
    while ((ch = fgetc(input_file)) != EOF) {
        input_size++;

        // make sure it's letter
        if (isalpha(ch)) {
            char ch_lower = tolower(ch);
            if (ch_lower >= tolower(first) && ch_lower <= tolower(second)) {
                fputc(ch, output_file);
                output_size++;
            } else {
                letters_not_output++;
            }
        } else if (isspace(ch) || ispunct(ch)) {
            fputc(ch, output_file);
            output_size++;
        }
    }

    // Close files and print report
    fclose(input_file);
    fclose(output_file);

    double percentage_change = (double)output_size / input_size * 100;

    printf("\nSize of %s is: %d\n", input_filename, input_size);
    printf("Size of %s is: %d\n", output_filename, output_size);
    printf("Letters not output is: %d\n", letters_not_output);
    printf("Difference in size is: %.2f%%\n", percentage_change);

    return 0;
}

//Enter the input file name:p1in1.txt
//        Enter the output file name:p1out1.txt
//        Enter two letters separated by a blank space: b p
//
//Size of p1in1.txt is: 158
//Size of p1out1.txt is: 111
//Letters not output is: 47
//Difference in size is: 70.25%

//Enter the input file name:p1in1.txt
//        Enter the output file name:p1out1.txt
//        Enter two letters separated by a blank space: e x
//
//Size of p1in1.txt is: 158
//Size of p1out1.txt is: 144
//Letters not output is: 14
//Difference in size is: 91.14%

//Enter the input file name:p2in2.txt
//        Enter the output file name:p2out2.txt
//        Enter two letters separated by a blank space: b p
//
//Size of p2in2.txt is: 728
//Size of p2out2.txt is: 504
//Letters not output is: 207
//Difference in size is: 69.23%

//Enter the input file name:p2in2.txt
//        Enter the output file name:p2out2.txt
//        Enter two letters separated by a blank space: e x
//
//Size of p2in2.txt is: 728
//Size of p2out2.txt is: 603
//Letters not output is: 108
//Difference in size is: 82.83%




