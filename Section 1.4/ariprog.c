/*
ID: Yiting
LANG: C++
TASK: ariprog 
 */
#include<stdio.h>
#include<stdlib.h>
#define MAX 250*250*2+1

int value[MAX];

struct result {
    int num;
    int v;
};

struct result R[100];

int struct_cmp_by_v(const void *a, const void *b) {
    struct result *ia = (struct result *) a;
    struct result *ib = (struct result *) b;
    return ia->v - ib->v;
}

int solve(int* map, int n) {
    int i, j, k, c = 0;
    bool done;
    for (i = 0; i < MAX; i++) {
        if (map[i] == 1)
            for (j = 1; j <= MAX; j++) {
                if (i + j * (n - 1) > MAX) break;
                done = true;
                int a = i;
                for (k = 0; k < n - 1; k++) {
                    a += j;
                    if (value[a] != 1) {
                        done = false;
                        break;
                    }
                }
                if (done) {
                    R[c].num = i;
                    R[c++].v = j;
                }
            }
    }
    return c;
}

main() {

    FILE* fin = fopen("ariprog.in", "rb");
    FILE* fout = fopen("ariprog.out", "wb");

    int n, m, i, j;
    //memset(value, 0, sizeof (value));//???
    fscanf(fin, "%d\n%d", &n, &m);
    for (i = 0; i <= m; i++) {
        for (j = i; j <= m; j++)
            value[i * i + j * j] = 1;
    }

    int c = solve(value, n);
    qsort(R, c, sizeof (struct result), struct_cmp_by_v);
    if (c == 0) {
        fprintf(fout, "NONE\n");
    } else
        for (i = 0; i < c; i++) {
            if (i == 0)
                fprintf(fout, "%d %d\n", R[i].num, R[i].v);
            if (i > 0 && !(R[i].v == R[i - 1].v && R[i].num == R[i - 1].num))
                fprintf(fout, "%d %d\n", R[i].num, R[i].v);
        }
    fclose(fin);
    fclose(fout);
    exit(0);
}
