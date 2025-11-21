// Problem: Luogu P2658
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2658
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef pair<int,int> PII;
int m,n;
int h[N][N];
int flag[N][N];
int sx=0,sy=0;
int mi=0x3f3f3f3f,ma=-1;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
PII que[N*N];
int cnt_flag=0;
bool bfs(int x,int y,int d){
	//判断是否有相邻格子间海拔差<=x的路径
	int hh=0,tt=-1;
	bool visited[N][N]={false};
	que[++tt]={x,y};
	visited[x][y]=true;
	int cnt=1;//第一个点也是路标，容易漏路标
	while(hh<=tt){
		auto t=que[hh++];
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1||a>m||b<1||b>n) continue;
			if(visited[a][b]) continue;
			//判断邻格海拔差是否<=x
			if(abs(h[t.first][t.second]-h[a][b])>d) continue;
			que[++tt]={a,b};
			visited[a][b]=true;
			if(flag[a][b]==1)
				if(++cnt==cnt_flag) return true;
		}
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>h[i][j];
			mi=min(mi,h[i][j]);
			ma=max(ma,h[i][j]);
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>flag[i][j];
			if(flag[i][j]==1) cnt_flag++;
			if(sx==0&&flag[i][j]==1){
				//设置一下起点
				sx=i;
				sy=j;
			}
		}
	}
	//cout<<cnt_flag<<endl;
	int l=-1,r=ma-mi; //0也可以是答案因此l必须是-1，但ma-mi一定符合条件可以放到r中
	while(l+1!=r){
		int mid=l+r>>1;
		//cout<<mid<<"\n";
		if(bfs(sx,sy,mid)){ //当前距离可行
			r=mid;
		}else{
			l=mid;
		}
	}
	cout<<r<<"\n";
	
	return 0;
}