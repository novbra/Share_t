// Problem: Luogu P1135
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1135
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=210;
int n,k[N];
int a,b;
int step;
int dis[N];
void dfs(int cur){
	//剪枝
	if(dis[cur]<=step){
		return;
	}
	dis[cur]=step;
	/* 以下为错误剪枝
	if(st[cur]==true){ 使用上面这条剪枝语句，被搜索过的结点一定会被跳过
		//已搜索过
		return;
	}
	if(step>=ans){ //搜索的步数>已搜索过的最小步数,这条的逻辑也被包含了，dis[b]点就是最短step
		return;
	}
	*/
	if(cur==b){
		//flag=true;
		//cout<<"floor:"<<cur<<", step:"<<step<<endl;
		return;
	}
	
	
	//标记搜索过
	//st[cur]=true;

	//cout<<"floor:"<<cur<<", step:"<<step<<endl;
	if(cur-k[cur]>0){
		step++;
		dfs(cur-k[cur]);
		step--;
		//cout<<"恢复至floor"<<cur<<endl;
	}
	if(cur+k[cur]<=n){
		step++;
		dfs(cur+k[cur]);
		step--;
		//cout<<"恢复至floor"<<cur<<endl;
	}
	
	//恢复现场
	//st[cur]=false;
	
}

int main(){
	//初始化数组dis的所有元素都为相对较大值
	memset(dis,0x7f,sizeof(dis));
	/*
	for(int i=0;i<N;i++){
		cout<<dis[i]<<endl;

	}
	*/
	scanf("%d %d %d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%d",&k[i]);
	dfs(a);
	if(dis[b]!=0x7f7f7f7f){
		printf("%d",dis[b]);	
	}else{
		printf("-1");
	}
	return 0;
}