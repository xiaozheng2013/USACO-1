/*
ID: Yiting
LANG: C++
TASK: fracdec 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define DEBUG 0
using namespace std;

int pos[100001], cnt = 1, f;
char res[100005];

#if DEBUG
FILE *fin = fopen("test.in", "rb");
FILE *fout = fopen("test.out", "wb");
#else
FILE *fin = fopen("fracdec.in", "rb");
FILE *fout = fopen("fracdec.out", "wb");
#endif

int getNum(int n) {
    if (n == 0) return 1;
    int num = 0;
    while (n != 0) {
        num++;
        n = n / 10;
    }
    return num;
}

void getResult(int n, int d) {
    memset(pos, -1, sizeof (pos));
    int num = n / d, i;
    fprintf(fout, "%d.", num);
    cnt += getNum(num);
    cnt++;
    f = cnt;
    n = n % d;
    while (pos[n] == -1) {
        pos[n] = cnt++;
        res[pos[n]] = n * 10 / d + '0';
        n = (n * 10) % d;
        if (n == 0) break;// not infinite
    }
    if (n == 0) {
        for (i = f; i < cnt; i++) {
            fprintf(fout, "%c", res[i]);
            if (i % 76 == 0) fprintf(fout, "\n");
        }
        if ((cnt - 1) % 76 != 0) fprintf(fout, "\n");
    } else {
        for (i = f; i < pos[n]; i++) {
            fprintf(fout, "%c", res[i]);
            if (i % 76 == 0) fprintf(fout, "\n");
        }
        fprintf(fout, "(");
        i++;
        if (i % 76 == 0) fprintf(fout, "\n");
        cnt++;
        while (i < cnt) {
            fprintf(fout, "%c", res[i - 1]);
            if (i % 76 == 0) fprintf(fout, "\n");
            i++;
        }
        fprintf(fout, ")\n");
    }
}



main() {
    int n, d;
    fscanf(fin, "%d %d", &n, &d);
    getResult(n, d);
}
