#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main (void) {
	int test;
	scanf("%d", &test);
	
	for(int j=1; j<= test; j++) {
		printf("Case %d:\n",j);
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2 , &y2);
		
		int total;
		scanf("%d", &total);
		
		int a, b;
		for(int i=0; i<total; i++) {
			scanf("%d %d", &a, &b);
			if(a>x2 || a<x1 || b>y2 || b<y1) printf("No\n");
			else printf("Yes\n");
					
		}
	}
	return 0;
}	
