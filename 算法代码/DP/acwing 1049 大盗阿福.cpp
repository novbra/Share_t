#include <bits/stdc++.h>
using namespace std;
const int N=100010;
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
int t,n;
int cash[N];
bool steel[N];
int dfs(int x){
	if(x>n)	return 0;
	return max(dfs(x+2)+cash(x),dfs(x+1));//前者表选，后者表不选
}
int dp[N];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		FOR(i,1,n+1){
			cin>>cash[i];
		}
		
		//虽然以下答案也对，但这不是递推DP，递推DP表应是自下而上推过去
		/*
		dp[1]=cash[1];
		dp[2]=max(cash[1],cash[2]);  //8 1 2 4 6
		
		//dp[3]=max(dp[1]+cash[3],dp[2]);
		//dp[4]=max(dp[2]+cash[4],dp[3]);
		FOR(i,3,n+1){
			dp[i]=max(dp[i-2]+cash[i],dp[i-1]);
		}
		*/
		
		
		//cout<<dfs(1)<<"\n";
		
		dp[n+2]=0;
		dp[n+1]=0;
		for(int i=n;i>0;i--){
			dp[i]=max(dp[i+2]+cash[i],dp[i+1]);
		}
		cout<<dp[1]<<"\n";
		
	}
	return 0;
}