/*
ID: Yiting
LANG: C++
TASK: rect1 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<limits.h>
#define MAX(A,B) (A)>(B)?(A):(B) 
#define MIN(A,B) (A)<(B)?(A):(B) 
#define CMAX 2600
#define DEBUG 0
using namespace std;

#if DEBUG
FILE *fin = fopen("test.in", "rb");
FILE *fout = fopen("test.out", "wb");
#else
FILE *fin = fopen("rect1.in", "rb");
FILE *fout = fopen("rect1.out", "wb");
#endif

int a, b, N, currentLevel;
int res[CMAX];

typedef struct Grid {
    int l, d, r, u;
    int color;
    int level;
    int size;
    Grid() {
        color = 0;
    }
} grid;

grid g[1200];

void split(int l, int d, int r, int u, int level) {
    if (level > N) {
        g[currentLevel].size += (u - d)*(r - l);
        return;
    }
    if (l == r || d == u) return;
    if (l < g[level].l) {
        split(l, MIN(d, g[level].u), MIN(r, g[level].l), MIN(u, g[level].u), level + 1);
    }
    if (d < g[level].d) {
        split(MAX(l, g[level].l), d, MAX(g[level].l, r), MIN(g[level].d, u), level + 1);
    }
    if (r > g[level].r) {
        split(MAX(l, g[level].r), MAX(g[level].d, d), r, MAX(g[level].d, u), level + 1);
    }
    if (u > g[level].u) {
        split(MIN(l, g[level].r), MAX(d, g[level].u), MIN(r, g[level].r), u, level + 1);
    }
}

main() {
    fscanf(fin, "%d %d %d", &a, &b, &N);
    for (int i = 1; i <= N; i++) {
        fscanf(fin, "%d %d %d %d %d", &g[i].l, &g[i].d,
                &g[i].r, &g[i].u, &g[i].color);
    }
    g[0].color = 1;
    g[0].size = a*b;
    for (int i = N; i >= 1; i--) {
        currentLevel = i;
        split(g[i].l, g[i].d, g[i].r, g[i].u, i + 1);
        g[0].size -= g[i].size;
        res[g[i].color] += g[i].size;
    }
    res[g[0].color] += g[0].size;
    for (int i = 0; i < CMAX; i++)
        if (res[i])
            fprintf(fout, "%d %d\n", i, res[i]);
    exit(0);
}
