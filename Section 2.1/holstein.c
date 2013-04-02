/*
ID: Yiting
LANG: C++
TASK: holstein 
 */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<assert.h>
#define V_MAX_TYPE 26
#define F_MAX_TYPE 16
using namespace std;

int Vtype[V_MAX_TYPE], Vtemp[V_MAX_TYPE];
int Ftype[F_MAX_TYPE][V_MAX_TYPE];
int tmp[V_MAX_TYPE], res[V_MAX_TYPE];
int M, v, g, vnum = 0, tnum = 0;

void solve() {
    int num = (int) pow(2, g), i, k, c, it;
    memset(res, 0, sizeof (res));
    for (i = 1; i < num; i++) {
        k = i, c = 0, tnum = 0;
        memset(Vtemp, 0, sizeof (Vtemp));
        if (k == 1535) {
            c = 0;
        }
        while (k) {
            if (k % 2) {
                for (it = 0; it < v; it++) {
                    Vtemp[it] += Ftype[c][it];
                }
                tmp[tnum++] = c + 1;
            }
            k = k / 2;
            c++;
        }
        for (it = 0; it < v; it++)
            if (Vtemp[it] < Vtype[it])
                goto out;
        if (tnum <= M) {
            if (tnum == M) {
                for (it = 0; it < tnum; it++)
                    if (res[it] < tmp[it])
                        goto out;
            }
            for (it = 0; it < tnum; it++)
                res[it] = tmp[it];
            M = tnum;
        }
out:
        ;
    }
}

main() {
    FILE *fin = fopen("holstein.in", "rb");
    FILE *fout = fopen("holstein.out", "wb");
    int i, j;
    M = INT_MAX;
    fscanf(fin, "%d", &v);
    for (i = 0; i < v; i++)
        fscanf(fin, "%d", &Vtype[i]);
    fscanf(fin, "%d", &g);
    for (i = 0; i < g; i++)
        for (j = 0; j < v; j++)
            fscanf(fin, "%d", &Ftype[i][j]);
    solve();
    fprintf(fout, "%d", M);
    for (i = 0; i < M; i++)
        fprintf(fout, " %d", res[i]);
    fprintf(fout, "\n");
    return 0;
}
