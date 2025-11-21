// Problem: Luogu P4554
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P4554
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=501;
typedef pair<int,int> PII;
int n,m;
int sx,sy,ex,ey;
char g[N][N];
deque<PII> que;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
int dist[N][N];
void bfs(int start_x,int start_y){
	que.clear();
	memset(dist,-1,sizeof dist);
	que.push_back({start_x,start_y});
	dist[start_x][start_y]=0;
	while(!que.empty()){
		auto t=que.front();
		que.pop_front();
		if(dist[ex][ey]>=0) return;
		for(int i=0;i<4;i++){
			int a=t.x+dx[i],b=t.y+dy[i];
			if(a<0||a>=n||b<0||b>=m)	continue;
			if(dist[a][b]>=0) continue;
			if(g[t.x][t.y]==g[a][b]){
				que.push_front({a,b});//将费用为0的插入队头
				dist[a][b]=dist[t.x][t.y];
			}else{
				que.push_back({a,b});//将费用为1的插入队尾
				dist[a][b]=dist[t.x][t.y]+1;
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	while(cin>>n>>m,n>0&&m>0){
		for(int i=0;i<n;i++)
			cin>>g[i];
		cin>>sx>>sy>>ex>>ey;
		bfs(sx,sy);
		cout<<dist[ex][ey]<<"\n";
	}
	return 0;
}