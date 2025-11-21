// Problem: 矩阵距离
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/description/175/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef pair<int,int> PII;
int n,m;
char g[N][N];
PII q[N*N];
int hh=0,tt=-1;
int dist[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void bfs(){
	while(hh<=tt){
		auto t=q[hh++];
		for(int i=0;i<4;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx<1||nx>n||ny<1||ny>m) continue;
			if(dist[nx][ny]>=0) continue;
			q[++tt]={nx,ny};
			dist[nx][ny]=dist[t.first][t.second]+1;
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	memset(dist,-1,sizeof dist);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>g[i][j];
			if(g[i][j]=='1'){
				//入队
				q[++tt]={i,j};
				dist[i][j]=0;
				
			}
		}
	}
	bfs();
	return 0;
}