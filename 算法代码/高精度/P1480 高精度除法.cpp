// Problem: Luogu P1480
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1480
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=5010;

string minus_bigdata(string s1,string s2){
	//该函数默认s1>s2
	int a1[N]={0},a2[N]={0},a3[N]={0};
	
	int len1=s1.size(),len2=s2.size(),len=max(len1,len2);
	for(int i=0;i<len1;i++)
		a1[i]=s1[len1-i-1]-'0';
	for(int i=0;i<len2;i++)
		a2[i]=s2[len2-i-1]-'0';
	for(int i=0;i<len;i++){
		if(a1[i]+a3[i]<a2[i]){
			a3[i+1]--;
			a3[i]+=10;
		}
		a3[i]=a3[i]+a1[i]-a2[i];
	}
	
	//减法需要寻找有效始位
	int index=0;
	
	for(int i=len-1;i>=0&&index==0;i--){
		if(a3[i]!=0)
			index=i;
	}
	string s;
	for(int i=index;i>=0;i--){
		s+=(char)(a3[i]+'0'); //不能使用下标赋值，因为s是空字符串，没有s[j]的下标位置
	}
	return s;
}

int main(){
	string s1,s2;
	int a1[N],a2[N],a3[N];
	cin>>s1>>s2;
	int len1=s1.size(),len2=s2.size();
	for(int i=0;i<len1;i++)
		a1[i]=s1[len1-i-1]-'0';
	for(int i=0;i<len2;i++)
		a2[i]=s2[len2-i-1]-'0';
	string r;
	for(int i=0;i<len1;i++){
		//i指向被除数
		//大数判断剩余数与除数的大小关系
		if(r!="0")
			r+=s1[i];
		else{
			r[0]=s1[i];
		}
		while(true){
			if(r.size()>len2||r.size()==len2&&r>=s2){
				r=minus_bigdata(r,s2);
				a3[i]++;
			}else
				break;
		}
	}
	int index=s1.size()-1;
	for(int i=0;i<s1.size();i++){
		if(a3[i]!=0){
			index=i;
			break;
		}
	}
	for(int i=index;i<s1.size();i++){
		cout<<a3[i];
	}
	return 0;
}