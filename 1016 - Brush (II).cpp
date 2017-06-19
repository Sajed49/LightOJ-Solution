#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct node {
    int a,b;
};

bool cmp (node i, node j) {
    return i.b>j.b;
}

int main (void) {
    int test;
    scanf("%d", &test);

    for(int i=1; i<=test; i++) {
        int total, width;
        scanf("%d %d", &total, &width);

        node save[total];
        for(int j=0; j<total; j++) {
            scanf("%d %d", &save[j].a, &save[j].b);
        }

        sort(save, save+total, cmp);

        int counter =0;
        int flag = 2000000000;

        for(int j=0; j<total; j++) {
            if(save[j].b < flag) {
                counter++;
                flag=save[j].b - width;
            }
        }

        printf("Case %d: %d\n", i, counter);
    }
    return 0;
}
