#include <ctype.h>
#include <fcntl.h>
#include <stdbool.h>
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

void mx_printint(int n) {
    if (n == 0) {
        mx_printchar('0');
        return;
    }
    int buf = n;
    int len = 0;
    while (n != 0) {
        n /= 10;
        len++;
    }
    n = buf;
    if (buf < 0) {
        len++;
        n *= -1;
    }
    char res[len];
    int bufl = len;
    while (n != 0) {
        res[len - 1] = (char)(n % 10 + '0');
        len--;
        n /= 10;
    }
    if (buf < 0) res[0] = '-';
    for (int i = 0; i < bufl; ++i) {
        mx_printchar(res[i]);
    }
}

void mx_printerr(const char *s) { write(2, s, mx_strlen(s)); }
void mx_printstr(const char *s) { write(1, s, mx_strlen(s)); }

int main(int argc, char *argv[]) {
    if (argc != 3) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printchar('\n');

    } else {
        char *strCipher = argv[1];
        char *keyword = argv[2];
        int keyInt[strlen(keyword)];
        int countKeyInt = 0;
        for (int i = 0; i < strlen(keyword); i++) {
            if (isupper(keyword[i]) == 1) {
                keyInt[i] = keyword[i] - 65;
            } else if (islower(keyword[i]) == 1) {
                keyInt[i] = keyword[i] - 97;
            }
            mx_printint(keyInt[i]);
            mx_printchar('\n');
        }

        for (int j = 0; j < strlen(strCipher); j++) {
            if (isalpha(strCipher[j]) == 1) {
                if (strCipher[j] - keyInt[countKeyInt] < 65 &&
                    isupper(strCipher[j]) == 1) {
                    mx_printchar((strCipher[j] + 26) - keyInt[countKeyInt]);
                } else if (strCipher[j] - keyInt[countKeyInt] < 97 &&
                           islower(strCipher[j]) == 1) {
                    mx_printchar((strCipher[j] + 26) - keyInt[countKeyInt]);
                } else {
                    mx_printchar(strCipher[j] - keyInt[countKeyInt]);
                }
                countKeyInt++;
                if (countKeyInt == strlen(keyword)) {
                    countKeyInt = 0;
                }
            } else {
                mx_printchar(strCipher[j]);
            }
        }
        mx_printchar('\n');
    }
}