#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;
bool matrix[102][102];
int node, total;

void bfs(int source, bool* color, int* level) {
    int mine[100];
    memset(mine, 0, sizeof(mine));

    queue <int> my;

    my.push(source);
    mine[source]+=0;
    color[source]= 1;

    while(!my.empty()) {
        source= my.front();

        for(int i=0; i<node; i++) {
            if(matrix[source][i] && !color[i]) {
                my.push(i);
                color[i]= 1;
                mine[i]=mine[source]+1;
            }
        }
        my.pop();
    }

    for(int i=0; i<node ; i++) level[i]+= mine[i];
}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int a=1; a<=test; a++) {

        memset(matrix, 0, sizeof(matrix));


        scanf("%d %d", &node , &total);

        for(int i=0; i<total; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            matrix[x][y]=1;
            matrix[y][x]=1;
        }
        int first, last;
        scanf("%d %d", &first, &last);


        //first
        bool color[100];
        int level[100];
        memset(color, 0, sizeof(color));
        memset(level, 0, sizeof(level));

        bfs(first ,color,  level);

        //last

        memset(color, 0, sizeof(color));

        bfs(last ,color,  level);

        int high=-1;
        for(int i=0; i<node; i++) {
            if(high< level[i]) high=level[i];
        }

        printf("Case %d: %d\n", a, high);
    }

    return 0;
}
