/*
ID: Yiting
LANG: C++
TASK: preface 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum Value {
    I = 0, V, X, L, C, D, M
} Val;

static char ch[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int N[7];

void getNum(int num) {
    if (num >= 1000) {
        N[M]++;
        getNum(num - 1000);
    } else if (num >= 900) {
        N[C]++;
        N[M]++;
        getNum(num - 900);
    } else if (num >= 500) {
        N[D]++;
        getNum(num - 500);
    } else if (num >= 400) {
        N[C]++;
        N[D]++;
        getNum(num - 400);
    } else if (num >= 100) {
        N[C]++;
        getNum(num - 100);
    } else if (num >= 90) {
        N[X]++;
        N[C]++;
        getNum(num - 90);
    } else if (num >= 50) {
        N[L]++;
        getNum(num - 50);
    } else if (num >= 40) {
        N[X]++;
        N[L]++;
        getNum(num - 40);
    } else if (num >= 10) {
        N[X]++;
        getNum(num - 10);
    } else if (num >= 9) {
        N[I]++;
        N[X]++;
        getNum(num - 9);
    } else if (num >= 5) {
        N[V]++;
        getNum(num - 5);
    } else if (num >= 4) {
        N[I]++;
        N[V]++;
        getNum(num - 4);
    } else if (num >= 1) {
        N[I]++;
        getNum(num - 1);
    }
}

main() {
    int n, i;
    memset(N, 0, sizeof (N));
    FILE *fin = fopen("preface.in", "rb");
    FILE *fout = fopen("preface.out", "wb");
    fscanf(fin, "%d", &n);
    for (i = 1; i <= n; i++)
        getNum(i);
    for (i = 0; i < 7; i++)
        if (N[i] != 0)
            fprintf(fout, "%c %d\n", ch[i], N[i]);
    exit(0);
}
