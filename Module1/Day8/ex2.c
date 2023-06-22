#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void copyFile(FILE *sourceFile, FILE *destinationFile, int option) {
    char ch;

    while ((ch = fgetc(sourceFile)) != EOF) {
        switch (option) {
            case 1: // Upper case
                fputc(toupper(ch), destinationFile);
                break;
            case 2: // Lower case
                fputc(tolower(ch), destinationFile);
                break;
            case 3: // Sentence case
                if (ch == '\n' || ch == '.') {
                    fputc(ch, destinationFile);
                    ch = fgetc(sourceFile);
                    if (ch != ' ' && ch != '\n' && ch != EOF) {
                        fputc(toupper(ch), destinationFile);
                        continue;
                    }
                }
                fputc(tolower(ch), destinationFile);
                break;
            default: // Normal copy
                fputc(ch, destinationFile);
                break;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp [option] source_file destination_file\n");
        return 1;
    }

    char *optionStr = argv[1];
    char *sourceFileName = argv[2];
    char *destinationFileName = argv[3];
    int option = 0;

    if (optionStr[0] == '-') {
        switch (optionStr[1]) {
            case 'u':
                option = 1; // Upper case
                break;
            case 'l':
                option = 2; // Lower case
                break;
            case 's':
                option = 3; // Sentence case
                break;
            default:
                printf("Invalid option.\n");
                printf("Usage: ./cp [option] source_file destination_file\n");
                return 1;
        }
    }

    FILE *sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        printf("Unable to open the source file.\n");
        return 1;
    }

    FILE *destinationFile = fopen(destinationFileName, "w");
    if (destinationFile == NULL) {
        printf("Unable to create the destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    copyFile(sourceFile, destinationFile, option);

    printf("File copied successfully.\n");

    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
