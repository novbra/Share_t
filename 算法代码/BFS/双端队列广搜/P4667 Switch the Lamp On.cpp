#include <bits/stdc++.h>
using namespace std;
const int N=505;
typedef pair<int,int> PII;
int n,m;
int g[N][N];
int dist[N][N];
deque<PII> q;
//正斜杆1，反斜杆2
//如果是正斜杆照这个，如果是反斜杆，反转并*-1
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
int rule[2][8]={
	{0,2,1,2,2,1,2,0},//中心斜杆为1          index 0
	{2,1,0,1,1,0,1,2}//中心斜杆为-1          index 1
};
int r[N][N];
int dx1[]={-1,-1,0};
int dy1[]={-1,0,-1};
int type1[]={2,1,2};
//只有在电源和灯之间有一条电线连接的情况下，灯才会亮着。

void bfs(){
	memset(dist,0x3f,sizeof dist);
	q.push_front({1,1});
	dist[1][1]=0;
	
	//(1,1)必须是反斜杆，如果不是需要一次调整
	if(g[1][1]==1){
		dist[1][1]++;
		g[1][1]=2;
	}
	//(n,m)必须是反斜杆，如果不是需要一次调整
	if(g[n][m]==1){
		dist[1][1]++;
		g[n][m]=2;
	}
	
	while(q.size()){
		auto t=q.front();q.pop_front();
		//处理旋转90度
		int origin=g[t.first][t.second];//记录该结点原始状态
		
		if(r[t.first][t.second]){
			r[t.first][t.second]--;
			if(g[t.first][t.second]==1) g[t.first][t.second]++;
			else g[t.first][t.second]--;
		}
		
		for(int i=0;i<8;i++){
			int nx=t.first+dx[i],ny=t.second+dy[i];
			if(nx<1||nx>n||ny<1||ny>m)	continue;
			if(rule[g[t.first][t.second]-1][i]==0)	continue;//无法通过旋转接上
			int inc;
			if(rule[g[t.first][t.second]-1][i]==g[nx][ny]){
				//费用为0
				inc=0;
				if(dist[nx][ny]<=dist[t.first][t.second]+inc)	continue;
				q.push_front({nx,ny});
			}else{
				//费用为1
				inc=1;
				if(dist[nx][ny]<=dist[t.first][t.second]+inc)	continue;
				//旋转90度
				r[nx][ny]++;
				q.push_back({nx,ny});
			}
			
			dist[nx][ny]=dist[t.first][t.second]+inc;
			if(nx==n&&ny==m)	break;
			//cout<<t.first<<","<<t.second<<"->"<<nx<<","<<ny<<"\n"<<",inc:"<<inc<<",dist:"<<dist[nx][ny]<<"\n";
		}
		g[t.first][t.second]=origin;
		if(dist[n][m]!=0x3f3f3f3f)	break;
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<dist[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	if(dist[n][m]==0x3f3f3f3f)
		cout<<"NO SOLUTION";
	else cout<<dist[n][m];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char ch;cin>>ch;
			if(ch=='\\')	g[i][j]=2;
			else g[i][j]=1;
		}
	}
	bfs();
	return 0;
}