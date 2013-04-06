/*
ID: Yiting
LANG: C++
TASK: subset 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n, res, addUpTo;
int arr[50][3000];

void solve() {
    int i, j;
    arr[1][1] = 1;
    for (i = 2; i <= n; i++)
        for (j = 1; j <= addUpTo; j++) {
            arr[i][j] = arr[i - 1][j];
            if (j - i >= 1)
                arr[i][j] += arr[i - 1][j - i];
        }
}

main() {
    FILE *fin = fopen("subset.in", "rb");
    FILE *fout = fopen("subset.out", "wb");
    fscanf(fin, "%d", &n);
    addUpTo = ((1 + n) * n) / 4;
    if (((1 + n) * n) % 4 == 0)
        solve();
    else
        arr[n][addUpTo] = 0;
    fprintf(fout, "%d\n", arr[n][addUpTo]);
    exit(0);
}
