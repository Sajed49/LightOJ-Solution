#include <iostream>
#include <string>
#include <cstdio>
#include <list>

using namespace std;

int main (void) {
	int test;
	cin>>test;
	
	for(int a=1; a<=test; a++) {
		printf("Case %d:\n",a);
		list <int> save;
		
		int sum, total;
		cin>>sum>>total;
		
		for(int i=0; i<total; i++) {
			string temp;
			cin>>temp;
			
			if(temp=="pushLeft") {
				int in;
				cin>>in;
				if(save.size() == sum) cout<<"The queue is full\n";
				else{
					save.push_front(in);
					cout<<"Pushed in left: "<<in<<endl;
				}
			}
			else if(temp=="pushRight") {
				int in;
				cin>>in;
				if(save.size() == sum) cout<<"The queue is full\n";
				else {
					save.push_back(in);
					cout<<"Pushed in right: "<<in<<endl;;
				}
			}
			else if(temp=="popLeft") {
				if(save.size() == 0) cout<<"The queue is empty\n";
				else {
					int in=save.front();
					save.pop_front();
					cout<<"Popped from left: "<<in<<endl;;
				}
			}
			else {
				if(save.size() == 0) cout<<"The queue is empty\n";
				else {
					int in=save.back();
					save.pop_back();
					cout<<"Popped from right: "<<in<<endl;;
				}
			}
		}
			
	}
		
	return 0;
}
