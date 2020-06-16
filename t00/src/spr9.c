#include <string.h>
#include <unistd.h>

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

para arrayMorseCode[26];
char *arrayDotsDashes[26] = {
    ".-",   "-...", "-.-.", "-..",  ".",   "..-.", "--.",  "....", "..",
    ".---", "-.-",  ".-..", "--",   "-.",  "---",  ".--.", "--.-", ".-.",
    "...",  "-",    "..-",  "...-", ".--", "-..-", "-.--", "--.."};

void structureFilling() {
    for (int i = 0; i < 26; i++) {
        arrayMorseCode[i].letter = i + 65;
        arrayMorseCode[i].code = arrayDotsDashes[i];
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printchar('\n');

    } else {
        structureFilling();
        char tempLetter[5];
        int a = 0;
        char *strMorse = argv[1];
        int bool = 1;

        for (int i = 0; i < mx_strlen(strMorse); i++) {
            if (strMorse[i] != ' ' && strMorse[i] != '.' &&
                strMorse[i] != '-') {
                mx_printerr("usage: ");
                mx_printerr(argv[0]);
                mx_printerr(" \"str\" ");
                mx_printchar('\n');
                bool = 0;
            }
        }

        for (int i = 0; i < mx_strlen(strMorse); i++) {
            if (bool != 0) {
                // remember the characters for one word
                if (strMorse[i] != ' ') {
                    tempLetter[i - a] = strMorse[i];
                }
                // dot or not
                if ((strMorse[i] == '.' && strMorse[i + 1] == '.' &&
                     strMorse[i + 2] == '.' && strMorse[i + 3] == '.' &&
                     strMorse[i + 4] == '.')) {
                    // look for the character before the point
                    if (strMorse[i] == '.' && strMorse[i + 1] == '.' &&
                        strMorse[i + 2] == '.' && strMorse[i + 3] == '.' &&
                        strMorse[i + 4] == '.' && strMorse[i + 5] == '.' &&
                        strMorse[i + 6] == '.' && strMorse[i + 7] == '.') {
                        mx_printchar('S');
                        mx_printchar('.');
                    } else if (strMorse[i] == '.' && strMorse[i + 1] == '.' &&
                               strMorse[i + 2] == '.' &&
                               strMorse[i + 3] == '.' &&
                               strMorse[i + 4] == '.' &&
                               strMorse[i + 5] == '.' &&
                               strMorse[i + 6] == '.') {
                        mx_printchar('I');
                        mx_printchar('.');
                    } else
                        mx_printchar('.');
                    // clear tempLetter
                    a = i + 1;
                    for (int m = 0; m < 4; m++) {
                        tempLetter[m] = '\0';
                    }

                    i += 4;
                }
                // print letter
                if (strMorse[i] == ' ' || (i + 1 == mx_strlen(strMorse))) {
                    for (int j = 0; j < 26; j++) {
                        if (strcmp(tempLetter, arrayMorseCode[j].code) == 0) {
                            mx_printchar(arrayMorseCode[j].letter);
                        }
                    }
                    a = i + 1;
                    for (int m = 0; m < 4; m++) {
                        tempLetter[m] = '\0';
                    }  // space or not
                    if ((strMorse[i] == ' ' && strMorse[i + 1] == ' ' &&
                         strMorse[i + 2] == ' ' && strMorse[i + 3] == ' ' &&
                         strMorse[i + 4] == ' ' && strMorse[i + 5] == ' ' &&
                         strMorse[i + 6] == ' ')) {
                        mx_printchar(' ');
                    }
                }
            }
        }
        mx_printchar('\n');
    }
}