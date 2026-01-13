// Problem: 二维费用的背包问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/8/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1010;
const int M=105;
int vi[N];//物品体积
int mi[N];//物品重量
int wi[N];//物品价值
int n,V,m;

int dp[M][M];

int dfs(int x,int spV,int spM){
	if(x>n)	return 0;
	//该轮选择物品的体积>spV，选择不了，继续向下找
	if(spV<vi[x]||spM<mi[x]){
		return dfs(x+1,spV,spM);
	}else{
		//该轮选择物品的体积<=spV,选择或不选择
		return max(dfs(x+1,spV-vi[x],spM-mi[x])+wi[x],dfs(x+1,spV,spM));
	}
}
//dfs->记忆化->逆序dp->正序dp->空间压缩(2D->1D)
//只用一个f[N]数组，能不能写这个题         f[N]就称为滚动数组
int main(){
	cin>>n>>V>>m;
	for(int i=1;i<=n;i++){
		cin>>vi[i]>>mi[i]>>wi[i];
	}
	//cout<<dfs(1,V,m);
	
	
	//倒着递推，是从n->1    ,正着递推只需要将for i=1， 然后将dp[i+1]改为dp[i-1]，输出cout<<dp[n][V], 为什么是dp[n][V]呢因为正序的话,选1的时候，这个时没有剩余了，而推到n层时，这个时候还有V剩余，因为他才是头
	//正序就是把逆序的递归树倒着看， 本来逆序看[1][V], 正序是逆序的倒着就是[n][V]
	for(int i=n;i>=1;i--){
		for(int j=V;j>=vi[i];j--){		//如果背包剩余体积不满足物品体积，直接跳过即可       只有在空间压缩后可以这样做， 因为复用不用赋值
			for(int k=m;k>=mi[i];k--){	//如果背包剩余重量不满足物品重量，直接跳过即可       只有在空间压缩后可以这样做， 因为复用不用赋值
				//(5,0..V)-(1,0..V)
				//V取的是全集，不同于dfs往下对v有舍
				if(j<vi[i]||k<mi[i]){//j是剩余体积 k是剩余重量 复用i和i+1层， 这个判断赋值是无意义的
					dp[j][k]=dp[j][k];
				}else{//够装 有2个选择：装或者不装
					dp[j][k]=max(dp[j][k],dp[j-vi[i]][k-mi[i]]+wi[i]); //j从大到小，那么dp[j-v[i]]在dp[j]之后改变,不影响dp[j]的结果
				}
			}
		}
	}
	cout<<dp[V][m];
	return 0;
}