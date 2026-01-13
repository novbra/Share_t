// Problem: Luogu B3637
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/B3637
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=5005;
int n;
int a[N];
int dp[N];
int mem[N];
int dfs(int x){
	if(mem[x]>0){
		return mem[x];
	}
	int ans=1;
	for(int i=0;i<x;i++){
		if(a[i]<a[x]){
			ans=max(ans,dfs(i)+1);
		}
	}
	mem[x]=ans;
	return ans;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	/*
	int ans=1;
	for(int i=0;i<n;i++){
		int maximum=-1e9;
		for(int j=0;j<a[i];j++){
			maximum=max(maximum,dp[j]);
		}
		dp[a[i]]=maximum+1;
		//cout<<a[i]<<":"<<dp[a[i]]<<"\n";
		ans=max(ans,dp[a[i]]);
	}
	cout<<ans;
	*/
	
	int ans=0;
	for(int i=0;i<n;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(a[j]<a[i]){
				dp[i]=max(dp[i],dp[j]+1);
			}
		}
		ans=max(ans,dp[i]);
	}
	
	/*
	for(int i=0;i<n;i++){
		ans=max(ans,dfs(i));
	}
	*/
	cout<<ans;
	return 0;
}