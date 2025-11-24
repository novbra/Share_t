// Problem: 跳台阶
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/823/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
using namespace std;
const int N=100;
//int dp[N];
int n;
int main(){
	cin>>n;
	int a=1,b=2,c;//优化空间
	//dp[1]=1;
	//dp[2]=2;
	//第i阶台阶，要么是从第i-1台阶上来，要么是从第i-2阶上来
	//O(n)
	if(n==1){
		cout<<a;
		return 0;
	}
	if(n==2){
		cout<<b;
		return 0;
	}
	FOR(i,3,n+1){
		//dp[i]=dp[i-1]+dp[i-2];
		c=a+b;
		a=b;
		b=c;
	}
	//cout<<dp[n];
	cout<<b<<"\n";
	return 0;
}