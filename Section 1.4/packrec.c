/*
ID: Yiting
LANG: C
TASK: packrec 
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define Max(a,b) ((a)>(b)?(a):(b));
#define INF 0x7FFFFFFF
#define NUM 4

typedef struct Rect {
    int w;
    int h;
} rect;

rect R[NUM], tempR[NUM], resultR[NUM];
bool used[NUM];
int area, numResult;
bool isSame;

void Exchange(rect *r) {
    int t;
    t = r->h;
    r->h = r->w;
    r->w = t;
}

void Judge(int w, int h) {
    int i;
    //make w the smaller one first.
    if (w > h) {
        w = w + h;
        h = w - h;
        w = w - h;
    }
    if (w * h <= area) {
        if (w * h == area) {
            for (i = 0; i < numResult; i++) {
                if (resultR[i].w == w)
                    return;
                if (resultR[i].w > w) {
                    memcpy(resultR + i + 1, resultR + i, sizeof (rect)*(numResult - i));
                    resultR[i].h = h;
                    resultR[i].w = w;
                    numResult++;
                    return;
                }
            }
            resultR[numResult].h = h;
            resultR[numResult++].w = w;
        } else {
            area = w*h;
            resultR[0].w = w;
            resultR[0].h = h;
            numResult = 1;
        }
    }

}

void Form() {
    int w, h;
    //case 1:
    w = tempR[0].w + tempR[1].w + tempR[2].w + tempR[3].w;
    h = Max(tempR[0].h, tempR[1].h);
    h = Max(h, tempR[2].h);
    h = Max(h, tempR[3].h);
    Judge(w, h);
    //case 2:
    w = Max(tempR[0].w + tempR[1].w + tempR[2].w, tempR[3].w);
    h = Max(tempR[0].h, tempR[1].h);
    h = tempR[3].h + Max(h, tempR[2].h);
    Judge(w, h);
    //case 3:
    w = tempR[3].w + Max(tempR[0].w + tempR[1].w, tempR[2].w);
    h = Max(tempR[0].h + tempR[2].h, tempR[1].h + tempR[2].h);
    h = Max(h, tempR[3].h);
    Judge(w, h);
    //case 4:
    w = tempR[0].w + tempR[3].w + Max(tempR[1].w, tempR[2].w);
    h = Max(tempR[0].h, tempR[1].h + tempR[2].h);
    h = Max(tempR[3].h, h);
    Judge(w, h);
    //case 5:
    //5.1
    if (tempR[1].h > tempR[2].h + tempR[3].h) {
        w = Max(tempR[0].w, tempR[1].w + tempR[2].w);
        w = Max(tempR[2].w + tempR[3].w, w);
    }
    //5.2
    if (tempR[2].h > tempR[3].h && tempR[2].h < tempR[1].h + tempR[3].h) {
        w = Max(tempR[0].w + tempR[1].w, tempR[1].w + tempR[2].w);
        w = Max(w, tempR[2].w + tempR[3].w);
    }
    //5.3
    if (tempR[2].h < tempR[3].h && tempR[3].h < tempR[0].h + tempR[2].h) {
        w = Max(tempR[0].w + tempR[1].w, tempR[0].w + tempR[3].w);
        w = Max(w, tempR[2].w + tempR[3].w);
    }
    //5.4
    if (tempR[3].h >= tempR[0].h + tempR[2].h) {
        w = Max(tempR[1].w, tempR[0].w + tempR[3].w);
        w = Max(w, tempR[2].w + tempR[3].w);
    }
    //5.5
    if (tempR[2].h == tempR[3].h) {
        w = Max(tempR[0].w + tempR[1].w, tempR[2].w + tempR[3].w);
    }
    h = Max(tempR[0].h + tempR[2].h, tempR[1].h + tempR[3].h);
    Judge(w, h);
}

void Rotate(int num) {
    if (num == NUM) {
        //go form the rectangle
        Form();
        return;
    }
    //Exchange(&tempR[num]);
    //Rotate(num + 1);
    //Exchange(&tempR[num]);
    Rotate(num + 1);
    Exchange(&tempR[num]);
    Rotate(num + 1);
}

void DFS(int num) {
    int i;
    if (num == NUM) {
        //rotate
        if (isSame)
            Form();
        else
            Rotate(0);
        return;
    }
    for (i = 0; i < NUM; i++) {//iteration of the four rectangles
        if (!used[i]) {
            used[i] = true;
            tempR[num] = R[i];
            DFS(num + 1);
            used[i] = false;
        }
    }
}

main() {
    FILE* fin = fopen("packrec.in", "rb");
    FILE* fout = fopen("packrec.out", "wb");

    int i;
    for (i = 0; i < NUM; i++) {
        fscanf(fin, "%d %d", &R[i].w, &R[i].h);
    }
    isSame = true;
    for (i = 0; i < NUM; i++) {
        if (R[i].h != R[i].w)
            isSame = false;
    }
    area = INF;
    numResult = 0;
    memset(used, 0, sizeof (used));

    DFS(0);
    fprintf(fout, "%d\n", area);
    for (i = 0; i < numResult; i++) {
        fprintf(fout, "%d %d\n", resultR[i].w, resultR[i].h);
    }
    fclose(fin);
    fclose(fout);
    exit(0);
}
