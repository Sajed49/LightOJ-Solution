#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
int x[] ={0 ,0 ,1 ,-1};
int y[] ={1 ,-1 ,0 ,0};
int w, h;
int result;
char save[22][22];

void DFS (int sourceX, int sourceY) {
    result++;
    save[sourceX][sourceY]='#';

    for(int i=0; i<4; i++) {
        int x1= sourceX+x[i];
        int y1= sourceY+y[i];

        if(x1>= 0 && x1<h && y1>=0 && y1<w && save[x1][y1]=='.') DFS(x1, y1);
    }

}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int a=1; a<=test; a++) {
        result=0;

        scanf("%d %d", &w, &h);

        int sourceX, sourceY;
        for(int i=0; i<h; i++) scanf("%s", &save[i]);

        //find source
        int flag=0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(save[i][j]== '@') {
                    sourceX= i;
                    sourceY= j;
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        DFS(sourceX, sourceY);

        printf("Case %d: %d\n",a, result);
    }
    return 0;
}
