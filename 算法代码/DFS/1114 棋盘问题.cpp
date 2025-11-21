// Problem: 棋盘问题
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/1116/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=10;
int n,k;
char g[N][N];
bool column[N]; //列
int ans;
/*
每行和每列必有一个可以落子的空间，否则那一行和那一列没必要设计出来
由于递归的是不同的行，所以不用判断行是否不同，从第0行一直到n行枚举，每行只取一个，所以不用开一个数组记录行的选取问题
*/
void dfs(int r,int put){
	//cout<<"r:"<<r<<",put:"<<put<<endl;
	if(r>=n||put==k){
		if(put==k)
			ans++;
		return;
	}
	//不取
	dfs(r+1,put);
	//取
	for(int c=0;c<n;c++){
		if(g[r][c]!='#')continue;
		if(column[c]) continue;
		column[c]=true;
		dfs(r+1,put+1);//选下一层
		//恢复现场
		column[c]=false;
	}
}
int main(){
	//逗号表达式，最后一个表达式的值作为整个逗号表达式的值。也就是看n>0&&k>0,而cin>>n>>k只执行不作为判断的依据
	while(cin>>n>>k,n>0&&k>0){
		ans=0; 
		for(int i=0;i<n;i++){
			scanf("%s",g[i]);
		}
		dfs(0,0);//选第0行
		printf("%d\n",ans);
	}
	return 0;
}