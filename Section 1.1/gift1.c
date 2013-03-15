/*
ID: Yiting
LANG: C
TASK: gift1
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int findName(char names[10][14], char name[14], int NP) {
    int i;
    for (i = 0; i < NP; i++) {
        if (strcmp(names[i], name) == 0) {
            return i;
        }
    }
    return -1;
}

main() {
    FILE* fin = fopen("gift1.in", "r");
    FILE* fout = fopen("gift1.out", "w");
    int NP, i, j, give, giveTo, change;
    int money[10] = {0};
    char names[10][14], tempName[14];
    fscanf(fin, "%d", &NP);
    for (i = 0; i < NP; i++)
        fscanf(fin, "%s", names[i]);
    while (1) {
        if (fscanf(fin, "%s", tempName) != EOF) {
            fscanf(fin, "%d %d", &give, &giveTo);
            if (give != 0 && giveTo != 0) {
                change = give % giveTo;
                money[findName(names, tempName, NP)] -= give;
                money[findName(names, tempName, NP)] += change;
                give = (give - change) / giveTo;
                for (j = 0; j < giveTo; j++) {
                    fscanf(fin, "%s", tempName);
                    money[findName(names, tempName, NP)] += give;
                }
            } else if (give != 0 && giveTo == 0) {
                money[findName(names, tempName, NP)] += give;
            }
        } else {
            break;
        }
    }
    for (i = 0; i < NP; i++) {
        fprintf(fout, "%s %d\n", names[i], money[i]);
    }
    exit(0);
}