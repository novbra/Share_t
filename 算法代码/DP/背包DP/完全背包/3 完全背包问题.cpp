// Problem: 完全背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/3/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,v;
int vi[N];
int wi[N];

int dp[N];
int dfs(int x,int spV){
	if(x>n)	return 0;
	if(spV<vi[x])	return dfs(x+1,spV);
	return max(dfs(x+1,spV),dfs(x,spV-vi[x])+wi[x]);
}
int main(){
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>vi[i]>>wi[i];
	}
	//cout<<dfs(1,v);
	for(int i=n;i>=1;i--){
		for(int j=vi[i];j<=v;j++){
			dp[j]=max(dp[j],dp[j-vi[i]]+wi[i]);
		}
	}
	cout<<dp[v];
	return 0;
}