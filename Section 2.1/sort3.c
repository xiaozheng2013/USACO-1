/*
ID: Yiting
LANG: C++
TASK: sort3 
 */

#include<stdio.h>
#include<stdlib.h>
#include<queue>
#include<iostream>
#include<algorithm>
#define MAX 1000
using namespace std;

int n, array[MAX], c[3], res;
bool check[MAX];
FILE *fin = fopen("sort3.in", "rb");
FILE *fout = fopen("sort3.out", "wb");

int find_exchange(int place, int num) {
    int from, to, i;
    if (place == 2)
        from = c[0], to = c[0] + c[1];
    if (place == 3)
        from = c[0] + c[1], to = c[0] + c[1] + c[2];
    for (i = from; i < to; i++)
        if (!check[i] && array[i] == num)
            return i;
    return -1;
}

int find_num(int n) {
    int from, to, i, co = 0;
    if (n == 1)
        from = 0, to = c[1] - 1;
    if (n == 2)
        from = c[0], to = c[0] + c[1] - 1;
    if (n == 3)
        from = c[0] + c[1], to = c[0] + c[1] + c[2] - 1;
    for (i = from; i <= to; i++)
        if (!check[i])
            co++;
    return co;
}

main() {
    int i;
    fscanf(fin, "%d", &n);
    res = 0;
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d", &array[i]);
        c[array[i] - 1]++;
    }
    if ((c[0] == 0 && c[1] == 0) || (c[0] == 0 && c[2] == 0) || (c[1] == 0 && c[2] == 0)) {
        fprintf(fout, "0\n");
        exit(0);
    }
    if (c[0] == 0 || c[2] == 0) {
        fprintf(fout, "%d\n", find_num(1));
        exit(0);
    }
    if (c[1] == 0) {
        fprintf(fout, "%d\n", find_num(0));
        exit(0);
    }

    for (i = 0; i < n; i++) {
        if (array[i] == 1)
            check[i] = (i < c[0]) ? true : false;
        if (array[i] == 2)
            check[i] = (i >= c[0] && i < c[0] + c[1]) ? true : false;
        if (array[i] == 3)
            check[i] = (i >= c[0] + c[1] && i < c[0] + c[1] + c[2]) ? true : false;
    }

    int exchange;
    for (i = 0; i < c[0]; i++) {
        if (!check[i]) {
            exchange = find_exchange(array[i], 1);
            if (exchange != -1) {
                check[i] = true, check[exchange] = true;
                res++;
            } else {
                res += 2;
            }
        }
    }
    for (i = c[0]; i < c[0] + c[1] + c[2]; i++) {
        if (!check[i] && array[i] != 1) {
            exchange = find_exchange(array[i], 2);
            if (exchange != -1) {
                check[i] = true, check[exchange] = true;
                res++;
            }
        }
    }
    fprintf(fout, "%d\n", res);
    return 0;
}
