/*
ID: Yiting
LANG: C++
TASK: humble 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#include<queue>
#include<limits.h>
#define KMAX 100
#define NMAX 100000
#define DEBUG 0
using namespace std;

int k, n, cnt;
int setS[KMAX + 1], setIndex[KMAX + 1];
long int hum[NMAX + 1];

#if DEBUG
FILE *fin = fopen("test.in", "rb");
FILE *fout = fopen("test.out", "wb");
#else
FILE *fin = fopen("humble.in", "rb");
FILE *fout = fopen("humble.out", "wb");
#endif

main() {
    int i;
    long int min;
    fscanf(fin, "%d %d", &k, &n);
    for (i = 0; i < k; i++) {
        fscanf(fin, "%d", &setS[i]);
    }
    hum[cnt++] = 1;
    while (cnt <= n) {
        min = LONG_MAX;
        for (i = 0; i < k; i++) {
            //find the product value that greater than the smallest hum value
            while (setS[i] * hum[setIndex[i]] <= hum[cnt - 1])
                setIndex[i]++;
            //find min among all these values
            if (setS[i] * hum[setIndex[i]] < min)
                min = setS[i] * hum[setIndex[i]];
        }
        hum[cnt++] = min;
    }
    fprintf(fout, "%d\n", hum[n]);
    exit(0);
}
