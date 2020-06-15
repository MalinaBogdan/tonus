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

// typedef struct {
//     char codeGorizontal;
//     char codeVertical;
//     char letter;
// } para;

// void structureFilling(char *a) {
//     int count = 0;
//     int countInt = 0;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 20; j++) {
//             if (((j + i) % 6 == 0) || ((j - i) % 6 == 0)) {
//                 arrayDotsDashes[i][j] = '0';
//             } else
//                 arrayDotsDashes[i][j] = '.';

//             mx_printchar(' ');
//             mx_printchar(arrayDotsDashes[i][j]);
//         }

//         mx_printchar('\n');
//     }
// }
int main(int argc, char *argv[]) {
    char *strCipher = argv[1];
    char arrayDotsDashes[4][strlen(argv[1])];
    char tempLetter[20];
    char tempLetter1[20];
    int s = 0;

    int count = 0;
    int countInt = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < strlen(argv[1]); j++) {
            if (((j + i) % 6 == 0) || ((j - i) % 6 == 0)) {
                arrayDotsDashes[i][j] = strCipher[s];
                s++;
            } else
                arrayDotsDashes[i][j] = '+';
        }

        // mx_printchar('\n');
    }
    int bool = 0;
    for (int j = 0; j < strlen(argv[1]); j++) {
        for (int i = 0; i < 4; i++) {
            if (arrayDotsDashes[i][j] != '+') {
                mx_printchar(arrayDotsDashes[i][j]);
            }
        }
    }
    mx_printchar('\n');
}