#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void mx_printchar(char c);
void mx_printchar(char c) { write(1, &c, 1); }

int mx_strlen(const char *s) {
    int size = 0;
    while (*s++) {
        ++size;
    }
    return size;
}

void mx_printerr(const char *s) { write(2, s, mx_strlen(s)); }

typedef struct {
    char *code;
    char letter;
} para;

para arrayMorseCode[29];
char *arrayDotsDashes[29] = {
    "AAAAA", "AAAAB", "AAABA", "AAABB", "AABAA", "AABAB", "AABBA", "AABBB",
    "ABAAA", "ABAAB", "ABABA", "ABABB", "ABBAA", "ABBAB", "ABBBA", "ABBBB",
    "BAAAA", "BAAAB", "BAABA", "BAABB", "BABAA", "BABAB", "BABBA", "BABBB",
    "BBAAA", "BBAAB", "BBABA", "BBABB", "BBBAA"};

void structureFilling() {
    for (int i = 0; i < 29; i++) {
        if (i == 26) {
            arrayMorseCode[i].letter = ' ';
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else if (i == 27) {
            arrayMorseCode[i].letter = '.';
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else if (i == 28) {
            arrayMorseCode[i].letter = ',';
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else {
            arrayMorseCode[i].letter = i + 65;
            arrayMorseCode[i].code = arrayDotsDashes[i];
        }
        // mx_printchar(arrayMorseCode[i].letter);
        // mx_printchar(' ');
        // mx_printerr(arrayMorseCode[i].code);
        // mx_printchar('\n');
    }
}
int main(int argc, char *argv[]) {
    char tempLetter[6];
    int a = 0;

    // if (argc != 2) {
    //     mx_printerr("usage: ");
    //     mx_printerr(argv[0]);
    //     mx_printchar('\n');

    // } else {
    int fd = open(argv[1], O_RDONLY);
    structureFilling();
    char *strCipher = argv[1];

    mx_printchar('\n');
    for (int i = 0; i < mx_strlen(strCipher); i++) {
        if (isalpha(strCipher[i]) == 1) {
            if (isupper(strCipher[i]) == 1) {
                tempLetter[a] = 'B';
            } else if (islower(strCipher[i]) == 1) {
                tempLetter[a] = 'A';
            }

            a++;
        }
        if (a == 5) {
            for (int j = 0; j < 29; j++) {
                if (strcmp(tempLetter, arrayMorseCode[j].code) == 0) {
                    mx_printchar(arrayMorseCode[j].letter);
                }
            }

            a = 0;
        }
    }

    mx_printchar('\n');
    mx_printchar('\n');
    int c = 0;

    printf("%d", a);
}