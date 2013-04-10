/*
ID: Yiting
LANG: C++
TASK: money 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

int V, N, res;
int coins[25];
long long dp[10001];

void DP() {
    int i, j;
    dp[0] = 1;
    for (i = 0; i < V; i++)
        for (j = 0; j <= N; j++)
            dp[j] += j - coins[i] >= 0 ? dp[j - coins[i]] : 0;
}

void DFS(int cur, int c) {//time out...
    int i;
    if (cur == N) {
        res++;
        return;
    }
    if (cur > N)
        return;
    for (i = c; i < V; i++) {
        cur += coins[i];
        DFS(cur, i);
        cur -= coins[i];
    }
}

main() {
    FILE *fin = fopen("money.in", "rb");
    FILE *fout = fopen("money.out", "wb");
    int i;
    fscanf(fin, "%d %d", &V, &N);
    for (i = 0; i < N; i++)
        fscanf(fin, "%d", &coins[i]);
    //DFS(0, 0);
    DP();
    //fprintf(fout, "%d\n", res);
    fprintf(fout, "%lld\n", dp[N]);
    exit(0);
}
