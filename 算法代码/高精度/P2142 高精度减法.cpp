// Problem: Luogu P2142
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2142
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*

	洛谷用两个getline，无法AC，不知道为什么。网上评论都是这样。换成cin就可以了
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int a1[10087]={0},a2[10087]={0},a3[10087]={0};
	string s1,s2;
	//getline(cin,s1);
	//getline(cin,s2);
	cin>>s1>>s2;

	//大的放在被减数，小的放在减数
	char flag='+';
	if(s1.size()<s2.size()||(s1.size()==s2.size()&&s1<s2)){
		swap(s1,s2);
		flag='-';
	}
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
	if(flag=='-')
		cout<<flag;
	//减法需要寻找有效始位
	int index=0;
	
	for(int i=len-1;i>=0&&index==0;i--){
		if(a3[i]!=0)
			index=i;
	}
	for(int i=index;i>=0;i--)
		cout<<a3[i];
	return 0;
}