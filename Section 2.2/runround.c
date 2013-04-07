/*
ID: Yiting
LANG: C++
TASK: runround 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
long int n;
bool work[MAX];

bool checkNum(long int num) {
    int base = 10, c = 0, i;
    long int temp = num;
    char* numString = (char*) malloc(sizeof (char) *MAX);
    char cur;
    while (temp) {
        cur = temp % base + 48;
        if (cur == '0')
            return false;
        for (i = 0; i < c; i++)
            if (cur == numString[i])
                return false;
        numString[c++] = cur;
        temp = temp / base;
    }
    return true;
}

char* getNum(long int num) {
    int base = 10, c = 0, i;
    long int temp = num;
    char* numString = (char*) malloc(sizeof (char) *MAX);
    while (temp) {
        numString[c++] = temp % base + 48;
        temp = temp / base;
    }
    numString[c] = '\0';
    char tmp;
    for (i = 0; i < c / 2; i++) {
        tmp = numString[i];
        numString[i] = numString[c - i - 1];
        numString[c - i - 1] = tmp;
    }
    return numString;
}

bool check(long int num) {
    char* numString = getNum(num);
    int pos = 1, move = numString[0] - 48, loop = 0, len = strlen(numString), m;
    memset(work, 0, sizeof (work));
    work[0] = true;
    while (loop < len) {
        loop++;
        if (pos + move > len) {
            m = (move - (len - pos) - 1) % len;
        } else {
            m = pos + move - 1;
        }
        if (loop < len) {
            if (work[m])
                return false;
            work[m] = true;
            move = numString[m] - 48;
            pos = (m + 1) % len;
        } else {
            break;
        }
    }
    if (m == 0)
        return true;
    return false;
}

main() {
    FILE *fin = fopen("runround.in", "rb");
    FILE *fout = fopen("runround.out", "wb");
    fscanf(fin, "%ld", &n);
    bool res;
    while (n) {
        n++;
        if (!checkNum(n))
            continue;
        res = check(n);
        if (res) {
            fprintf(fout, "%ld\n", n);
            break;
        }
    }
    exit(0);
}
