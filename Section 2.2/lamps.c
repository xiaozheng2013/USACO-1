/*
ID: Yiting
LANG: C++
TASK: lamps 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define NMAX 101
using namespace std;

int N, C, onCount, offCount, cnt;
int light[NMAX + 1];

struct Node {
    int s[NMAX + 1];
} res[NMAX*NMAX], temp;

bool cmp(struct Node n1, struct Node n2) {
    int i;
    for (i = 1; i <= N; i++)
        if (n1.s[i] != n2.s[i])
            return n1.s[i] < n2.s[i];
}

void DFS(struct Node n, int step, int from) {
    int i, j;
    bool c = false;
    struct Node k;
    if (step <= C && (C - step) % 2 == 0) {
        for (i = 1; i <= N; i++)
            if (light[i] != -1 && light[i] != n.s[i])
                goto A;
        res[++cnt] = n;
        for (i = 1; i < cnt; i++) {
            c = true;
            for (j = 1; j <= N; j++)
                if (res[i].s[j] != res[cnt].s[j]) c = false;
            if (c)break;
        }
        if (c)
            cnt--;
    }
A:
    ;
    for (i = from; i <= 4; i++) {
        if (i == 1) {
            k = n;
            for (j = 1; j <= N; j++) k.s[j] = 1 - k.s[j];
        } else if (i == 2) {
            k = n;
            for (j = 1; j <= N; j++)
                if (j % 2) k.s[j] = 1 - k.s[j];
        } else if (i == 3) {
            k = n;
            for (j = 1; j <= N; j++)
                if (j % 2 == 0) k.s[j] = 1 - k.s[j];
        } else if (i == 4) {
            k = n;
            for (j = 1; j <= N; j++)
                if (j % 3 == 1) k.s[j] = 1 - k.s[j];
        }
        DFS(k, step + 1, from + 1);
    }
}

main() {
    int tmp, i, j;
    FILE *fin = fopen("lamps.in", "rb");
    FILE *fout = fopen("lamps.out", "wb");
    fscanf(fin, "%d\n%d", &N, &C);
    memset(light, -1, sizeof (light));
    while (fscanf(fin, "%d", &tmp) && tmp != -1)
        light[tmp] = 1;
    while (fscanf(fin, "%d", &tmp) && tmp != -1)
        light[tmp] = 0;
    for (i = 1; i <= N; i++)
        temp.s[i] = 1;
    DFS(temp, 0, 1);
    if (cnt) {
        sort(res + 1, res + 1 + cnt, cmp);
        for (i = 1; i <= cnt; i++) {
            for (j = 1; j < N; j++) {
                fprintf(fout, "%d", res[i].s[j]);
            }
            fprintf(fout, "%d\n", res[i].s[N]);
        }
    } else {
        fprintf(fout, "IMPOSSIBLE\n");
    }

    exit(0);
}
