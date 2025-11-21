// Problem: Luogu P1746
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1746
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
typedef pair<int,int> PII;
int n;
char g[N][N];
int sx,sy,ex,ey;
queue<PII> q;
int vis[N][N];
int dist[N][N];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};
int bfs(){
	memset(dist,-1,sizeof dist);
	memset(vis,0,sizeof vis);
	q.emplace(sx,sy);
	q.emplace(ex,ey);
	vis[sx][sy]=1;//起始位置开始遍历标记为1
	vis[ex][ey]=2;//结束位置开始遍历标记为2
	dist[sx][sy]=0;
	dist[ex][ey]=0;
	while(q.size()){
		auto t=q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1||a>n||b<1||b>n) continue;
			if(g[a][b]=='1') continue;
			if(!vis[a][b]){
				q.emplace(a,b);
				dist[a][b]=dist[t.first][t.second]+1;
				vis[a][b]=vis[t.first][t.second];
			}else if(vis[a][b]!=vis[t.first][t.second]){
				//碰撞
				return dist[a][b]+dist[t.first][t.second]+1;
			}
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>g[i]+1;
	cin>>sx>>sy>>ex>>ey;
	cout<<bfs()<<"\n";
	return 0;
}