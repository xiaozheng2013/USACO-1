/*
ID: Yiting
LANG: C++
TASK: cowtour 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define MAX 150
#define Max(A,B) (A)>(B)?(A):(B)
#define Min(A,B) (A)<(B)?(A):(B)
#define INF 1000000.000000
#define DEBUG 0
using namespace std;

typedef struct Pasture {
    int num;
    int px, py;
} pasture;

int N, graph[MAX + 1][MAX + 1], same[MAX + 1];
double path[MAX + 1][MAX + 1], dis[MAX + 1], dia[MAX + 1];
pasture P[MAX + 1];

void Floyd() {
    int i, j, k;
    for (k = 1; k <= N; k++) {
        for (i = 1; i <= N; i++) {
            for (j = 1; j <= N; j++) {
                if (path[i][j] > path[i][k] + path[k][j])
                    path[i][j] = path[i][k] + path[k][j];
            }
        }
    }
}

double getSingleDis(int i, int j) {
    int x1 = P[i].px, y1 = P[i].py, x2 = P[j].px, y2 = P[j].py;
    return sqrt((y2 - y1)*(y2 - y1)+(x2 - x1)*(x2 - x1));
}

void splitGraph(int node, int num) {
    int i;
    if (same[node] != 0)
        return;
    same[node] = num;
    for (i = 1; i <= N; i++) {
        if (same[i] == 0 && graph[node][i] == 1) {
            splitGraph(i, num);
        }
    }
}

main() {
#if DEBUG
    FILE *fin = fopen("test.in", "rb");
    FILE *fout = fopen("test.out", "wb");
#else
    FILE *fin = fopen("cowtour.in", "rb");
    FILE *fout = fopen("cowtour.out", "wb");
#endif
    int i, j, k, tmX, tmY;
    double tmpD;
    char tmpline[MAX + 1];
    memset(P, 0, sizeof (P));
    fscanf(fin, "%d", &N);
    for (i = 1; i <= N; i++) {
        P[i].num = i;
        fscanf(fin, "%d %d", &tmX, &tmY);
        P[i].px = tmX, P[i].py = tmY;
    }
    for (i = 1; i <= N; i++) {
        fscanf(fin, "%s", tmpline);
        for (j = 0; j < N; j++) {
            graph[i][j + 1] = tmpline[j] - '0';
            if (tmpline[j] == '0') {
                path[i][j + 1] = INF, path[j + 1][i] = INF;
            } else {
                tmpD = getSingleDis(i, j + 1);
                path[i][j + 1] = tmpD, path[j + 1][i] = tmpD;
            }
        }
    }
    Floyd();
    int num = 1;
    for (i = 1; i <= N; i++)
        if (same[i] == 0)
            splitGraph(i, num++);

    for (i = 1; i <= N; i++) {
        dis[i] = 0;
        for (j = 1; j <= N; j++) {
            if (i != j && same[i] == same[j]) {
                dis[i] = Max(dis[i], path[i][j]);
            }
        }
        dia[same[i]] = Max(dia[same[i]], dis[i]);
    }

    double d = INF;
    for (i = 1; i <= N; i++) {
        for (j = i + 1; j <= N; j++) {
            if (same[i] == same[j]) continue;

            double f1 = 0;
            for (k = 1; k <= N; k++) {
                if (i != k && same[i] == same[k])
                    f1 = Max(f1, path[i][k]);
            }

            double f2 = 0;
            for (k = 1; k <= N; k++) {
                if (j != k && same[j] == same[k])
                    f2 = Max(f2, path[j][k]);
            }

            double f3 = getSingleDis(i, j);
            d = Min(d, Max((f1 + f2 + f3), Max(dia[same[i]], dia[same[j]])));
        }
    }
    fprintf(fout, "%f\n", d);
}
