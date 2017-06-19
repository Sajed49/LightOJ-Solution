#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

vector <int> save[20001];
int visited[20001];
int tempHigh=0;
int team1 , team2;

void DFS (int source, int current, int team) {
    if(visited[source]==1) {
        visited[current]=2;
        team2++;
    }
    else {
        visited[current]=1;
        team1++;
    }

    int temp= save[current].size();
    for(int i=0; i<temp; i++) {
        if(visited[save[current][i]]==0) {
            DFS(current, save[current][i], visited[current]);
        }
    }
}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int a=1; a<=test; a++) {
        memset(visited, 0 , sizeof(visited));
        for(int i=0; i<20001; i++) save[i].clear();

        int total;
        scanf("%d", &total);
        for(int i=0; i<total; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            save[x].push_back(y);
            save[y].push_back(x);
        }


        int result=0;
        for(int i=0; i<20001; i++) {
            if(!visited[i] && save[i].size()>0 ) {
                team1=1, team2=0;
                visited[i]=1;

                int temp= save[i].size();
                for(int j=0; j<temp; j++) {
                    if(visited[save[i][j]]==0) DFS(i , save[i][j] , 1);
                }

                if(team1>team2) result+=team1;
                else result+=team2;

                team1=0;
                team2=0;
            }


        }

        printf("Case %d: %d\n",a , result);


    }
    return 0;
 }
