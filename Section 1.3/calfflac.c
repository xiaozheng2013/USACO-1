/*
ID: Yiting
LANG: C
TASK: calfflac 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<assert.h>
#include<ctype.h>
#define MAX 20000
#define CHARACTER 82

int f = 0, t = 0;

int Min(int a, int b) {
    return a < b ? a : b;
}

int palindromes(char* array) {
    int len_array = strlen(array), len_newArray = len_array << 1, i;
    char newArray[len_newArray + 1];
    newArray[0] = '$';
    newArray[1] = '#';
    for (i = 1; array[i] != '\0'; i++) {
        newArray[(i << 1)] = tolower(array[i]);
        newArray[(i << 1) + 1] = '#';
    }
    newArray[len_newArray] = '\0';
    int mx = 0, id = 0, result_len = 0, result_id = 0;
    int p[len_newArray];
    for (i = 1; i < len_newArray; i++) {
        if (i < mx) {
            p[i] = Min(p[2 * id - i], mx - i);
        } else {
            p[i] = 1;
        }
        while (newArray[i - p[i]] == newArray[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] > mx) {
            mx = i + p[i];
            id = i;
        }
        if (p[i] > result_len) {
            result_len = p[i];
            result_id = i;
        }
    }
    result_len--;
    f = (result_id - result_len) / 2 + 1;
    t = f + result_len;
}

main() {
    FILE* fin = fopen("calfflac.in", "rb");
    FILE* fout = fopen("calfflac.out", "wb");
    char origin[MAX], pure[MAX];
    int len_origin = 0, i = 0, len_pure = 1; //start from 1

    while (fscanf(fin, "%c", &origin[i]) != EOF)
        i++;

    len_origin = strlen(origin);
    pure[0] = ' ';
    int positions[len_origin];
    for (i = 0; i < len_origin; i++) {
        if (isalpha(origin[i])) {
            positions[len_pure] = i;
            pure[len_pure++] = origin[i];
        }
    }
    pure[len_pure] = '\0';
    palindromes(pure);
    fprintf(fout, "%d\n", t - f);
    for (i = positions[f]; i <= positions[t - 1]; i++) {
        fprintf(fout, "%c", origin[i]);
    }
    fprintf(fout, "\n");
    fclose(fin);
    fclose(fout);
    exit(0);
}
