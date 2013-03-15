/*
ID: Yiting
LANG: C
TASK: friday
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int isLeap(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        return 1;
    return 0;
}

main() {
    FILE *fin = fopen("friday.in", "r");
    FILE *fout = fopen("friday.out", "a");
    int N, i, j, k, startYear = 1900, startDay = 0, total;
    int days[7] = {0}; //0-6, monday to sunday
    int output[7] = {0};
    int months[12] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    fscanf(fin, "%d", &N);
    for (i = 0; i < N; i++) {//year loop
        total = 0;
        if (!isLeap(startYear)) {
            for (j = 0; j < 12; j++) {//12 months loop
                total += months[j];
                days[(total + 13 + startDay - 1) % 7]++;
            }
            startDay = (1 + startDay) % 7;
        } else {
            for (j = 0; j < 12; j++) {//12 months loop
                total += months[j];
                if (j == 2)total++;
                days[(total + 13 + startDay - 1) % 7]++;
            }
            startDay = (2 + startDay) % 7; //????????
        }
        startYear++;
    }
    output[0] = days[5];
    output[1] = days[6];
    for (i = 0; i < 5; i++)
        output[i + 2] = days[i];
    for (i = 0; i < 7; i++) {
        fprintf(fout, "%d", output[i]);
        if (i != 6)
            fprintf(fout, " ");
    }
    fprintf(fout, "\n");
    exit(0);
}