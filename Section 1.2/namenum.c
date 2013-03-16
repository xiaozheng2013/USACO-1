/*
ID: Yiting
LANG: C
TASK: namenum
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LEN 10
#define MAX 5000

char getNumber(char c) {
    if (c == 'Q' || c == 'Z')
        return '1';
    if (c == 'A' || c == 'B' || c == 'C')
        return '2';
    if (c == 'D' || c == 'E' || c == 'F')
        return '3';
    if (c == 'G' || c == 'H' || c == 'I')
        return '4';
    if (c == 'J' || c == 'K' || c == 'L')
        return '5';
    if (c == 'M' || c == 'N' || c == 'O')
        return '6';
    if (c == 'P' || c == 'R' || c == 'S')
        return '7';
    if (c == 'T' || c == 'U' || c == 'V')
        return '8';
    if (c == 'W' || c == 'X' || c == 'Y')
        return '9';
}

int compare(char* input, char* names) {
    int len1 = strlen(input), len2 = strlen(names), i;
    if (len1 != len2)
        return 0;
    for (i = 0; i < len2; i++) {
        if (input[i] != getNumber(names[i]))
            return 0;
    }
    return 1;
}

main() {
    FILE* fin = fopen("namenum.in", "r");
    FILE* ftree = fopen("dict.txt", "r");
    FILE* fout = fopen("namenum.out", "w");
    int i, k = 0;
    char input[LEN];
    char names[MAX][LEN] = {};
    fscanf(fin, "%s", input);
    for (i = 0; i < MAX; i++) {
        fscanf(ftree, "%s", names[i]);
        if (compare(input, names[i])) {
            k = 1;
            fprintf(fout, "%s\n", names[i]);
        }
    }
    if (k == 0)
        fprintf(fout, "NONE\n");
    exit(0);
}