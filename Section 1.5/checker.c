/*
ID: Yiting
LANG: C++
TASK: checker 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <math.h>
#include<assert.h>
using namespace std;

FILE* fin = fopen("checker.in", "rb");
FILE* fout = fopen("checker.out", "wb");
bool board[13][13];
int isPlaced[13][13];
bool isPlaced_col[13];
int n;
int c;
void output();
bool check(int row, int col);
void DFS(int row, int col);

void output() {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (board[i][j]) {
                fprintf(fout, "%d", j + 1);
                if (i != n - 1)
                    fprintf(fout, " ");
            }
    fprintf(fout, "\n");
}

void setPlaced(int row, int col, int set) {
    int i, j;
    isPlaced_col[col] = (set == 1) ? true : false;
    for (i = row, j = col; i < n && j < n; i++, j++)
        isPlaced[i][j] = (set == 1) ? isPlaced[i][j] + 1 : isPlaced[i][j] - 1;
    for (i = row, j = col; i < n && j >= 0; i++, j--)
        isPlaced[i][j] = (set == 1) ? isPlaced[i][j] + 1 : isPlaced[i][j] - 1;
}

void DFS(int row) {
    int col;
    if (row == n) {
        if (c < 3) {
            output();
        }
        c++;
        return;
    }
    for (col = 0; col < n; col++) {
        if (!isPlaced_col[col] && isPlaced[row][col] == 0) {
            board[row][col] = true;
            setPlaced(row, col, 1);
            DFS(row + 1);
            board[row][col] = false;
            setPlaced(row, col, 0);
        }
    }
}

main() {
    int i, j;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            board[i][j] = false;
            isPlaced[i][j] = false;
        }
    c = 0;
    DFS(0);
    fprintf(fout, "%d\n", c);
    fclose(fin);
    fclose(fout);
    exit(0);
}
