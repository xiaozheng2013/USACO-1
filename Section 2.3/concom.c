/*
ID: Yiting
LANG: C++
TASK: concom 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>

using namespace std;

vector < pair<int, int> > owns[101];
int pro[101], n;
bool checked[101];

void DFS(int a) {
    int i;
    for (i = 0; i < owns[a].size(); i++) {
        int b = owns[a][i].first;
        int p = owns[a][i].second;
        pro[b] += p;
        if (pro[b] > 50 && !checked[b]) {
            checked[b] = true;
            DFS(b);
        }
    }
}

main() {
    FILE *fin = fopen("concom.in", "rb");
    FILE *fout = fopen("concom.out", "wb");
    fscanf(fin, "%d", &n);
    int i, j, a, b, p;
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d %d %d", &a, &b, &p);
        owns[a].push_back(make_pair(b, p));
    }
    for (i = 1; i <= 100; i++) {
        memset(pro, 0, sizeof (pro));
        memset(checked, 0, sizeof (checked));
        DFS(i);
        for (j = 1; j <= 100; j++) {
            if (i != j)
                if (pro[j] > 50)
                    fprintf(fout, "%d %d\n", i, j);
        }
    }
    exit(0);
}
