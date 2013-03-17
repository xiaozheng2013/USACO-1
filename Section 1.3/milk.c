/*
ID: Yiting
LANG: C
TASK: milk
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000

typedef struct PA {
    int P;
    int A;
} pa;

void Exchange(pa *P1, pa *P2) {
    int p, a;
    p = P1->P;
    a = P1->A;
    P1->P = P2->P;
    P1->A = P2->A;
    P2->P = p;
    P2->A = a;
}

int Partition(pa P[MAX], int p, int r) {
    int x = P[r].P, i = p - 1, j;
    for (j = p; j < r; j++) {
        if (P[j].P < x) {
            i++;
            if (i != j)
                Exchange(&P[i], &P[j]);
        }
    }
    if (i + 1 != r)
        Exchange(&P[i + 1], &P[r]);
    return i + 1;
}

void Quicksort(pa P[MAX], int p, int r) {
    if (p < r) {
        int q = Partition(P, p, r);
        Quicksort(P, p, q - 1);
        Quicksort(P, q + 1, r);
    }
}

main() {
    FILE* fin = fopen("milk.in", "r");
    FILE* fout = fopen("milk.out", "w");

    int N, M, i, number = 0, amount = 0;
    pa P[MAX];
    fscanf(fin, "%d %d", &N, &M);
    for (i = 0; i < M; i++) {
        fscanf(fin, "%d %d", &P[i].P, &P[i].A);
    }
    //first, sort by Price
    Quicksort(P, 0, M - 1);

    //then scan from the first set of data
    for (i = 0; i < M; i++) {
        if (number + P[i].A <= N) {
            number = number + P[i].A;
            amount = amount + P[i].P * P[i].A;
        } else {
            amount = amount + P[i].P * (N - number);
            break;
        }
    }
    fprintf(fout, "%d\n", amount);
    exit(0);
}