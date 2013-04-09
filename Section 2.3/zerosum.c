/*
ID: Yiting
LANG: C++
TASK: zerosum 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
FILE *fin = fopen("zerosum.in", "rb");
FILE *fout = fopen("zerosum.out", "wb");
int N;
int ops[10];

void output() {
    int i;
    for (i = 1; i < N; i++)
        fprintf(fout, "%d%c", i, ops[i]);
    fprintf(fout, "%d\n", N);
}

void DFS(int n, int sum, int cur) {
    if (n == N) {
        if (sum + cur == 0) {
            output();
        }
        return;
    }
    int next = n + 1;
    ops[n] = ' ';
    DFS(next, sum, cur * 10 + (cur > 0 ? next : -next));
    ops[n] = '+';
    DFS(next, cur + sum, next);
    ops[n] = '-';
    DFS(next, cur + sum, -next);
}

main() {
    fscanf(fin, "%d", &N);
    DFS(1, 0, 1);
    exit(0);
}
