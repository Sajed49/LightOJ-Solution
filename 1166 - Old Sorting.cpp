#include <bits/stdc++.h>

using namespace std;

int main (void) {
    int test;
    cin>>test;

    for(int a=1; a<=test; a++) {
        int num;
        int save[1000];

        cin>>num;
        for(int i=0; i<num; i++) cin>>save[i];

        int result=0;

        for(int i=0; i<num-1; i++) {
            int low = i+1;
            for(int j=i+1; j<num; j++) {
                if(save[low] > save[j]) low= j;
            }

            if(save[low] < save[i]) {
                swap(save[i], save[low]);
                result++;
            }
        }
        cout<<"Case "<<a<<": "<<result<<endl;
    }

    return 0;
}
