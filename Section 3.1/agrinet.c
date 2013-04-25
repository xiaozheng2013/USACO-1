/*
ID: Yiting
LANG: C++
TASK: agrinet 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#define NMAX 100
#define DEBUG 0
using namespace std;

int n, graph[NMAX + 1][NMAX + 1], res;
bool nodes[NMAX + 1];


#if DEBUG
FILE *fin = fopen("test.in", "rb");
FILE *fout = fopen("test.out", "wb");
#else
FILE *fin = fopen("agrinet.in", "rb");
FILE *fout = fopen("agrinet.out", "wb");
#endif

typedef struct Edge {

    friend bool operator<(struct Edge e1, struct Edge e2) {
        return e1.weight > e2.weight;
    }
    int from, to, weight;
} edge;

priority_queue<edge> q;

void output() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d ", graph[i][j]);
        printf("\n");
    }
}

void prim() {
    int i;
    nodes[1] = true;
    for (i = 1; i <= n; i++) {
        if (graph[1][i] != 0) {
            edge e = {1, i, graph[1][i]};
            q.push(e);
        }
    }
    while (!q.empty()) {
        edge selectedEdge = q.top();
        q.pop();
        if (nodes[selectedEdge.to]) continue;
        //printf("from %d to %d, weight = %d\n", selectedEdge.from, selectedEdge.to, selectedEdge.weight);
        res += selectedEdge.weight;
        nodes[selectedEdge.to] = true;
        for (i = 1; i <= n; i++) {
            if (selectedEdge.to != i && !nodes[i]) {
                edge e = {selectedEdge.to, i, graph[selectedEdge.to][i]};
                q.push(e);
            }
        }
    }
}

main() {
    int i, j;
    fscanf(fin, "%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            fscanf(fin, "%d", &graph[i][j]);
        }
    }
    prim();
    fprintf(fout, "%d\n", res);
    exit(0);
}
