// Problem: Luogu P3395
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3395
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1005;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int t,n;
int ob[N][N];
queue<PII> q;
int dist[N][N];
void bfs(){
	//(1,1)->(n,n)
	q.push({1,1});
	dist[1][1]=0;
	while(q.size()){
		auto t=q.front();q.pop();
		if(dist[n][n]>=0) continue;//在队列弹出后，如果(n,n)已访问就跳过
		for(int i=0;i<4;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx<1||nx>n||ny<1||ny>n) continue;
			if(dist[nx][ny]>=0)	continue;
			//cout<<nx<<","<<ny<<","<<ob[nx][ny]<<"\n";
			//判断是否有障碍物
			if(ob[nx][ny]<=dist[t.first][t.second])	continue;
			
			dist[nx][ny]=dist[t.first][t.second]+1;
			q.push({nx,ny});
		}
	}
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		memset(ob,0x3f,sizeof ob);
		for(int i=1;i<=2*n-2;i++){
			int x,y;
			cin>>x>>y;
			ob[x][y]=i;
		}
		memset(dist,-1,sizeof dist);
		bfs();
		if(dist[n][n]>=0)	cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
	return 0;
}