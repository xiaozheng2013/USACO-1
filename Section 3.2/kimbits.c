/*
ID: Yiting
LANG: C++
TASK: kimbits
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
ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
#endif

long long N, L, I;
long long f[32][32];

main() {
    fin >> N >> L >> I;
    //f[i][j] means the number of 01 strings which contain at most j 1.
    for (int j = 0; j <= N; j++)
        f[0][j] = f[j][0] = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= L; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }

    for (int i = N; i >= 1; i--) {
        if (I > f[i - 1][L]) {
            fout << "1";
            I -= f[i - 1][L];
            L--;
        } else {
            fout << "0";
        }
    }
    fout << endl;
    exit(0);
}