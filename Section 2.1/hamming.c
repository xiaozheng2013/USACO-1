/*
ID: Yiting
LANG: C++
TASK: hamming 
 */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<limits.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<assert.h>
#define MAX 256
using namespace std;
int n, b, d, c;
bool res[MAX];

FILE *fin = fopen("hamming.in", "rb");
FILE *fout = fopen("hamming.out", "wb");

void output() {
    int c = 0, i;
    for (i = 0; i < 256; i++) {
        if (c != 0 && c % 10 == 0 && res[i])
            fprintf(fout, "\n");
        if ((c == 0 && res[i]) || (c % 10 == 0 && res[i])) {
            c++;
            fprintf(fout, "%d", i);
        } else
            if (res[i]) {
            c++;
            fprintf(fout, " %d", i);
        }
    }
    fprintf(fout, "\n");
}

void reverse(char* c) {
    int n = strlen(c), m = n / 2, i;
    char temp;
    if (n == 1) return;
    for (i = 0; i < m; i++) {
        temp = c[i];
        c[i] = c[n - i - 1];
        c[n - i - 1] = temp;
    }
}

char* toBinary(int num) {
    char* r = (char*) malloc(sizeof (char) *b);
    int k = num, c = 0;
    if (num == 0) {
        r[0] = '0';
        r[1] = '\0';
    } else {
        while (k) {
            r[c++] = k % 2 + 48;
            k = k / 2;
        }
        r[c] = '\0';
    }
    reverse(r);
    return r;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int getHD(int num1, int num2) {
    char* s1 = toBinary(num1);
    char* s2 = toBinary(num2);
    int n1 = strlen(s1);
    int n2 = strlen(s2);
    int tmp = abs(n1 - n2), i, j;
    if (tmp > 0) {
        int t = tmp;
        for (i = 0; i < t; i++)
            if ((n1 > n2 && s1[i] == '0') || (n1 < n2 && s2[i] == '0'))
                tmp--;
    }
    for (i = n1 - 1, j = n2 - 1; i >= 0 && j >= 0; i--, j--) {
        if (s1[i] != s2[j])
            tmp++;
    }
    return tmp;
}

bool check(int num) {
    int i;
    for (i = 0; i < num; i++) {
        if (res[i])
            if (getHD(i, num) < d)
                return false;
    }
    return true;
}

void DFS(int i) {
    int k;
    if (c == n) {
        output();
        exit(0);
    }
    for (k = i; k < MAX; k++)
        if (check(k)) {
            res[k] = true;
            c++;
            DFS(k + 1);
            res[k] = false;
            c--;
        }
    if (k == MAX && c != n) {
        return;
    }
}

main() {
    memset(res, 0, sizeof (res));
    fscanf(fin, "%d %d %d", &n, &b, &d);
    DFS(0);
}
