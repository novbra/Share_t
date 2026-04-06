#include <bits/stdc++.h>
using namespace std;
const int N=200,M=1005;
double dp[20005][M];
int weight[20005];
double value[20005];
int main(){
    //freopen("2.in","r",stdin);
	int n,m;
    double costTime=0;
	cin>>n>>m;//n 物品总数 m 背包容量
	int index=1;//记录实际物品索引
	for(int i=1;i<=n;i++){
		int type;cin>>type;
		double t;cin>>t;
		costTime+=t;
		if(type==0){
			//灵活型
			//把灵活型按单位价值拆分成w个普通型任务
			int w,v;
			cin>>w>>v;
			for(int j=1;j<=w;j++){
				weight[index]=1;
				value[index]=1.0*v/w;
				index++;
			}
		}else{
			//普通型
			cin>>weight[index]>>value[index];
			index++;
		}
    }
	//01背包
	for(int i=1;i<index;i++){
		for(int j=1;j<=m;j++){
			//判断能否加入
			if(j>=weight[i]){
				//不选                         Vs  选
				//不加这个物品且同等容量下的价值 Vs  该物品价值+上一轮选择物品在容量=当前容量-该物品重量情况下能选到的最大价值 
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
			}else if(j>0){
				//放不下
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	for(int i=0;i<=index-1;i++){
		for(int j=0;j<=m;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<"\n";
	}
	printf("%.6lf\n",costTime-dp[index-1][m]);
	return 0;
}