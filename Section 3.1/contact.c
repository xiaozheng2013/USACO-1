/*
ID: Yiting
LANG: C++
TASK: contact
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

typedef struct ResultForSort {
    string binary;
    int times;
} rft;

#if DEBUG
ifstream fin("test.in");
ofstream fout("test.out");
#else
ifstream fin("contact.in");
ofstream fout("contact.out");
#endif

int A, B, N;
int input[200010], res[200000];
rft result[200000];

int Bin_Dec(int i, int j) {
    int val = 0, base = 1;
    while (j >= i) {
        val += base * input[j];
        base *= 2;
        j--;
    }
    val += base; //insure each binary string start with '1'
    return val;
}

int getbitsNum(int bit) {
    int base = 1;
    while (bit != 0) {
        base *= 2;
        bit--;
    }
    return base;
}

string Dec_Bin(int dec) {
    string x;
    while (dec != 1) {
        if (dec % 2 == 0) x = '0' + x;
        if (dec % 2 == 1) x = '1' + x;
        dec /= 2;
    }
    return x;
}

int compare(const void *ele1, const void *ele2) {
    rft *rx, *ry;
    rx = (rft*) ele1;
    ry = (rft*) ele2;
    return (rx->times > ry->times) ? -1 : (rx->times == ry->times) ? 0 : 1;
}

main() {
    fin >> A >> B >> N;
    int len = 0;
    char tmp;
    while (!fin.eof()) {
        tmp = fin.get();
        if (tmp != '1' && tmp != '0')
            continue;
        input[len++] = tmp - '0';
    }

    if (B > len) B = len;

    for (int i = 0; i < len - B + 1; i++)
        res[Bin_Dec(i, i + B - 1)]++;

    int bit = B - 1;
    while (bit >= A) {
        int minB = getbitsNum(bit);
        int maxB = getbitsNum(bit + 1) - 1;
        int last = Bin_Dec(len - bit, len - 1);
        for (int i = minB; i <= maxB; i++) {
            res[i] += res[2 * i] + res[2 * i + 1];
            if (i == last) res[i]++;
        }
        bit--;
    }

    int cnt = 0;
    for (int i = 0; i < 200000; i++) {
        if (res[i] != 0) {
            result[cnt].binary = Dec_Bin(i);
            result[cnt++].times = res[i];
        }
    }

    qsort(result, cnt, sizeof (rft), compare);
    int i = 0, j = 0, change = 0;

    while (i < cnt) {
        j++;
        fout << result[i].times << endl;
        fout << result[i].binary;
        if (result[i + 1].times == result[i].times) {
            int current = result[i].times;
            int c = i + 1;
            int num = 1;
            int out = 1;
            while (result[c].times == current) {
                if (change == 1) {
                    fout << result[c].binary;
                    change = 0;
                } else
                    fout << " " << result[c].binary;
                c++;
                num++;
                out++;
                if (out == 6) {
                    if (result[c].times == current) {
                        change = 1;
                        out = 0;
                        fout << endl;
                    }
                }
            }
            i += num;
            fout << endl;
        } else {
            i++;
            fout << endl;
        }
        if (j == N) break;
    }
    exit(0);
}
