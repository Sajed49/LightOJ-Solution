#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int row, column;
int x[] = {0 , 0, 1, -1};
int y[] = {1 , -1, 0, 0};

int my[501][501];
char save[501][501];
int visited[501][501];
int result;

void dfs(int a, int b) {
    if(save[a][b]=='C')result++;
    visited[a][b]=1;

    for(int i=0; i<4; i++) {
        int x1 = a+x[i];
        int y1 = b+y[i];

        if(x1>-1 && x1<row && y1>-1 && y1<column && !visited[x1][y1] && save[x1][y1]!='#') dfs(x1, y1);
    }

}

void upResult(int a, int b) {
    my[a][b]= result;
    visited[a][b]=2;

    for(int i=0; i<4; i++) {
        int x1 = a+x[i];
        int y1 = b+y[i];
        if(x1>-1 && x1<row && y1>-1 && y1<column && visited[x1][y1]==1 && save[x1][y1]!='#') upResult(x1, y1);
    }

}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int a=1; a<=test; a++) {
        int total;
        scanf("%d %d %d", &row, &column, &total);


        for(int i=0; i<row; i++) scanf("%s", &save[i]);
        printf("Case %d:\n", a);

        memset(my, 0, sizeof(my));
        memset(visited, 0, sizeof(visited));

        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(save[i][j] != '#' && visited[i][j]==0) {
                    result=0;
                    dfs(i, j);
                    upResult(i,j);
                }
            }
        }


        //Queries
        for(int i=0; i<total; i++) {
            int x, y;
            scanf("%d %d", &x, &y);

            x--;
            y--;
            printf("%d\n", my[x][y]);

        }
    }
    return 0;
}
