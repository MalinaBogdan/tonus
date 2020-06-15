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
    char tempLetter[20];
    int a = 0;

    if (argc != 2) {
        mx_printerr("usage: ");
        mx_printerr(argv[0]);
        mx_printchar('\n');

    } else {
        char *strMorse = argv[1];
        for (int i = 0; i < 26; i++) {
            mx_printstr("ROT");
            mx_printint(i);
            mx_printstr("  -  ");
            for (int j = 0; j < mx_strlen(strMorse); j++) {
                if (isalpha(strMorse[j]) == 1) {
                    if (strMorse[j] + i > 90 && isupper(strMorse[j]) == 1) {
                        mx_printchar((strMorse[j] - 26) + i);
                    } else if (strMorse[j] + i > 122 &&
                               islower(strMorse[j]) == 1) {
                        mx_printchar((strMorse[j] - 26) + i);
                    } else {
                        mx_printchar(strMorse[j] + (i));
                    }
                } else {
                    mx_printchar(strMorse[j]);
                }
            }
            mx_printchar('\n');
            mx_printchar('\n');
        }
    }
    mx_printchar('\n');
}
