/*
ID: Yiting
LANG: C
TASK: clocks 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int current[9], result[30], temp[30] = {1}, used[10];
int res_count = 30;

typedef enum pos {
    A = 0, B, C, D, E, F, G, H, I
} p;

void Operation(p X) {
    current[X] = (current[X] + 1) % 4;
}

void Move(int i) {
    switch (i) {
        case 1://ABDE
            Operation(A);
            Operation(B);
            Operation(D);
            Operation(E);
            break;
        case 2://ABC
            Operation(A);
            Operation(B);
            Operation(C);
            break;
        case 3://BCEF
            Operation(B);
            Operation(C);
            Operation(E);
            Operation(F);
            break;
        case 4://ADG
            Operation(A);
            Operation(D);
            Operation(G);
            break;
        case 5://BDEFH
            Operation(B);
            Operation(D);
            Operation(E);
            Operation(F);
            Operation(H);
            break;
        case 6://CFI
            Operation(C);
            Operation(F);
            Operation(I);
            break;
        case 7://DEGH
            Operation(D);
            Operation(E);
            Operation(G);
            Operation(H);
            break;
        case 8://GHI
            Operation(G);
            Operation(H);
            Operation(I);
            break;
        case 9://EFHI
            Operation(E);
            Operation(F);
            Operation(H);
            Operation(I);
            break;
    }
}

bool check() {
    int i;
    for (i = 0; i < 9; i++) {
        if (current[i] != 0)
            return false;
    }
    return true;
}

void DFS(int cur) {
    if (cur - 1 >= res_count) return;
    if (check()) {
        res_count = cur - 1;
        int i;
        for (i = 1; i <= res_count; i++)
            result[i] = temp[i];
        return;
    }
    int i, j;
    for (i = temp[cur - 1]; i <= 9; i++) {
        if (used[i] >= 3)continue;
        Move(i);
        used[i]++;
        temp[cur] = i;
        DFS(cur + 1);
        for (j = 0; j < 3; j++)
            Move(i);
        used[i]--;
    }
}

main() {
    FILE* fin = fopen("clocks.in", "rb");
    FILE* fout = fopen("clocks.out", "wb");
    int i, j;
    for (i = 0; i < 9; i++) {
        fscanf(fin, "%d", current + i);
        current[i] = (current[i] / 3) % 4;
    }
    DFS(1);
    for (i = 1; i < res_count; i++) {
        fprintf(fout, "%d ", result[i]);
    }
    fprintf(fout, "%d\n", result[i]);
    fclose(fin);
    fclose(fout);
    exit(0);
}
