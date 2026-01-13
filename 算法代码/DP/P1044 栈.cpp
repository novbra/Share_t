// Problem: Luogu P1044
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1044
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

/*
不应该关注入栈的数本身，
而应该关注，入栈和出栈操作顺序有多少种，条件排列组合(栈中有元素才能pop, 未入栈数>0才能执行push, 这俩的交替出现的顺序可以有多少种)
递归树应该关注从初始状态(n,0)到无法继续push这段路径，记录还有多少个数未入栈，以及栈中有多少个数未出栈。
*/
#include <bits/stdc++.h>
using namespace std;
const int N=20;
int n;
int mem[N][N];//dfs记忆化搜索
int dp[N][N];//二维DP
/*
	x: 还剩几个数没push进栈
	y: 栈中有几个数未pop出栈
*/
int dfs(int x,int y){
	//记忆化搜索
	if(mem[x][y]>0)	return mem[x][y];
	
	if(x==0)	return 1;
	
	//x>0
	//push新数进栈
	int sum=0;
	sum+=dfs(x-1,y+1);
	if(y>0){
		//pop出栈
		sum+=dfs(x,y-1);
	}
	//记忆化搜索
	mem[x][y]=sum;
	return sum;
}
int main(){
	cin>>n;
	//dfs版本
	//cout<<dfs(n,0);
	
	//dp版本 逆向    不容易空间压缩，因为同时涉及到了i-1和i层的数据复制
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(i==0)	dp[i][j]=1;
			else{
				dp[i][j]=dp[i-1][j+1];
				if(j>0)	dp[i][j]+=dp[i][j-1];
			}
		}
	}
	cout<<dp[n][0];
	return 0;
}