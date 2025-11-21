// Problem: Luogu P1506
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1506
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef pair<int,int> PII;
char g[N][N];
int x,y,ans;
bool st[N][N];
int hh=0,tt=-1;
PII q[N*N];
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};
void bfs(int sx,int sy){
	q[++tt]={sx,sy};
	st[sx][sy]=true;
	while(hh<=tt){
		auto t=q[hh++];
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<0||a>x+1||b<0||b>y+1) continue;
			if(g[a][b]=='*') continue;
			if(st[a][b]) continue;
			q[++tt]={a,b};
			st[a][b]=true;
		}
	}
	
}
int main(){
	cin>>x>>y;
	for(int i=1;i<=x;i++){
		cin>>g[i]+1;
	}
	bfs(0,0);
	for(int i=0;i<=x+1;i++){
		for(int j=0;j<=y+1;j++){
			if(!st[i][j]&&g[i][j]=='0'){
				ans++;
			}
			//cout<<st[i][j];
		}
		//cout<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}