// Problem: Luogu P1303
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1303
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2010;
int main(){
	string s1,s2;
	int a1[N]={0},a2[N]={0},a3[2*N]={0};
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++)
		a1[i]=s1[len1-1-i]-'0';
	for(int i=0;i<len2;i++)
		a2[i]=s2[len2-1-i]-'0';
	for(int i=0;i<len2;i++){
		for(int j=0;j<len1;j++){
			a3[i+j]+=a1[j]*a2[i];
			//可以先不进位，而是都加上以后再逐个进位
		}
	}
	
	for(int i=0;i<len1+len2;i++)
		if(a3[i]>=10){
			a3[i+1]+=a3[i]/10;
			a3[i]=a3[i]%10;
		}
	//99*99->9801      结果位数不超过a和b的位数总和
	
	int index=0;
	for(int i=s1.size()+s2.size()-1;i>=0&&index==0;i--)
		if(a3[i]!=0)
			index=i;
	for(int i=index;i>=0;i--)
		cout<<a3[i];
	return 0;
}