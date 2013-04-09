/*
ID: Yiting
LANG: C++
TASK: prefix 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;

char s[200200];
bool sTo[200200];
int res;

struct Primitives {
    char ch[11];
    int len;
} P[200];

void DP(int cnt) {
    int i, j, k, l = strlen(s);
    bool check;
    sTo[0] = 1;
    for (i = 0; i < l; i++) {
        if (!sTo[i]) continue;
        for (j = 0; j < cnt; j++) {
            check = true;
            for (k = 0; k < P[j].len; k++) {
                if (P[j].ch[k] != s[i + k]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                sTo[i + P[j].len] = 1;
                if (i + P[j].len > res)
                    res = i + P[j].len;
            }
        }
    }
}

main() {

    FILE *fin = fopen("prefix.in", "rb");
    FILE *fout = fopen("prefix.out", "wb");
    char tmp[20];
    int cnt = 0, cs = 0;
    while (fscanf(fin, "%s", tmp)) {
        if (strcmp(tmp, ".") == 0)
            break;
        strcpy(P[cnt].ch, tmp);
        P[cnt++].len = strlen(tmp);
    }
    while ((s[cs] = fgetc(fin)) != EOF) {
        while (s[cs] == '\r' || s[cs] == ' ' || s[cs] == '\n')
            s[cs] = fgetc(fin);
        cs++;
    }
    s[cs - 1] = '\0';
    DP(cnt);
    fprintf(fout, "%d\n", res);
    exit(0);
}
