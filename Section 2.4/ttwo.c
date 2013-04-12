/*
ID: Yiting
LANG: C++
TASK: ttwo 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#define MAX 500
using namespace std;

typedef struct positions {
    int x;
    int y;
} pos;

enum direction {
    N = 0, E, S, W
};

vector< pair<pos, int> >qF[MAX];
vector< pair<pos, int> >qC[MAX];
char init[10][10];
int cF, cQ;

void updateState(char ch) {
    int i, j;
    pos p;
    i = (ch == 'F') ? qF[cF - 1][0].first.x : qC[cQ - 1][0].first.x;
    j = (ch == 'F') ? qF[cF - 1][0].first.y : qC[cQ - 1][0].first.y;
    int d = (ch == 'F') ? qF[cF - 1][0].second : qC[cQ - 1][0].second, newD;
    p.x = i, p.y = j;
    if (d == N) i--;
    if (d == S) i++;
    if (d == W) j--;
    if (d == E) j++;
    if (i < 0 || i > 9 || j < 0 || j > 9) {
        newD = (d + 1) % 4;
    } else if (init[i][j] == '*') {
        newD = (d + 1) % 4;
    } else {
        newD = d;
        p.x = i;
        p.y = j;
    }
    if (ch == 'F') qF[cF++].push_back(make_pair(p, newD));
    if (ch == 'C') qC[cQ++].push_back(make_pair(p, newD));
}

bool find(int cf, int cq) {
    if (qF[cf][0].first.x == qC[cq][0].first.x &&
            qF[cf][0].first.y == qC[cq][0].first.y)
        return true;
    return false;
}

main() {
    FILE *fin = fopen("ttwo.in", "rb");
    FILE *fout = fopen("ttwo.out", "wb");
    int i, j;
    int tmp;
    char temp[10];
    memset(init, 0, sizeof (init));
    for (i = 0; i < 10; i++) {
        fscanf(fin, "%s", temp);
        for (j = 0; j < 10; j++) {
            init[i][j] = temp[j];
            if (init[i][j] == 'F') {
                pos p;
                p.x = i, p.y = j;
                qF[cF++].push_back(make_pair(p, N));
            }
            if (init[i][j] == 'C') {
                pos p;
                p.x = i, p.y = j;
                qC[cQ++].push_back(make_pair(p, N));
            }
        }
    }
    bool found = false;
    int n = 0;
    while (n < 500) {
        n++;
        //get new qF and qC
        updateState('F');
        updateState('C');
        //check if qF==qC
        if (find(cF - 1, cQ - 1)) {
            found = true;
            break;
        }
    }
    if (found) fprintf(fout, "%d\n", cQ - 1);
    else fprintf(fout, "0\n");
    exit(0);
}
