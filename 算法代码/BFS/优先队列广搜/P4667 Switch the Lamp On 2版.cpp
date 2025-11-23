#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start,i<f_end,i++)
using namespace std;
const int N=505;
struct Node{
	int x,y;
	Node(int a,int b):x(a),y(b){}
	Node():x(0),y(0){}
}
int n,m;
int g[N][N];
int dist[N][N];
deque<PII> q;
int dx[]={-1,-1,1,1};	//左上 右上 右下 左下
int dy[]={-1,1,1,-1};
char cost0[]={'\\','/','/','\\'};// \是转义字符
bool check(Node node){
	if(node.x<0||node.x>n||node.y<0||node.y>m)	return 1;
}
void bfs(){
	q.push_front({0,0});
	dist[0][0]=0;
	while(q.size()){
		auto now=q.front();q.pop();
		Node next;
		FOR(i,0,4){
			next.x=now.x+dx[i];
			next.y=now.y+dy[i];
			if(check(next))	continue;
			
			if(g[next.x][next.y]==cost0[i]){
				
			}
		}
	}
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