/*
ID: Yiting
LANG: C
TASK: dualpal 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000 //check

char* getBase(int base, int number);
int getNumber(int num);
int isP(char* number);

char* getBase(int base, int number) {
    char* result = (char*) malloc(sizeof (char) *MAX);
    int tempNum = number, remainder = number, count = 0, i;
    while (tempNum >= base) {
        remainder = tempNum % base;
        tempNum = tempNum / base;
        if (remainder >= 10)
            result[count++] = remainder - 10 + 'A';
        else {
            result[count++] = remainder + '0';
        }
    }
    if (tempNum >= 10)
        result[count] = tempNum - 10 + 'A';
    else {
        result[count] = tempNum + '0';
    }
    result[count + 1] = '\0';
    char tempC;
    for (i = 0; i < (count + 1) / 2; i++) {
        tempC = result[i];
        result[i] = result[count - i];
        result[count - i] = tempC;
    }
    return result;
}

int getNumber(int num) {//how many digits in the number
    int i, b = 1, n = 1, temp = num;
    while (temp / b > 0) {
        b = b * 10;
        n++;
    }
    return n;
}

int isP(char* number) {
    int i, n = strlen(number);
    for (i = 0; i < n / 2; i++) {
        if (number[i] != number[n - 1 - i])
            return -1;
    }
    return 1;
}

main() {
    FILE *fin = fopen("dualpal.in", "r");
    FILE *fout = fopen("dualpal.out", "w");

    int N, S, i, count = 0, base, times;
    fscanf(fin, "%d %d", &N, &S);
    for (i = S + 1; i < S + MAX; i++) {
        if (count == N)
            break;
        times = 0;
        for (base = 2; base <= 10; base++) {
            char* s = getBase(base, i);
            if (isP(s) == 1)
                times++;
            free(s);
            if (times == 2) {
                //printf("%d\n", i);
                fprintf(fout, "%d\n", i);
                count++;
                break;
            }
        }
    }
    exit(0);
}