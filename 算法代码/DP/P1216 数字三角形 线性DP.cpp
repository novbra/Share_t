// Problem: Luogu P1216
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1216
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
using namespace std;
const int N=1005;
int dta[N][N];
int r;
/*
int dfs(int x,int y){
	if(x>r)	return 0;
	return dta[x][y]+max(dfs(x+1,y),dfs(x+1,y+1));
}
*/
int main(){
	scanf("%d",&r);
	FOR(i,1,r+1){
		FOR(j,1,i+1){
			scanf("%d",&dta[i][j]);
			//cout<<dta[i][j]<<" ";
		}
		//cout<<"\n";
	}
	/*
	cout<<dfs(1,1);
	*/
	/*
	dp[4][1]=dta[4][1]+max(dp[5][1],dp[5][2]);
	dp[5][1]=dta[5][1]+max(dp[6][1],dp[6][2]);
	dp[5][2]=dta[5][2]+max(dp[6][2],dp[6][3]);
	*/
	//由于所获取的状态只有前一行，因此可以只记录前一行即可，就能将二维数组可以优化成一维数组
	for(int i=r-1;i>=1;i--){
		for(int j=1;j<=i;j++){
			dta[i][j]+=max(dta[i+1][j],dta[i+1][j+1]);
		}
	}
	printf("%d",dta[1][1]);
	return 0;
}