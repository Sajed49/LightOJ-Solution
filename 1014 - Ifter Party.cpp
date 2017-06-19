#include <bits/stdc++.h>

using namespace std;

int main (void) {
    long long int test;
    cin>>test;

    for(long long int a=1; a<=test; a++) {
        long long int total,left;
        cin>>total>>left;
        total-=left;

        printf("Case %d:",a);
        if(total <= left) cout<<" impossible\n";
        else {
            vector <long long int> save;
            int temp = sqrt(total);

            for(long long int i=1; i<=temp; i++) {
                if((total%i)==0) {
                    if(i != total/i)save.push_back(i);
                    save.push_back(total/i);
                }
            }

            sort(save.begin(), save.end());
            long long int len= save.size();
            for(long long int i=0; i<len; i++) {
                if(save[i]> left)printf(" %d", save[i]);
            }
            putchar('\n');
        }
    }
    return 0;
}
