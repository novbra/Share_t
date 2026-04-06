// Problem: Luogu P1601
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1601
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s1,s2; //用char数组会更快
	getline(cin,s1);
	getline(cin,s2);
	int a1[510],a2[510],a3[510]={0};
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++){
		a1[i]=s1[len1-i-1]-'0';
	}
	for(int i=0;i<s2.size();i++){
		a2[i]=s2[len2-i-1]-'0';
	}
	int len=max(len1,len2);
	for(int i=0;i<len;i++){
		a3[i]+=a1[i]+a2[i];
		if(a3[i]>=10){
			a3[i+1]=a3[i]/10;
			a3[i]=a3[i]%10;
		}
	}
	if(a3[len]!=0)
		cout<<a3[len];
	for(int i=len-1;i>=0;i--){
		
		cout<<a3[i];
	}
	return 0;
}