// Problem: Luogu P1164
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1164
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
DEBUG
切记DP二维数组的第一维和第二维开的大小不一定是一样的，一定要认真读题
*/
#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int M=10005;
int n,m;
int c[N];
//int dp[N][M];
int f[M];//空间压缩
int dfs(int index,int left){
	if(left==0)	return 1;
	if(index>n)	return 0;
	int sum=dfs(index+1,left);
	if(left>=c[index])
		sum+=dfs(index+1,left-c[index]);
	return sum;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	//cout<<dfs(1,m);
	/*
	for(int i=n+1;i>=1;i--){
		for(int j=0;j<=m;j++){
			//j表示剩多少钱
			if(j==0)	dp[i][j]=1;
			else{
				dp[i][j]=dp[i+1][j];
				if(j>=c[i])	{
					dp[i][j]+=dp[i+1][j-c[i]];
				}
			}
		}
	}
	*/
	//dp 空间压缩
	for(int i=n+1;i>=1;i--){
		for(int j=m;j>=0;j--){
			//j表示剩多少钱
			if(j==0)	f[j]=1;
			else{
				f[j]=f[j];
				if(j>=c[i])	{
					f[j]+=f[j-c[i]]; //左侧赋值给右侧 只能从右侧开始往左侧遍历覆盖
				}
			}
		}
	}
	cout<<f[m];
	return 0;
}