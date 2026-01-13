// Problem: 1. 李白打酒加强版
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/2114/learning/?page=1&first_category_id=1&problem_id=2114
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=105,P=1e9+7;
int n,m;
//酒的最大数量不能大于花的数量

//二维DP

ll dp[N][N][N];

int dfs(int shop,int flower,int alcohol){
	if(shop==n&&flower==m&&alcohol==0)	return 1;
	if(shop>n||flower==m)	return 0;
	int sum=0;
	//遇花
	if(alcohol>0){
		sum+=dfs(shop,flower+1,alcohol-1);
	}
	//遇店
	sum+=dfs(shop+1,flower,alcohol*2);
	return sum;
}

int main(){
	cin>>n>>m;
	//cout<<dfs(0,0,2);
	dp[0][0][2]=1;
	for(int i=0;i<=n;i++){
		for(int j=0;j<m;j++){
			for(int k=0;k<=m;k++){
				
				ll& v=dp[i][j][k];
				//这道题要取余数存储 这里顺推，由于值是叠加的取模，这里不太容易
				
				//遇店              见花
				if(i>0&&j>0&&k%2==0){
					v=(dp[i-1][j][k/2]+dp[i][j-1][k+1])%P; //i-1和j-1维度都在ij之前就遍历完了
				}else if(i>0&&j<=0&&k%2==0){
					v=dp[i-1][j][k/2];
				}else if(j>0){
					v=dp[i][j-1][k+1];
				}
				
				
				//5%3=2
				//7%3=1
				//(5+7)%3=0
				//(2+1)%3=0
				/*
				
				dp[i+1][j][k*2]=(dp[i+1][j][k*2]%P+v%P)%P;
				
				if(k>0)	{
					dp[i][j+1][k-1]=(dp[i][j+1][k-1]%P+v%P)%P;
				}
				//cout<<i+1<<","<<j<<","<<k*2<<"\n";
				*/
			}
		}
	}
	cout<<dp[n][m-1][1];
	return 0;
}