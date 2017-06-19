#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main (void) {
	int test;
	cin>>test;
	
	for(int a=1; a<=test; a++) {
		printf("Case %d:\n", a);
		
		stack <string> s1, s2;
		s1.push("http://www.lightoj.com/");
		
		string temp;
		do {
			cin>>temp;
			if(temp=="VISIT") {
				
				while(!s2.empty()) s2.pop();
				
				cin>>temp;
				cout<<temp<<endl;
				s1.push(temp);
			}
			else if(temp=="BACK") {
				if(s1.size()>1) {
					string temp2= s1.top();
					s1.pop();
					s2.push(temp2);
					cout<<s1.top()<<endl; 
				}
				else cout<<"Ignored\n";
			}
			else if(temp=="FORWARD") {
				if(s2.size()>0) {
					cout<<s2.top()<<endl;
					string temp2= s2.top();
					s2.pop();
					s1.push(temp2);				
				}
				else cout<<"Ignored\n";
			}
			
		}while (temp != "QUIT");
	}
	return 0;
}
