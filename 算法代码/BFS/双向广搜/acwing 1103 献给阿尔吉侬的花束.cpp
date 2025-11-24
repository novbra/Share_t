// Problem: 献给阿尔吉侬的花束
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/1103/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
using namespace std;
const int N=205;
struct Node{
	int x,y;
};
int t,r,c;
char g[N][N];
int sx,sy,ex,ey;
int dist[N][N];
int tag[N][N];
queue<Node> q;
int dx[]={-1,0,0,1};
int dy[]={0,-1,1,0};

bool check(Node node){
	if(node.x<1||node.x>r||node.y<1||node.y>c)	return 1;
	if(g[node.x][node.y]=='#')	return 1;
	return 0;
}
void bfs(){
	//清空队列
	while(q.size())
		q.pop();
	memset(dist,-1,sizeof dist);
	q.push({sx,sy});//0表示从起始位置开始搜
	q.push({ex,ey});//1表示从结束位置开始搜
	tag[sx][sy]=0;
	tag[ex][ey]=1;
	dist[sx][sy]=0;
	dist[ex][ey]=0;
	while(q.size()){
		Node next,now=q.front();q.pop();
		FOR(i,0,4){
			next.x=now.x+dx[i],next.y=now.y+dy[i];
			if(check(next))	continue;
			
			if(dist[next.x][next.y]>=0){
				if(tag[next.x][next.y]!=tag[now.x][now.y]){
					//交叉
					cout<<dist[now.x][now.y]+dist[next.x][next.y]+1<<"\n";
					return;
				}else{
					//重复搜索
					continue;
				}
			}
			q.push(next);
			dist[next.x][next.y]=dist[now.x][now.y]+1;
			tag[next.x][next.y]=tag[now.x][now.y];
		}
	}
	cout<<"oop!"<<"\n";
	return;
}
int main(){
	cin>>t;
	while(t--){
		cin>>r>>c;
		FOR(i,1,r+1){
			FOR(j,1,c+1){
				cin>>g[i][j];
				if(g[i][j]=='S'){
					sx=i;sy=j;
				}else if(g[i][j]=='E'){
					ex=i;ey=j;
				}
			}
		}
		bfs();
	}
	return 0;
}