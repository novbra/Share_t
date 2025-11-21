// Problem: Luogu P1162
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1162
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*
这个题只有一个闭合圈
如何缺人某一块是被包围了，还是没被包围，就是看这个点能否向四周遍历找到边界,
或者换一种想法，从某个边界点开始遍历，标记联通的部分，对那些没有标记的为0的全部赋2，就是围着四周灌水
再换一种想法
1 1 1
1 0 1
1 1 1
直接从 (0,0)点开始灌水，这个点不被我们使用，在有效数据的外面一圈都是0,再标记联通部分，对于不联通部分，直接赋2
0 0 0 0 0
0 1 1 1 0
0 1 0 1 0
0 1 1 1 0
0 0 0 0 0
这个方法也适用于多个闭合圈
*/
#include <bits/stdc++.h>
using namespace std;
const int N=32;
typedef pair<int,int> PII;
int n,g[N][N]={0};

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool st[N][N]={false};
//初始化队列
PII que[N*N];
int hh=0,tt=-1;
void bfs(int x,int y){

	//根节点入队
	que[++tt]={x,y};
	st[x][y]=true;
	while(hh<=tt){
		auto t=que[hh++];
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<0||a>n+1||b<0||b>n+1)	continue;
			if(g[a][b]==1) continue;
			if(st[a][b]) continue;
			//未访问过
			que[++tt]={a,b};
			st[a][b]=true;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	bfs(0,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!st[i][j]&&g[i][j]==0){
				g[i][j]=2;
			}
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}