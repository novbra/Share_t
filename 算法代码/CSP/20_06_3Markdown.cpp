#include <bits/stdc++.h>
using namespace std;

bool spaceline(string line){
	for(int i=0;i<line.size();i++){
		if(line[i]!=' '){
			return false;
		}
	}
	return true;
}

int main(){
	int w;//行宽
	cin>>w;
	cin.ignore();
	string line;
	string paragraph;
	/*
		输入多行字符串是一次性输入的，不用担心getline退出不了，或者说输入一行就退出
	*/
	int cnt=0;
	while(getline(cin,line)){
		if(!spaceline(line)){
			cnt++;
		}
	}
	

	cout<<cnt*2-1;
	return 0;
}