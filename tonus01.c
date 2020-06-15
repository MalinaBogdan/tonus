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

para arrayMorseCode[54];
char *arrayDotsDashes[54] = {
    "Z", "Y", "X", "W", "V", "U", "T", "S", "R", "Q", "P", "O", "N", "M",
    "L", "K", "J", "I", "H", "G", "F", "E", "D", "C", "B", "A", " ", ".",
    "z", "y", "x", "w", "v", "u", "t", "s", "r", "q", "p", "o", "n", "m",
    "l", "k", "j", "i", "h", "g", "f", "e", "d", "c", "b", "a"};

void structureFilling() {
    for (int i = 0; i < 54; i++) {
        if (i == 26) {
            arrayMorseCode[i].letter = ' ';
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else if (i == 27) {
            arrayMorseCode[i].letter = '.';
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else if (i < 26) {
            arrayMorseCode[i].letter = i + 65;
            arrayMorseCode[i].code = arrayDotsDashes[i];
        } else {
            arrayMorseCode[i].letter = i + 69;
            arrayMorseCode[i].code = arrayDotsDashes[i];
        }
    }
}
int main(int argc, char *argv[]) {
    char tempLetter[20];
    int a = 0;

    if (argc != 2) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printchar('\n');

    } else {
        structureFilling();
        char *strMorse = argv[1];
        for (int i = 0; i < mx_strlen(strMorse); i++) {
            tempLetter[i - a] = strMorse[i];
            for (int j = 0; j < 54; j++) {
                if (strcmp(tempLetter, arrayMorseCode[j].code) == 0) {
                    mx_printchar(arrayMorseCode[j].letter);
                    for (int m = 0; m < 20; m++) {
                        a = i + 1;
                        tempLetter[m] = '\0';
                    }
                }
            }
        }
    }
    mx_printchar('\n');
}