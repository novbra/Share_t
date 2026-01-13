// Problem: 1. 翻转
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/18427/learning/?page=1&first_category_id=1&problem_id=18427
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
string s[N];
int dp[N][2]; //0 不翻转 1 翻转
int main(){
	cin>>n;
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	dp[1][0]=2;
	dp[1][1]=2;
	for(int i=2;i<=n;i++){//4e5
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				//k: 上一个是否翻转 j: 本个是否翻转
				int len=dp[i-1][k];
				if(s[i-1][1-k]==s[i][j]){
					dp[i][j]=min(dp[i][j],len+1);
				}else{
					dp[i][j]=min(dp[i][j],len+2);
				}
			}
			//cout<<i<<","<<j<<":"<<dp[i][j]<<"\n";
		}
	}
	cout<<min(dp[n][0],dp[n][1]);
	return 0;
}