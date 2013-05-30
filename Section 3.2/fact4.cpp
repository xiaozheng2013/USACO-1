/*
ID: Yiting
LANG: C++
TASK: fact4
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<queue>
#include<iostream>
#include<fstream>
#define DEBUG 0
using namespace std;

#if DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#else
ifstream fin("fact4.in");
ofstream fout("fact4.out");
#endif

main() {
    int N, lastNonDigit = 1, res = 1;
    fin >> N;
    if (N != 1)
        for (int i = 2; i <= N; i++) {
            res *= i;
            lastNonDigit = res % 10;
            while (lastNonDigit == 0) {//remove 0s
                res = res / 10;
                lastNonDigit = res % 10;
            }
            res = res % 1000; // keep last 3 digits
        }
    res = res % 10;
    fout << res << endl;
    exit(0);
}