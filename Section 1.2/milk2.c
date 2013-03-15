/*
ID: Yiting
LANG: C
TASK: milk2
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5000

int n;

typedef struct Data {
    int start;
    int end;
} data;

void output(data d[]) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d %d\n", d[i].start, d[i].end);
    printf("\n");
}

void exchange(data* d1, data* d2) {
    data p;
    p.start = d1->start;
    p.end = d1->end;
    d1->start = d2->start;
    d1->end = d2->end;
    d2->start = p.start;
    d2->end = p.end;
}

int Partition(data d[], int p, int r) {
    data *ptr = &d[r];
    int i = p - 1, j;
    for (j = p; j < r; j++) {
        if (d[j].start <= ptr->start) {
            i++;
            if (i != j) {
                exchange(&d[i], &d[j]);
            }
        }
    }
    if (i + 1 != r)
        exchange(&d[i + 1], &d[r]);
    return i + 1;
}

void QuickSort(data d[], int p, int r) {
    if (p < r) {
        int q = Partition(d, p, r);
        QuickSort(d, p, q - 1);
        QuickSort(d, q + 1, r);
    }
}

main() {
    FILE *fin = fopen("milk2.in", "r");
    FILE *fout = fopen("milk2.out", "w");
    data d[N];
    int i, t1 = 0, t2 = 0, base, up;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d %d", &d[i].start, &d[i].end);
    }
    //sort by start time
    QuickSort(d, 0, n - 1);
    base = d[0].start;
    up = d[0].end;
    t1 = d[0].end - d[0].start;
    for (i = 0; i < n - 1; i++) {
        if (d[i].end > up)
            up = d[i].end;
        if (d[i + 1].start > up)
            base = d[i + 1].start;
        t2 = t2 > d[i + 1].start - up ? t2 : d[i + 1].start - up;
        t1 = t1 > d[i + 1].end - base ? t1 : d[i + 1].end - base;
    }
    //output(d);
    //printf("%d %d\n", t1, t2);
    fprintf(fout, "%d %d\n", t1, t2);
    exit(0);
}