#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=11;
int n,m;
/**
	关于过程mod还是答案mod，自己可以去看吉大跳楼梯加强版高精度 环形队列.cpp 跟那个答案一样的
**/
int main(){
	cin>>n>>m;
	int dp[M];
	memset(dp,0,sizeof dp);
	dp[0]=1;
	int front=0;//记录首元素位置
	for(int i=1;i<m;i++){
		for(int j=0;j<i;j++){
			dp[i]+=dp[j];
		}
	}
	
	for(int i=m;i<=n;i++){
		for(int j=0;j<m;j++){
			//dp[front]是第一个要加的数，直接就存到dp[index]里，然后循环把后面的加上
			if(j==front) continue;
			dp[front]+=dp[j];
		}
		//取余存储
		dp[front]=dp[front]%10007;
		//更新front位置
		front=(front+1)%m;
	}
	
	int index=(front+m-1)%m;//最后结果在front的前一个位置上
	
	//求余
	cout<<dp[index];
	return 0;
}