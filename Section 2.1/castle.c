/*
ID: Yiting
LANG: C++
TASK: castle 
 */

#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define MAX 50
#define W 1
#define N 2
#define E 4
#define S 8
using namespace std;

int input[MAX][MAX], col[MAX][MAX];
int color_cnt, m, n;
int c[MAX*MAX];

void setColor(int i, int j, int color) {
    if (col[i][j] != -1)
        return;
    col[i][j] = color;
    c[color]++;
    if ((input[i][j] & N) == 0 && (i - 1 >= 0))
        setColor(i - 1, j, color);
    if ((input[i][j] & S) == 0 && (i + 1 < n))
        setColor(i + 1, j, color);
    if ((input[i][j] & W) == 0 && (j - 1 >= 0))
        setColor(i, j - 1, color);
    if ((input[i][j] & E) == 0 && (j + 1 < m))
        setColor(i, j + 1, color);
}

main() {
    FILE *fin = fopen("castle.in", "rb");
    FILE *fout = fopen("castle.out", "wb");
    int i, j, largest;
    fscanf(fin, "%d %d", &m, &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            fscanf(fin, "%d", &input[i][j]);
    color_cnt = 0;

    memset(col, -1, sizeof (col));
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (col[i][j] == -1)
                setColor(i, j, color_cnt++);
    fprintf(fout, "%d\n", color_cnt);

    largest = INT_MIN;
    for (i = 0; i < m * n; i++)
        largest = max(c[i], largest);
    fprintf(fout, "%d\n", largest);

    int ri, rj;
    char w;

    for (j = 0; j < m; j++)
        for (i = n - 1; i >= 0; i--) {
            if (i - 1 >= 0) {
                if (col[i][j] != col[i - 1][j]) {
                    if (c[col[i][j]] + c[col[i - 1][j]] > largest) {
                        largest = c[col[i][j]] + c[col[i - 1][j]];
                        ri = i, rj = j, w = 'N';
                    }
                }
            }
            if (j + 1 < m) {
                if (col[i][j] != col[i][j + 1]) {
                    if (c[col[i][j]] + c[col[i][j + 1]] > largest) {
                        largest = c[col[i][j]] + c[col[i][j + 1]];
                        ri = i, rj = j, w = 'E';
                    }
                }
            }
        }
    fprintf(fout, "%d\n", largest);
    fprintf(fout, "%d %d %c\n", ri + 1, rj + 1, w);
    return 0;
}
