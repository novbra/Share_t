// Problem: Luogu P1746
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1746
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1010;
typedef pair<int,int> PII;
int n,ans;
char g[N][N];
int dist[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

PII start,_end;
queue<PII> que;
int bfs(int x,int y){
	memset(dist,-1,sizeof dist);
	dist[x][y]=0;
	que.push({x,y});
	while(!que.empty()){
		auto t=que.front();
		que.pop();
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(1<=a&&a<=n&&1<=b&&b<=n&&g[a][b]=='0'&&dist[a][b]==-1){
				dist[a][b]=dist[t.first][t.second]+1;
				if(a==_end.first&&b==_end.second){
					return dist[_end.first][_end.second];
				}
				que.push({a,b});
			}
		}
	}
	return -1;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%s",g[i]+1);	
	}
	cin>>start.first>>start.second>>_end.first>>_end.second;
	ans=bfs(start.first,start.second);
	cout<<ans<<endl;
	return 0;
}