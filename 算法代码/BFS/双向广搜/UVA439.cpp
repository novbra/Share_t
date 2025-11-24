// Problem: Luogu UVA439
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/UVA439
// Memory Limit:  MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
using namespace std;
const int N=10;
struct Node{
	int x,y;
};
int dx[]={-1,-2,-2,-1,1,2,2,1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
unordered_map<string,int> mp;
int sx,sy,ex,ey,ans;
queue<Node> q;
int dist[N][N];
int tag[N][N];

// 列 a-h
// 行 1-8
int bfs(){
	if(sx==ex&&sy==ey)	return 0;
	//清空队列
	while(q.size())	q.pop();
	memset(dist,-1,sizeof dist);
	
	q.push({sx,sy});//0表示从起始位置开始搜
	q.push({ex,ey});//1表示从结束位置开始搜
	tag[sx][sy]=0;
	tag[ex][ey]=1;
	dist[sx][sy]=0;
	dist[ex][ey]=0;
	
	while(q.size()){
		Node next,now=q.front();q.pop();
		FOR(i,0,8){
			next.x=now.x+dx[i],next.y=now.y+dy[i];
			if(next.x<1||next.x>8||next.y<1||next.y>8)	continue;
			if(dist[next.x][next.y]>=0){
				if(tag[next.x][next.y]!=tag[now.x][now.y]){
					//交叉
					return dist[now.x][now.y]+dist[next.x][next.y]+1;
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
	return -1;
}
int main(){
	mp["a"]=1;
	mp["b"]=2;
	mp["c"]=3;
	mp["d"]=4;
	mp["e"]=5;
	mp["f"]=6;
	mp["g"]=7;
	mp["h"]=8;
	string a,b;
	while(a="",b="",cin>>a>>b,a!=""){
		sy=mp[a.substr(0,1)];
		sx=stoi(a.substr(1,1));
		ex=mp[b.substr(0,1)];
		ey=stoi(b.substr(1,1));
		ans=bfs();
		printf("To get from %s to %s takes %d knight moves.\n",a.c_str(),b.c_str(),ans);
	}
	return 0;
}