/*
ID: Yiting
LANG: C
TASK: transform
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

void output(char a[N][N], int n);

void Rotate(char array[N][N], char before[N][N], int k, int n) {
    int i, j;
    if (k == 1) {//clockwise 90 degrees
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                array[i][j] = before[(n - 1) - j][i];

    }
    if (k == 2) {//clockwise 180 degrees
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                array[i][j] = before[(n - 1) - i][(n - 1) - j];
    }
    if (k == 3) {//clockwise 270 degrees
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                array[i][j] = before[j][(n - 1) - i];
    }
}

void Reflect(char array[N][N], int n) {
    char before[N][N];
    memcpy(before, array, sizeof (before));
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            array[i][j] = before[i][(n - 1) - j];
}

int check(char a1[N][N], char a2[N][N], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (a1[i][j] != a2[i][j])
                return 0;
    return 1;
}

void output(char a[N][N], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int solve(char before[N][N], char after[N][N], int len) {
    char temp[N][N];
    int i, j;
    memcpy(temp, before, sizeof (temp));
    for (i = 1; i < 4; i++) {//check rotations
        Rotate(temp, before, i, len);
        if (check(temp, after, len)) {
            return i;
        }
    }
    memcpy(temp, before, sizeof (temp));
    Reflect(temp, len); //check reflection
    if (check(temp, after, len)) {
        return 4;
    }
    //check combination
    for (j = 0; j < 3; j++) {
        memcpy(temp, before, sizeof (temp));
        Rotate(temp, before, j + 1, len); //first rotate
        Reflect(temp, len); //then reflect
        if (check(temp, after, len)) {
            return 5;
        }
    }
    if (check(before, after, len)) {
        return 6;
    }
    return 7;
}

main() {
    FILE* fin = fopen("transform.in", "r");
    FILE* fout = fopen("transform.out", "w");
    int len, i;
    char before[N][N], after[N][N];
    fscanf(fin, "%d", &len);
    for (i = 0; i < len; i++)
        fscanf(fin, "%s", before[i]);
    for (i = 0; i < len; i++)
        fscanf(fin, "%s", after[i]);
    int s;
    if (len == 0)
        s = 7;
    else s = solve(before, after, len);
    fprintf(fout, "%d\n", s);

    exit(0);
}