// Problem: Luogu P1332
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1332
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef pair<int,int> PII;
int n,m,a,b;
int dist[N][N];
PII infected[N*N];//数组模拟队列
int hh=0,tt=-1;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
//无障碍图曼哈顿距离也可以计算出
void bfs(){
	while(hh<=tt){//数组队列非空
		//出队
		auto t=infected[hh++];
		for(int i=0;i<4;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(dist[nx][ny]!=-1) continue;
			//入队
			infected[++tt]={nx,ny};
			dist[nx][ny]=dist[t.first][t.second]+1;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
	cin>>n>>m>>a>>b;
	memset(dist,-1,sizeof dist);
	for(int i=1;i<=a;i++){
		int x,y;
		cin>>x>>y;
		//入队
		infected[++tt]={x,y};
		dist[x][y]=0;
	}
	bfs();
	for(int i=0;i<b;i++){
		int x,y;
		cin>>x>>y;
		cout<<dist[x][y]<<"\n";
	}
	return 0;
}