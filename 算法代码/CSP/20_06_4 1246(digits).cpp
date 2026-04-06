#include <bits/stdc++.h>
using namespace std;
int main(){
	map<char,string> m;
	m['1']="2";
	m['2']="4";
	m['4']="16";
	m['6']="64";
	
	int n;
	string s;
	cin>>n>>s;
	
	string t="1";
	cout<<t<<"\n";
	for(int r=0;r<n;r++){
		string tmp="";
		for(int i=0;i<t.size();i++){
			tmp+=m[t[i]];
		}
		t=tmp;
		cout<<t<<"\n";
	}
	
	int cnt=0;
	size_t pos=0;
	while((pos=t.find(s,pos))!=string::npos){
		cnt++;
		pos+=s.size();
	}
	
	cout<<cnt;
	
	return 0;
}