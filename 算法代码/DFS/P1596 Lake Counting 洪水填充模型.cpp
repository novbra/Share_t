// Problem: Luogu P1596
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1596
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=110;
int n,m;
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
char g[N][N];
bool st[N][N];
int ans;
//洪水填充模型，目的：求连通块数量
void dfs(int x,int y){
	for(int i=0;i<8;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<0||a>=n||b<0||b>=m) continue;
		if(g[a][b]!='W') continue;
		if(st[a][b]) continue;
		st[a][b]=true;
		dfs(a,b);
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",g[i]);//二维数组的每一行可以看成一个数组，数组名就是数组首元素的地址。字符数组不需要加&,而字符需要加&
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]=='W'&&!st[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}
	printf("%d",ans);
	return 0;
}