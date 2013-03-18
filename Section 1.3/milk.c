/*
ID: Yiting
LANG: C
TASK: barn1
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 200
#define POSITION 1
#define VALUE 2

typedef struct PV {
    int position;
    int value;
} pv;

void Exc(void* p1, void* p2, int size) {
    char buf[size];
    memcpy(buf, p1, size);
    memcpy(p1, p2, size);
    memcpy(p2, buf, size);
}

int Partition(pv P[MAX], int p, int r, int k) {
    int x = (k == 1) ? P[r].position : P[r].value, i = p - 1, j;
    for (j = p; j < r; j++) {
        int temp = (k == 1) ? P[j].position : P[j].value;
        if (temp > x) {
            i++;
            if (i != j)
                Exc(&P[i], &P[j], sizeof (pv));
        }
    }
    if (i + 1 != r)
        Exc(&P[i + 1], &P[r], sizeof (pv));
    return i + 1;
}

void Quicksort(pv P[MAX], int p, int r, int k) {
    if (p < r) {
        int q = Partition(P, p, r, k);
        Quicksort(P, p, q - 1, k);
        Quicksort(P, q + 1, r, k);
    }
}

int Partition1(int P[MAX], int p, int r) {
    int x = P[r], j, i = p - 1;
    for (j = p; j < r; j++) {
        if (P[j] < x) {
            i++;
            if (i != j)
                Exc(&P[i], &P[j], sizeof (int));
        }
    }
    if (i + 1 != r)
        Exc(&P[i + 1], &P[r], sizeof (int));
    return i + 1;
}

void Quicksort1(int P[MAX], int p, int r) {
    if (p < r) {
        int q = Partition1(P, p, r);
        Quicksort1(P, p, q - 1);
        Quicksort1(P, q + 1, r);
    }
}

main() {
    FILE *fin = fopen("barn1.in", "r");
    FILE *fout = fopen("barn1.out", "w");

    int M, S, C, i, total = 0;
    int stall[MAX];
    pv adjacent[MAX - 1];
    fscanf(fin, "%d %d %d", &M, &S, &C);
    if (M >= C) {
        fprintf(fout, "%d\n", C);
        exit(0);
    }
    for (i = 0; i < C; i++)
        fscanf(fin, "%d", &stall[i]);
    //sort the stall first
    Quicksort1(stall, 0, C - 1);

    if (M == 1) {
        fprintf(fout, "%d\n", stall[C - 1] - stall[0] + 1);
        exit(0);
    }
    for (i = 0; i < C - 1; i++) {
        adjacent[i].position = i;
        adjacent[i].value = stall[i + 1] - stall[i];
    }
    //find the 1st, 2nd, 3rd ... Mth number in array adjacent 
    pv temp[MAX - 1], result[MAX - 1];
    memcpy(temp, adjacent, sizeof (adjacent));
    Quicksort(temp, 0, C - 2, VALUE);
    memcpy(result, temp, sizeof (pv)*(M - 1));
    Quicksort(result, 0, M - 2, POSITION);

    for (i = M - 2; i >= 0; i--) {
        if (i == M - 2)
            total = total + stall[result[i].position] - stall[0] + 1;
        else
            total = total + stall[result[i].position] - stall[result[i + 1].position + 1] + 1;
        if (i == 0)
            total = total + stall[C - 1] - stall[result[i].position + 1] + 1;
    }
    fprintf(fout, "%d\n", total);
    exit(0);
}
