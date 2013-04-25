/*
ID: Yiting
LANG: C++
TASK: inflate 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#define DEBUG 0
#define MAX(A,B) (A)>(B)?(A):(B)
#define NMAX 10000
using namespace std;

int m, n;
int p[NMAX], t[NMAX], f[NMAX + 1];

#if DEBUG
FILE *fin = fopen("test.in", "rb");
FILE *fout = fopen("test.out", "wb");
#else
FILE *fin = fopen("inflate.in", "rb");
FILE *fout = fopen("inflate.out", "wb");
#endif

void solve() {
    int i, j;
    for (i = 0; i < n; i++) {// all possible choices
        for (j = 1; j <= m; j++) { // all possible times
            if (j >= t[i]) {
                f[j] = MAX(f[j], f[j - t[i]] + p[i]);
            }
        }
    }
}

main() {
    fscanf(fin, "%d %d", &m, &n);
    int i;
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &p[i], &t[i]);
    }
    memset(f, 0, sizeof (f));
    solve();
    fprintf(fout, "%d\n", f[m]);
    exit(0);
}
