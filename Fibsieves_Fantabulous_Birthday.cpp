#include <bits/stdc++.h>

using namespace std;

int main (void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test;
    cin>>test;

    for(int a=1 ; a<=test; a++) {
        long long int num;
        cin>>num;

        long long int save1 = ceil(sqrt(num));
        long long int lowerLimit = pow(save1-1, 2)+1;
        long long int higherLimit= pow(save1, 2);

        long long int rowRight = ((higherLimit+lowerLimit)>>1);
        cout<<"Case "<<a<<": ";

        if(save1 & 1) {

            if(num >= rowRight) cout<<higherLimit-num+1<<" "<<save1<<endl;
            else cout<<save1<<" "<<num-lowerLimit+1<<endl;

        }
        else {

            if(num<= rowRight) cout<<num-lowerLimit+1<<" "<<save1<<endl;
            else cout<<save1<<" "<<higherLimit-num+1<<endl;
        }

    }
    return 0;
}
