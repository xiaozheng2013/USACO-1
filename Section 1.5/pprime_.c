/*
ID: Yiting
LANG: C++
TASK: pprime 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <math.h>
using namespace std;

FILE* fin = fopen("pprime.in", "rb");
FILE* fout = fopen("pprime.out", "wb");

bool isPrime(int p) {
    if (p % 2 == 0 || p < 1) return false;

    int len = sqrt(p * 1.0);

    for (int i = 3; i <= len; i += 2) if (p % i == 0) return false;
    return true;
}

int reverse(int n) {
    int result = 0;
    while (n > 0) {
        result = result * 10 + (n % 10);
        n /= 10;
    }
    return result;
}

void calc(int a, int b) {
    int i;
    int base = 1;
    while (base * base * 10 < a)
        base *= 10;
    while (true) {
        for (i = base; i < base * 10; i++) {
            int r = i * base + (reverse(i) % base);
            if (r > b)
                return;
            if (r >= a && isPrime(r))
                fprintf(fout, "%d\n", r);
        }
        for (i = base; i < base * 10; i++) {
            int r = i * base * 10 + reverse(i);
            if (r > b)
                return;
            if (r >= a && isPrime(r))
                fprintf(fout, "%d\n", r);
        }
        base *= 10;
    }
}

main() {
    int a, b;
    fscanf(fin, "%d %d", &a, &b);
    calc(a, b);
    fclose(fin);
    fclose(fout);
    exit(0);
}
