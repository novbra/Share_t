// Problem: Luogu P1002
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1002
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=22;
int g[N][N];
int kdx[]={-2,-2,-1,1,2,2,1,-1};
int kdy[]={-1,1,2,2,1,-1,-2,-2};
int dx[]={0,1};
int dy[]={1,0};
long long dp[N][N];
int endx,endy;
int knightx,knighty;
int main(){
	cin>>endx>>endy>>knightx>>knighty;
	
	g[knightx][knighty]=1;
	for(int i=0;i<8;i++){
		int nx=knightx+kdx[i],ny=knighty+kdy[i];
		if(nx<0||nx>20||ny<0||ny>20)	continue;
		g[nx][ny]=1;
	}
	
	dp[0][0]=1;
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(g[i][j]==1)	continue;
			for(int k=0;k<2;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(nx<0||nx>20||ny<0||ny>20)	continue;
				if(g[nx][ny]==1)	continue;
				dp[nx][ny]+=dp[i][j];
				//cout<<nx<<","<<ny<<":"<<dp[nx][ny]<<"\n";
			}
		}
	}
	/*
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
	
	cout<<dp[endx][endy];
	return 0;
}