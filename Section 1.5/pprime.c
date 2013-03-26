/*
ID: Yiting
LANG: C++
TASK: pprime 
 */
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <math.h>
using namespace std;

FILE* fin = fopen("pprime.in", "rb");
FILE* fout = fopen("pprime.out", "wb");

//void setPrime(int count) {
//    int p = 2, i, j;
//    prime[0] = false, prime[1] = false;
//    for (i = 2; i <= count; i++)
//        prime[i] = true;
//    for (i = 2; i <= (int) sqrt(count); i++) {
//        if (prime[i]) {
//            for (j = i * i; j <= count; j += i) {
//                prime[j] = false;
//            }
//        }
//    }
//}

bool isPrime(int p) {
    if (p % 2 == 0 || p < 1) return false;

    int len = sqrt(p * 1.0);

    for (int i = 3; i <= len; i += 2) if (p % i == 0) return false;
    return true;
}

void Palindromes_1(int a, int b) {
    int i;
    for (i = 2; i < 10; i++) {
        if (i >= a && i <= b && isPrime(i))
            fprintf(fout, "%d\n", i);
    }
}

void Palindromes_2(int a, int b) {
    int i, p;
    for (i = 1; i < 10; i++) {
        p = 10 * i + i;
        if (p >= a && p <= b && isPrime(p))
            fprintf(fout, "%d\n", p);
    }
}

void Palindromes_3(int a, int b) {
    int i, j, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            p = 100 * i + 10 * j + i;
            if (p > b) return;
            if (p >= a && p <= b && isPrime(p)) {
                fprintf(fout, "%d\n", p);
            }
        }
    }
}

void Palindromes_4(int a, int b) {
    int i, j, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            p = 1000 * i + 100 * j + 10 * j + i;
            if (p > b) return;
            if (p >= a && p <= b && isPrime(p)) {
                fprintf(fout, "%d\n", p);
            }
        }
    }
}

void Palindromes_5(int a, int b) {
    int i, j, k, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            for (k = 0; k <= 9; k++) {
                p = i + 10 * j + 100 * k + 1000 * j + 10000 * i;
                if (p > b) return;
                if (p >= a && p <= b && isPrime(p)) {
                    fprintf(fout, "%d\n", p);
                }
            }
        }
    }
}

void Palindromes_6(int a, int b) {
    int i, j, k, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            for (k = 0; k <= 9; k++) {
                p = i + 10 * j + 100 * k + 1000 * k + 10000 * j + 100000 * i;
                if (p > b) return;
                if (p >= a && p <= b && isPrime(p)) {
                    fprintf(fout, "%d\n", p);
                }
            }
        }
    }
}

void Palindromes_7(int a, int b) {
    int i, j, k, l, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            for (k = 0; k <= 9; k++) {
                for (l = 0; l <= 9; l++) {
                    p = i + 10 * j + 100 * k + 1000 * l + 10000 * k
                            + 100000 * j + 1000000 * i;
                    if (p > b) return;
                    if (p >= a && p <= b && isPrime(p)) {
                        fprintf(fout, "%d\n", p);
                    }
                }

            }
        }
    }
}

void Palindromes_8(int a, int b) {
    int i, j, k, l, p;
    for (i = 1; i <= 9; i += 2) {
        for (j = 0; j <= 9; j++) {
            for (k = 0; k <= 9; k++) {
                for (l = 0; l <= 9; l++) {
                    p = i + 10 * j + 100 * k + 1000 * l + 10000 * l
                            + 100000 * k + 1000000 * j + 10000000 * i;
                    if (p > b) return;
                    if (p >= a && p <= b && isPrime(p)) {
                        fprintf(fout, "%d\n", p);
                    }
                }

            }
        }
    }
}

main() {
    int a, b, i;
    fscanf(fin, "%d %d", &a, &b);
    //setPrime(b);
    Palindromes_1(a, b);
    Palindromes_2(a, b);
    Palindromes_3(a, b);
    Palindromes_4(a, b);
    Palindromes_5(a, b);
    Palindromes_6(a, b);
    Palindromes_7(a, b);
    Palindromes_8(a, b);
    fclose(fin);
    fclose(fout);
    exit(0);
}
