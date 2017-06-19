#include <iostream>
#include <algorithm>

using namespace std;

struct node {
	int a, b;
};

bool cmp (node i, node j) {
	if(i.b==j.b) return i.a>j.a;
	return i.b < j.b;
}

int countFactor(int x) {
	int counter=0;
	for(int i=1; i<=x ; i++) {
		if(!(x%i)) counter++;
	}
	return counter;
}

int main (void) {
	int test;
	cin>>test;
	
	//precalculate
	node save[1001]; 
	for(int i=1; i<1001; i++) save[i].a=i;
	
	for(int i=1; i<1001; i++) {
		save[i].b = countFactor(i);
	}
	
	sort(save+1, save+1001, cmp);
	for(int a=1; a<=test; a++) {
		int temp;
		cin>>temp;
		
		cout<<"Case "<<a<<": "<<save[temp].a<<endl;
	}
	return 0;
}
