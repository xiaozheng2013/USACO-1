/*
ID: Yiting
LANG: C++
TASK: stamps
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
ifstream fin("stamps.in");
ofstream fout("stamps.out");
#endif

int K, N;
int stamps[50];
int total[200 * 10000 + 1];

main() {
    int curr = 0, min, tmp; //starting at 1 cent
    fin >> K >> N;
    for (int i = 0; i < N; i++) {
        fin >> stamps[i];
        total[stamps[i]] = 1;
    }
    while (true) {
        curr++;
        if (total[curr] != 0) continue;
        min = K + 1;
        for (int i = 0; i < N; i++) {
            tmp = curr - stamps[i];
            if (tmp <= 0) continue;
            if (total[tmp] + 1 < min) {
                min = total[tmp] + 1;
            }
        }
        if (min > K) break;
        total[curr] = min;
    }
    fout << curr - 1 << endl;
    exit(0);
}