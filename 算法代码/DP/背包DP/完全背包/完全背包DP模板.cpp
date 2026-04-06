#include <bits/stdc++.h>
using namespace std;

/*
	d[i][j]表示在背包容量为j下选择1,2,...,i物品的最大价值

0  1  2  3  4  5  6  7  8     j
-------------------------
0  0  0  0  0  0  0  0  0
1
2
3

i




*/
const int N=200,M=10000;
int dp[N][M];
int weight[N];
int value[N];
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>weight[i]>>value[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//判断能否加入
			if(j>=weight[i]){
				//不选                         Vs  选
				//不加这个物品且同等容量下的价值 Vs  该物品价值+本轮(因为是完全可以重复选所以是本轮)选择物品在容量=当前容量-该物品重量情况下能选到的最大价值
				//
				dp[i][j]=max(dp[i-1][j],dp[i][j-weight[i]]+value[i]);
			}else{
				//放不下, 继承 不加这个物品且同等容量下的价值
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}