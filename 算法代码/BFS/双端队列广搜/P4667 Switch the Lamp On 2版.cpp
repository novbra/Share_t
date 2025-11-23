#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
using namespace std;
const int N=505;
struct Node{
	int x,y,cost;
	Node(int a,int b,int c):x(a),y(b),cost(c){}
	Node():x(0),y(0),cost(0){}
};

int n,m;
char g[N][N];
int dist[N][N];
deque<Node> q;
int dx[]={-1,-1,1,1};	//左上 右上 右下 左下
int dy[]={-1,1,1,-1};

int unitX[]={0,0,1,1};//元件块(起始位置为1)相对于坐标点(起始位置为0)的偏移位置，左上，右上，右下，左下
int unitY[]={0,1,1,0};

char cost0[]={'\\','/','\\','/'};// \是转义字符

bool check(Node node){
	if(node.x<0||node.x>n||node.y<0||node.y>m)	return 1;
	if(dist[node.x][node.y]<0x3f3f3f3f) return 1;
	return 0;
}
void bfs(){
	memset(dist,0x3f,sizeof dist);
	q.push_front({0,0,0});
	while(q.size()){
		auto now=q.front();q.pop_front();
		//Pop过的便Skip
		if(check(now))	continue; //BFS不同的扩散权值，使用双端队列或优先级队列一定要在队列pop以后赋距离值，而不是在扩散的时候赋距离
		int x=now.x,y=now.y,cost=now.cost;
		dist[x][y]=cost;
		Node next;
		FOR(i,0,4){
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			
			if(g[now.x+unitX[i]][now.y+unitY[i]]==cost0[i]){
				q.push_front({next.x,next.y,cost+0});
			}else{
				q.push_back({next.x,next.y,cost+1});
			}
		}
	}
	
	if(dist[n][m]!=0x3f3f3f3f)	cout<<dist[n][m];
	else	cout<<"NO SOLUTION";
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i]+1;
	}
	bfs();
	return 0;
}