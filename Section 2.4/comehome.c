/*
ID: Yiting
LANG: C++
TASK: comehome 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define INF 1000000
#define NUM 26*2
#define DEBUG 0
using namespace std;

int graph[NUM][NUM], path[NUM][NUM];
int p;

void Floyd() {
    int i, j, k;
    for (k = 0; k < NUM; k++) {
        for (i = 0; i < NUM; i++) {
            for (j = 0; j < NUM; j++) {
                if (path[i][j] > path[i][k] + path[k][j])
                    path[i][j] = path[i][k] + path[k][j];
            }
        }
    }
}

main() {
#if DEBUG
    FILE *fin = fopen("test.in", "rb");
    FILE *fout = fopen("test.out", "wb");
#else
    FILE *fin = fopen("comehome.in", "rb");
    FILE *fout = fopen("comehome.out", "wb");
#endif
    int i, j, dis, a, b;
    char tmpA, tmpB;
    fscanf(fin, "%d\n", &p);
    for (i = 1; i <= p; i++) {
        fscanf(fin, "%c %c %d\n", &tmpA, &tmpB, &dis);
        if (tmpA < 'a') a = tmpA - 'A' + NUM / 2;
        else a = tmpA - 'a';
        if (tmpB < 'a') b = tmpB - 'A' + NUM / 2;
        else b = tmpB - 'a';
        graph[a][b] = (graph[a][b] == 0) ? dis : ((graph[a][b] > dis) ? dis : graph[a][b]);
        graph[b][a] = (graph[b][a] == 0) ? dis : ((graph[b][a] > dis) ? dis : graph[b][a]);
    }
    for (i = 0; i < NUM; i++) {
        for (j = 0; j < NUM; j++) {
            if (graph[i][j] == 0) {
                graph[i][j] = INF;
                graph[j][i] = INF;
            }
        }
    }
    memcpy(path, graph, sizeof (path));
    Floyd();

    char c;
    int d = INF;
    for (i = NUM / 2; i < NUM - 1; i++) {
        if (d > path[i][NUM - 1]) {
            d = path[i][NUM - 1];
            c = i + 'A' - NUM / 2;
        }
    }
    fprintf(fout, "%c %d\n", c, d);
}
