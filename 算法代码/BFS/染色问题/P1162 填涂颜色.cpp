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
//全局访问标志
bool visited[N][N]={false};
void bfs(int x,int y){
	//初始化队列
	PII que[N*N];
	int hh=0,tt=-1;
	//局部访问标志
	bool v[N][N]={false}; //数组必须初始化
	//访问边界标志
	bool flag_is_border=false;
	//根节点入队
	que[++tt]={x,y};
	visited[x][y]=true;
	v[x][y]=true;
	while(hh<=tt){
		auto t=que[hh++];
		for(int i=0;i<4;i++){
			int a=t.first+dx[i],b=t.second+dy[i];
			if(a<1||a>n||b<1||b>n){
				//边界,非闭合,对所有与之相邻的点都遍历，设置已访问
				flag_is_border=true;
				continue;
			}
			if(g[a][b]==1) continue;
			if(v[a][b]) continue;
			//未访问过
			que[++tt]={a,b};
			visited[a][b]=true;
			v[a][b]=true;
		}
	}
	if(!flag_is_border){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(v[i][j]){
					g[i][j]=2;
				}
			}
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
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(g[i][j]==0&&!visited[i][j]){
				bfs(i,j);
			}
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}

	return 0;
}