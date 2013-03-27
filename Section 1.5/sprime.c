/*
ID: Yiting
LANG: C++
TASK: sprime 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <math.h>
using namespace std;

int n;

FILE* fin = fopen("sprime.in", "rb");
FILE* fout = fopen("sprime.out", "wb");

bool isPrime(int p) {
    if (p == 2)return true;
    if (p % 2 == 0 || p < 1) return false;
    int len = (int) sqrt(p * 1.0);
    for (int i = 3; i <= len; i += 2) if (p % i == 0) return false;
    return true;
}

int getNum(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num = num / 10;
    }
    return count;
}

void DFS(int num) {
    int c = getNum(num), i;
    if (c == n) {
        if (isPrime(num))
            fprintf(fout, "%d\n", num);
        return;
    }
    if (!isPrime(num)) return;
    for (i = 1; i <= 9; i++) {
        num = num * 10;
        DFS(num + i);
        num = num / 10;
    }
}

main() {
    int i;
    fscanf(fin, "%d", &n);
    DFS(2);
    for (i = 3; i <= 9; i += 2)
        DFS(i);
    fclose(fin);
    fclose(fout);
    exit(0);
}
