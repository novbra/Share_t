#include <bits/stdc++.h>
using namespace std;
const int N=105;
int g[N][N];//-1无色 0红 1黄
int m,n;
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dist[N][N];
struct Node{
	int x,y,cost,color;
	Node(int a,int b,int c,int d):x(a),y(b),cost(c),color(d){}
	Node():x(0),y(0),cost(0),color(0){}
	bool operator <(const Node& other) const{ //这个是greater
			return cost<other.cost;
	}
	bool operator>(const Node& other) const{ //这个则是less
			return cost>other.cost;
	}
};
priority_queue<Node,vector<Node>,greater<Node>> pque;
void bfs(){
	pque.emplace(1,1,0,g[1][1]);
	dist[1][1]=0;
	while(pque.size()){
		auto t=pque.top();pque.pop();
		if(dist[t.x][t.y]<t.cost)	continue;//该结点开销比已有记录的开销大就跳过
		if(t.x==m&&t.y==m)	break;
		Node next;
		for(int i=0;i<4;i++){	
			next.x=t.x+dx[i],next.y=t.y+dy[i];
			//边界
			if(next.x<1||next.x>m||next.y<1||next.y>m)	continue;
			//虚块不允许通往虚块
			if(g[t.x][t.y]==-1&&g[next.x][next.y]==-1)	continue;
			//目标块是否是虚块
			if(g[next.x][next.y]==-1){
				//实块->虚块cost+2
				next.cost=dist[t.x][t.y]+2;
				next.color=t.color;
			}else{
				if(t.color==g[next.x][next.y]){
					//同色cost+0
					next.cost=dist[t.x][t.y];
					next.color=t.color;
				}else{
					//不同色cost+1
					next.cost=dist[t.x][t.y]+1;
					next.color=g[next.x][next.y];
				}
			}
			if(next.cost>=dist[next.x][next.y])	continue;
			dist[next.x][next.y]=next.cost;
			pque.push(next);
		}
	}
	if(dist[m][m]==0x3f3f3f3f){
		cout<<"-1";
	}else	cout<<dist[m][m];
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>m>>n;
	memset(g,-1,sizeof g);
	memset(dist,0x3f,sizeof dist);
	for(int i=1;i<=n;i++){
		int x,y,ch;cin>>x>>y>>ch;
		g[x][y]=ch;
	}
	bfs();
	return 0;
}