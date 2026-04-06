#include <bits/stdc++.h>
using namespace std;
int main(){
	string text;
	string target;
	cin>>text>>target;
	int cnt=0;
	size_t pos=0;
	while((pos=text.find(target,pos))!=string::npos){
		cout<<pos<<"\n";
		cnt++;
		
		pos+=target.size();
	}
	cout<<cnt;
	return 0;
}