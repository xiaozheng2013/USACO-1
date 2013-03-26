/*
ID: Yiting
LANG: C++
TASK: numtri 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

int tri[1000][1000];

main() {

    FILE* fin = fopen("numtri.in", "rb");
    FILE* fout = fopen("numtri.out", "wb");
    int n, i, j;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j <= i; j++) {
            fscanf(fin, "%d", &tri[i][j]);
        }
    }
    for (i = n - 1; i >= 1; i--) {
        for (j = 0; j <= i; j++) {
            tri[i - 1][j] += MAX(tri[i][j], tri[i][j + 1]);
        }
    }
    fprintf(fout, "%d\n", tri[0][0]);

    fclose(fin);
    fclose(fout);
    exit(0);
}
