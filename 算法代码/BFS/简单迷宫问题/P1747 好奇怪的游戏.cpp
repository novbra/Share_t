// Problem: Luogu P1747
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1747
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)


#include <bits/stdc++.h>
using namespace std;
const int N=21;
typedef pair<int,int> PII;
int n,m,ans;
int sx1,sy1,sx2,sy2;

int dist[N][N];
int dx[]={-2,-1,1,2,2,1,-1,-2,2,2,-2,-2};//如何理解走田:只能斜着走两步
int dy[]={1,2,2,1,-1,-2,-2,-1,2,-2,2,-2};

queue<PII> que;
void bfs(int x,int y){
	memset(dist,-1,sizeof dist);
	dist[x][y]=0;
	que.push({x,y});
	while(!que.empty()){
		auto t=que.front();
		que.pop();
		for(int i=0;i<12;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1|| a>N||b<1||b>N) continue;
			if(dist[a][b]!=-1) continue;
			dist[a][b]=dist[t.first][t.second]+1;
			que.push({a,b});
		}
	}
}
int main(){
	//逆向思维
	//从(sx1,sy1),(sx2,sy2)分别到(1,1)就等价于从(1,1)出发到分别到(sx1,sy1),(sx2,sy2)的最远距离
	cin>>sx1>>sy1>>sx2>>sy2;
	bfs(1,1);
	cout<<dist[sx1][sy1]<<"\n";
	cout<<dist[sx2][sy2]<<"\n";
	return 0;
}