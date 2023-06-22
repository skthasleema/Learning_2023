#include <stdio.h>

int getCharType(char ch) {
    int charType;

    if ((ch >= 'A' && ch <= 'Z')) {
        charType = 1;
    } else if (ch >= 'a' && ch <= 'z') {
        charType = 2;
    } else if (ch >= '0' && ch <= '9') {
        charType = 3;
    } else if (ch >= 32 && ch <= 126) {
        charType = 4;
    } else {
        charType = 5;
    }

    return charType;
}

int main() {
    char character;

    printf("Enter a character: ");
    scanf(" %c", &character);

    int type = getCharType(character);

    switch (type) {
        case 1:
            printf("Type: Uppercase Letter\n");
            break;
        case 2:
            printf("Type: Lowercase Letter\n");
            break;
        case 3:
            printf("Type: Digit\n");
            break;
        case 4:
            printf("Type: Printable Symbol\n");
            break;
        case 5:
            printf("Type: Non-Printable Symbol\n");
            break;
        default:
            printf("Type: Unknown\n");
    }

    return 0;
}
