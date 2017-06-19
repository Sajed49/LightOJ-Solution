#include <iostream>
#include <cstdio>

using namespace std;

int main (void) {
	ios_base::sync_with_stdio(false);

	int test;
	cin>>test;

	for(int a=1; a<=test; a++) {
		long long int num;
		cin>>num;


		if(num%2) printf("Case %d: Impossible\n",a);
		else {
			long long int temp = num/2;
			int flag=1;
			for(long long int i=2; i<=temp; i+=2) {
				if((num/i)*i == num && (num/i)%2) {
					printf("Case %d: %lld %lld\n", a, num/i , i);
					flag=0;
					break;
				}
			}
			if(flag) printf("Case %d: Impossible\n",a);
		}
	}
	return 0;
}
