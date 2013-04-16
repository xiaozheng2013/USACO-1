/*
ID: Yiting
LANG: C++
TASK: maze1 
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<iostream>
#include <fstream>
#include <queue>
#define HMAX 100
#define WMAX 38
#define MAX(a,b) ((a)>(b))?(a):(b)
#define MIN(a,b) ((a)<(b))?(a):(b)
using namespace std;
int w, h, res;
int shortest1[HMAX][WMAX], shortest2[HMAX][WMAX];
char maze[2 * HMAX + 1][2 * WMAX + 2];
int exits[2][2];
bool v[HMAX][WMAX];

struct Grid {
    int x, y;

    Grid(int i, int j) {
        this->x = i;
        this->y = j;
    }
};

queue< pair<struct Grid, int> >q;

void output() {
    int i, j;
    for (i = 0; i < 2 * h + 1; i++) {
        for (j = 0; j < 2 * w + 1; j++) {
            printf("(%d,%d)=%c, ", i, j, maze[i][j]);
        }
        printf("\n");
    }
}

void bfs(int x, int y, int shortest[HMAX][WMAX]) {
    q.push(make_pair(Grid(x, y), 1));
    while (!q.empty()) {
        pair<struct Grid, int> p = q.front();
        q.pop();
        struct Grid g = p.first;
        if (v[g.x][g.y])
            continue;
        v[g.x][g.y] = 1;
        shortest[g.x][g.y] = p.second;

        if (g.x != 0 && maze[2 * g.x][2 * g.y + 1] == ' ')
            q.push(make_pair(Grid(g.x - 1, g.y), p.second + 1));
        if ((g.x != (h - 1)) && (maze[(g.x + 1)*2][2 * g.y + 1] == ' '))
            q.push(make_pair(Grid(g.x + 1, g.y), p.second + 1));
        if (g.y != 0 && maze[2 * g.x + 1][2 * g.y] == ' ')
            q.push(make_pair(Grid(g.x, g.y - 1), p.second + 1));
        if ((g.y != (w - 1)) && maze[2 * g.x + 1][(g.y + 1)*2] == ' ') {
            q.push(make_pair(Grid(g.x, g.y + 1), p.second + 1));
        }
    }
}

main() {
    ofstream fout("maze1.out");
    ifstream fin("maze1.in");
    int i, j, e;
    fin >> w >> h;
    memset(exits, -1, sizeof (exits));
    for (i = 0; i < 2 * h + 1; i++) {
        for (j = 0; j < 2 * w + 1; j++) {
            do {
                fin.get(maze[i][j]);
            } while (maze[i][j] == '\n' || maze[i][j] == '\r');

            if ((i == 0 || i == 2 * h || j == 0 || j == 2 * w) && maze[i][j] == ' ') {
                e = (exits[0][0] == -1) ? 0 : 1;
                if (i == 2 * h)
                    exits[e][0] = h - 1;
                else
                    exits[e][0] = i / 2;
                if (j == 2 * w)
                    exits[e][1] = w - 1;
                else
                    exits[e][1] = j / 2;
            }
        }
    }

    bfs(exits[0][0], exits[0][1], shortest1);
    memset(v, 0, sizeof (v));
    bfs(exits[1][0], exits[1][1], shortest2);

    for (i = 0; i < h; i++) {
        for (j = 0; j < w; j++) {
            res = MAX(res, MIN(shortest1[i][j], shortest2[i][j]));
        }
    }
    fout << res << endl;
    exit(0);
}
