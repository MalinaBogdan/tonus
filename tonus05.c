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
    char codeGorizontal;
    char codeVertical;
    char letter;
} para;
para arrayDotsDashes[6][6];

void structureFilling() {
    int count = 0;
    int countInt = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (count > 25) {
                arrayDotsDashes[i][j].letter = '0' + countInt;
                arrayDotsDashes[i][j].codeGorizontal = 'A' + i;
                arrayDotsDashes[i][j].codeVertical += 'A' + j;
                countInt++;
                mx_printchar(' ');

            } else {
                arrayDotsDashes[i][j].letter = 'A' + count;
                arrayDotsDashes[i][j].codeGorizontal = 'A' + i;
                arrayDotsDashes[i][j].codeVertical += 'A' + j;
                count++;

                mx_printchar(' ');
            }
            // mx_printchar(arrayDotsDashes[i][j].codeGorizontal);
            // mx_printchar(arrayDotsDashes[i][j].codeVertical);
            mx_printchar(arrayDotsDashes[i][j].letter);
        }

        mx_printchar('\n');
    }
}
int main(int argc, char *argv[]) {
    char *strCipher = argv[1];
    char tempLetter[20];
    char tempLetter1[20];
    int s = 0;
    structureFilling();
    for (int a = 0; a < strlen(strCipher); a++) {
        if (isalpha(strCipher[a]) == 1) {
            if ((a + s) % 2 == 0) {
                for (int i = 0; i < 6; i++) {
                    for (int j = 0; j < 6; j++) {
                        if (strCipher[a + 1] ==
                                arrayDotsDashes[i][j].codeVertical &&
                            strCipher[a] ==
                                arrayDotsDashes[i][j].codeGorizontal) {
                            mx_printchar(arrayDotsDashes[i][j].letter);
                        }
                    }
                }
            }
        } else {
            mx_printchar(strCipher[a]);
            s++;
        }
    }
    mx_printchar('\n');
}

/*
 for (int k = 0; k < strlen(strCipher); k++) {
        if (isalpha(strCipher[k]) == 1) {
            tempLetter[k - a] = strCipher[k];
        }

        if (strCipher[k] == ' ') {
            mx_printerr(tempLetter);
            mx_printchar('\n');
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 6; j++) {
                    if (tempLetter[coca] ==
                            arrayDotsDashes[i][j].codeVertical &&
                        tempLetter[coca + 1] ==
                            arrayDotsDashes[i][j].codeGorizontal) {
                        mx_printchar(arrayDotsDashes[i][j].letter);
                        mx_printchar('\n');
                        coca = coca + 2;
                        printf("%d", coca);
                    } else {
                        // mx_printerr(strCipher);
                        // mx_printchar('\n');
                    }
                }
            }

            a = k + 1;
            for (int m = 0; m < 20; m++) {
                tempLetter[m] = '\0';
            }
            mx_printchar(strCipher[k]);
        }
    }
    */