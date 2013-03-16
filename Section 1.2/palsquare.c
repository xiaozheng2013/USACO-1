/*
ID: Yiting
LANG: C
TASK: palsquare 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 300 //check

char* getBase(int base, int number);
int getPosition(int number, int p);
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

/*
 * 123/100=1
 * 123%100=23
 * 23/10=2
 * 23%10=3
 * 3/10=0
 * 3%10=3
 */
int getPosition(int number, int p) {

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
    FILE *fin = fopen("palsquare.in", "r");
    FILE *fout = fopen("palsquare.out", "w");

    int base, i, square;
    fscanf(fin, "%d", &base);
    for (i = 1; i < MAX; i++) {
        square = i*i;
        char*s = getBase(base, square);
        if (isP(s) == 1) {
            fprintf(fout, "%s %s\n", getBase(base, i), s);
        }
    }

    exit(0);
}