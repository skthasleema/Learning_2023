#include <stdio.h>

int isVowel(char ch) {
    int isVowel = 0;

    switch(ch) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            isVowel = 1;
            break;
    }

    return isVowel;
}

int main() {
    char character;

    printf("Enter a character: ");
    scanf(" %c", &character);

    if (isVowel(character)) {
        printf("Vowel\n");
    } else {
        printf("Not Vowel\n");
    }

    return 0;
}
