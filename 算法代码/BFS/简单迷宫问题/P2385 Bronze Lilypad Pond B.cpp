// Problem: Luogu P2385
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2385
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=35;
typedef pair<int,int> PII;
int m,n,m1,m2,ans;
int g[N][N];//0 为水，1 为莲花，2 为岩石，3 为贝西所在的起点，4 为贝西想去的终点。
int dist[N][N];
int sx,sy,ex,ey;
//数组模拟队列
PII q[N*N];
int hh=0,tt=-1;
void bfs(int x,int y){
	int dx[]={m1,m2,-m1,-m2,m1,m2,-m1,-m2};
	int dy[]={m2,m1,m2,m1,-m2,-m1,-m2,-m1};
	memset(dist,-1,sizeof dist);
	//入队
	q[++tt]={x,y};
	dist[x][y]=0;
	while(hh<=tt){
		//出队
		auto t=q[hh++];
		for(int i=0;i<8;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx<1||nx>m||ny<1||ny>n) continue;
			if(g[nx][ny]==0||g[nx][ny]==2) continue;
			if(dist[nx][ny]>=0) continue;
			q[++tt]={nx,ny};
			dist[nx][ny]=dist[t.first][t.second]+1;
		}
	}
}
int main(){
	cin>>m>>n>>m1>>m2;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
			if(g[i][j]==3){
				sx=i;
				sy=j;
			}else if(g[i][j]==4){
				ex=i;
				ey=j;
			}
		}
	}
	bfs(sx,sy);
	ans=dist[ex][ey];
	cout<<ans<<"\n";
	return 0;
}