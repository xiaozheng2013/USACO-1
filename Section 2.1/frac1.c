/*
ID: Yiting
LANG: C++
TASK: frac1 
 */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;

int n;
FILE *fin = fopen("frac1.in", "rb");
FILE *fout = fopen("frac1.out", "wb");

void frac(int m1, int d1, int m2, int d2) {
    if (d1 + d2 > n)
        return;
    frac(m1, d1, m1 + m2, d1 + d2);
    fprintf(fout, "%d/%d\n", m1 + m2, d1 + d2);
    frac(m1 + m2, d1 + d2, m2, d2);
}

main() {

    fscanf(fin, "%d", &n);
    fprintf(fout, "0/1\n");
    frac(0, 1, 1, 1);
    fprintf(fout, "1/1\n");
    return 0;
}
