// Problem: Luogu P3956
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3956
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int N=1005;
int g[N][N];//0红色,1黄色
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
int dist[N][N];
deque<PII> q;
int bfs(){
	memset(dist,-1,sizeof dist);
	q.push_front({1,1});
	dist[1][1]=0;
	while(q.size()){
		auto t=q.front();q.pop_front();
		
	}
	
}
int main(){
	cin>>m>>n;
	for(int i=0;i<n;i++){
		int x,y,c;
		cin>>x>>y>>c;
		g[x][y]=c;
		
	}
	bfs();
	return 0;
}