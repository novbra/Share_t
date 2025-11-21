// Problem: Luogu P1443
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1443
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=405;
typedef pair<int,int> PII;
int n,m,ans;
int start_x,start_y;
int dist[N][N];
int dx[]={-2,-1,1,2,2,1,-1,-2};
int dy[]={1,2,2,1,-1,-2,-2,-1};

queue<PII> que;
void bfs(int x,int y){
	memset(dist,-1,sizeof dist);
	dist[x][y]=0;
	que.push({x,y});
	while(!que.empty()){
		auto t=que.front();
		que.pop();
		for(int i=0;i<8;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1|| a>n||b<1||b>m) continue;
			if(dist[a][b]!=-1) continue;
			dist[a][b]=dist[t.first][t.second]+1;
			que.push({a,b});
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	cin>>n>>m>>start_x>>start_y;
	bfs(start_x,start_y);
	return 0;
}