/*
ID: Yiting
LANG: C++
TASK: milk3 
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define M 20
bool res[M + 1];
bool flag[M + 1][M + 1];
int a, b, c;

void DFS(int x, int y, int z) {
    if (flag[x][y]) return;
    flag[x][y] = true;
    if (x == 0) res[z] = true;
    if (x > 0 && y < b) DFS(MAX(0, x + y - b), MIN(b, x + y), z); //a->b
    if (x > 0 && z < c) DFS(MAX(0, x + z - c), y, MIN(c, x + z)); //a->c
    if (x < a && y > 0) DFS(MIN(a, x + y), MAX(0, x + y - a), z); //b->a
    if (y > 0 && z < c) DFS(x, MAX(0, y + z - c), MIN(c, y + z)); //b->c
    if (x < a && z > 0) DFS(MIN(a, x + z), y, MAX(0, x + z - a)); //c->a
    if (y < b && z > 0)DFS(x, MIN(b, y + z), MAX(0, y + z - b)); //c->b
}

main() {

    FILE* fin = fopen("milk3.in", "rb");
    FILE* fout = fopen("milk3.out", "wb");

    int i;
    fscanf(fin, "%d %d %d", &a, &b, &c);
    DFS(0, 0, c);
    for (i = 0; i < c; i++)
        if (res[i])
            fprintf(fout, "%d ", i);
    fprintf(fout, "%d\n", c);
    fclose(fin);
    fclose(fout);
    exit(0);
}
