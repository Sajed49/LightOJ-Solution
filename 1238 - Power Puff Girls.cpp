#include <bits/stdc++.h>

using namespace std;

struct node {
    char i;
    char j;
    int level;
};

int x [4] = { 0 , 0 ,1 ,-1};
int y [4] = { 1 , -1, 0, 0};

char save[20][21];
bool visited[20][21];
int row, column;
int result=0;


void bfs(int a, int b) {
    queue <node> flag;
    node my;
    my.i=a;
    my.j=b;
    my.level=0;
    visited[a][b]=true;
    flag.push(my);

    while(!flag.empty()) {
        my = flag.front();
        flag.pop();

        if(save[my.i][my.j]=='h') {
            if(result<my.level) result = my.level;
            break;
        }
        else {
            for(int i=0; i<4; i++) {
                int x1= x[i]+my.i;
                int y1= y[i]+my.j;
                if(x1>-1 && x1<row && y1>-1 && y1<column && visited[x1][y1]==false && (save[x1][y1] != '#' && save[x1][y1] != 'm')) {
                    node my1;
                    my1.i=x1;
                    my1.j=y1;
                    my1.level = my.level+1;
                    visited[my1.i][my1.j]=true;
                    flag.push(my1);
                }
            }
        }

    }

}

int main (void) {

    int test;
    scanf("%d", &test);

    for(int a=1; a<= test; a++){
        scanf("%d %d", &row, &column);
        result=0;
        //input
        for(int i=0; i<row; i++) scanf("%s", &save[i]);

        for(int i=0; i<row; i++) {
            for(int j=0; j<column; j++) {
                if(save[i][j]=='a' || save[i][j]=='b' || save[i][j]=='c' ) {
                    memset(visited, false , sizeof(visited));
                    bfs(i,j);
                }
            }
        }

        printf("Case %d: %d\n", a, result);
    }
    return 0;
}
