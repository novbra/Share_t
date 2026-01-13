// Problem: Luogu P1130
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1130
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2005;
int n,m;//n步数, m小组数
int a[N][N];
int dp[N][N];
int f[N];
int g[N];
int dfs(int step,int groupID){
	if(step>n)	return 0;
	return a[groupID][step]+min(dfs(step+1,groupID),dfs(step+1,groupID%m+1));
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	/* dfs版本超时
	int ans=0x3f3f3f3f;
	for(int i=0;i<m;i++){
		ans=min(ans,dfs(i,1));
	}
	*/
	/* dp 逆序版
	for(int i=n;i>=1;i--){
		// i:step
		for(int j=1;j<=m;j++){
			// j:groupID
			dp[i][j]=a[j][i]+min(dp[i+1][j],dp[i+1][j%m+1]); //空间压缩的话，最后一个要使用到第一个元素，但是第一个元素已经被覆盖了
		}
	}
	*/
	
	//空间压缩
	for(int i=n;i>=1;i--){
		// i:step
		for(int j=1;j<=m;j++){
			// j:groupID
			g[j]=a[j][i]+min(f[j],f[j%m+1]);
		}
		memcpy(f,g,sizeof f);
	}
	
	int ans=0x3f3f3f3f;
	for(int i=1;i<=m;i++){
		if(f[i]>0)	ans=min(ans,f[i]);
	}
	cout<<ans<<"\n";
	return 0;
}