// Problem: 01背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/2/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int v[N];
int w[N];
int n,V;
int dp[N];

int dfs(int x,int spV){
	if(x>n)	return 0;
	//该轮选择物品的体积>spV，选择不了，继续向下找
	if(spV<v[x]){
		return dfs(x+1,spV);
	}else{
		//该轮选择物品的体积<=spV,选择或不选择
		return max(dfs(x+1,spV-v[x])+w[x],dfs(x+1,spV));
	}
}
//dfs->记忆化->逆序dp->正序dp->空间压缩(2D->1D)
//只用一个f[N]数组，能不能写这个题         f[N]就称为滚动数组
int main(){
	cin>>n>>V;
	for(int i=1;i<=n;i++){
		cin>>v[i]>>w[i];
	}
	//cout<<dfs(1,V);
	
	
	//倒着递推，是从n->1    ,正着递推只需要将for i=1， 然后将dp[i+1]改为dp[i-1]，输出cout<<dp[n][V], 为什么是dp[n][V]呢因为正序的话,选1的时候，这个时没有剩余了，而推到n层时，这个时候还有V剩余，因为他才是头
	//正序就是把逆序的递归树倒着看， 本来逆序看[1][V], 正序是逆序的倒着就是[n][V]
	for(int i=n;i>=1;i--){
		for(int j=V;j>=0;j--){
			//(5,0..V)-(1,0..V)
			//V取的是全集，不同于dfs往下对v有舍
			if(j<v[i]){//j是剩余体积,
				dp[j]=dp[j];
			}else{//够装 有2个选择：装或者不装
				dp[j]=max(dp[j],dp[j-v[i]]+w[i]); //j从大到小，那么dp[j-v[i]]在dp[j]之后改变,不影响dp[j]的结果
			}
		}
	}
	cout<<dp[V];
	return 0;
}