/*
ID: Yiting
LANG: C
TASK: ride
 */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 1024

main() {
    FILE *fin = fopen("ride.in", "r");
    FILE *fout = fopen("ride.out", "w");
    char a[MAX], b[MAX];
    int i;
    long ra = 1, rb = 1;
    fscanf(fin, "%s%s", a, b);
    for (i = 0; i < strlen(a); i++)
        ra = ra * (a[i] - 'A' + 1);
    for (i = 0; i < strlen(b); i++)
        rb = rb * (b[i] - 'A' + 1);

    if ((ra % 47) == (rb % 47)) {
        fprintf(fout, "%s\n", "GO");
    } else {
        fprintf(fout, "%s\n", "STAY");
    }
    exit(0);
}