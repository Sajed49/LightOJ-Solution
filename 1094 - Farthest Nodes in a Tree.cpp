#include <bits/stdc++.h>

using namespace std;

struct node {
    int a;
    long long int cost;
};

void dfs(int source, vector <node> *save, bool *visited, long long int *rate) {

    visited[source] = 1;
    int temp = save[source].size();

    for(int i=0; i<temp; i++) {
        if( !visited[save[source][i].a]) {
                rate[save[source][i].a] = rate[source]+save[source][i].cost;
                dfs(save[source][i].a, save , visited, rate);
        }
    }

}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int a=1; a<=test; a++) {

        int total;
        scanf("%d", &total);


        vector <node> save[total];

        bool visited[30001];
        memset(visited, 0, sizeof(visited));
        long long rate[30001];
        memset(rate, 0, sizeof(rate));
        int source = -1; //fake source


        for(int i=1; i<total; i++) {
            int x, y;
            long long int cost;
            scanf("%d %d %lld", &x, &y, &cost);

            if(i==1) source=x;


            node temp;
            temp.a= y;
            temp.cost= cost;

            save[x].push_back(temp);

            temp.a= x;
            save[y].push_back(temp);
        }


        dfs(source, save , visited, rate);

        long long int high=-1;
        source=-1;
        for(int i=0; i<total; i++) {
            if(rate[i]>high) {
                high = rate[i];
                source = i;//
            }
        }

        for(int i=0; i<total; i++) rate[i]=0;
        for(int i=0; i<total; i++) visited[i]=0;

        dfs(source, save , visited, rate);

        high=-1;
        for(int i=0; i<total; i++) {
            if(rate[i]>high) {
                high = rate[i];
            }
        }
        printf("Case %d: %lld\n", a, high);

    }
    return 0;
}
