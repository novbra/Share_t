// Problem: Luogu P2895
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2895
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=305;
typedef pair<int,int> PII;
int m;
int t[N][N];//流星砸落毁坏道路时间表
int dist[N][N];//各点到达时间
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

/*Debug
坐标系没有最大值300，而是第一象限都可以无限的 只是流星只会砸在0-300之间，事实上300以上的点也是存在的
*/

int bfs(int x,int y){
	memset(dist,-1,sizeof dist);
	PII q[N*N];
	int hh=0,tt=-1;
	q[++tt]={x,y};
	dist[x][y]=0;
	while(hh<=tt){
		auto tmp=q[hh++];
		for(int i=0;i<4;i++){
			int a=tmp.first+dx[i],b=tmp.second+dy[i];
			if(a<0||b<0) continue;
			if(dist[a][b]>=0) continue;
			if(dist[tmp.first][tmp.second]+1>=t[a][b]) continue;//表示道路已毁坏
			q[++tt]={a,b};
			dist[a][b]=dist[tmp.first][tmp.second]+1;
			if(t[a][b]==0x3f3f3f3f)	return dist[a][b];
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	memset(t,0x3f,sizeof t);//无限大表示安全的地方
	cin>>m;
	//难点，就在于处理这个砸的顺序
	for(int i=0;i<m;i++){
		int x,y,time;cin>>x>>y>>time;
		//如果中心已经被砸过了，判断谁先砸的
		t[x][y]=min(t[x][y],time);
		//标记周围毁坏时间
		for(int i=0;i<4;i++){
			int a=x+dx[i],b=y+dy[i];
			if(a<0||b<0) continue;
			//如果已经被砸过了且被砸的时间先于本次时间就跳过
			t[a][b]=min(t[a][b],time);
		}
		
	}
	cout<<bfs(0,0)<<"\n";
	return 0;
}