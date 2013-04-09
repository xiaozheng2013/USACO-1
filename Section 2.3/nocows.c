/*
ID: Yiting
LANG: C++
TASK: nocows 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define M 9901
using namespace std;

int N, K, res;
long long d[201][100];

void DP() {
    int i, j, k;
    for (i = 1; i <= K; i++)
        d[1][i] = 1;
    for (i = 2; i <= N; i++) {
        for (j = 1; j <= K; j++) {
            for (k = 1; k < i - 1; k++) {
                d[i][j] += (d[k][j - 1] * d[i - k - 1][j - 1]) % M;
            }
        }
    }
}

main() {

    FILE *fin = fopen("nocows.in", "rb");
    FILE *fout = fopen("nocows.out", "wb");
    fscanf(fin, "%d %d", &N, &K);
    DP();
    res = (d[N][K] - d[N][K - 1]) % M;
    fprintf(fout, "%d\n", (res + M) % M);
    exit(0);
}
