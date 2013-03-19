/*
ID: Yiting
LANG: C
TASK: crypt1 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1024

int checkInput(int a, int* inputs) {
    int temp = a, v;
    while (temp != 0) {
        v = temp % 10;
        if (inputs[v] == -1)
            return 0;
        temp = temp / 10;
    }
    return 1;
}

main() {
    FILE* fin = fopen("crypt1.in", "rb");
    FILE* fout = fopen("crypt1.out", "wb");

    int inputs[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int n, i, a, b, b1, b2, r, base = 10, count = 0, temp;
    fscanf(fin, "%d", &n);
    for (i = 0; i < n; i++) {
        fscanf(fin, "%d ", &temp);
        inputs[temp] = temp;
    }

    for (a = 111; a < 999; a++) {
        for (b = 11; b < 99; b++) {
            if (checkInput(a, inputs) && checkInput(b, inputs)) {
                b1 = b % base;
                if (a * b1 > 999) continue;
                b2 = b / base;
                if (a * b2 > 999) continue;
                r = a * b1 + a * b2 * base;
                if (a * b > 9999) continue;
                if (checkInput(a * b, inputs) &&
                        checkInput(a * b1, inputs) &&
                        checkInput(a * b2, inputs))
                    count++;
            }
        }
    }
    fprintf(fout, "%d\n", count);
    fclose(fin);
    fclose(fout);
    exit(0);
}
