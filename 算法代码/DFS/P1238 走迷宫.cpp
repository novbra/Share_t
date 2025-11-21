// Problem: Luogu P1238
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1238
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=20;
typedef pair<int,int> PII;
int m,n,ans;
int g[N][N];
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
PII start,_end;
int visited[N][N];
vector<PII> v;
bool flag;
void dfs(int x,int y){
	if(x==_end.first &&y==_end.second){
		flag=true;
		//打印路径
		for(int i=0;i<(int)v.size();i++){
			cout<<"("<<v[i].first<<","<<v[i].second<<")";
			if(i!=(int)v.size()-1){
				cout<<"->";
			}
		}
		cout<<endl;
		return;

	}
	for(int i=0;i<4;i++){
		int a=x+dx[i],b=y+dy[i];
		if(a<1 || a>m || b<1 || b>n) continue;
		if(g[a][b]==0)	continue;
		if(visited[a][b]) continue;
		visited[a][b]=true;
		v.push_back({a,b}); //emplace_back 直接构造pair,v.emplace_back(a,b);会更快
		dfs(a,b);
		//恢复现场
		visited[a][b]=false;
		v.pop_back();
	}
}
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>g[i][j];
		}
	}
	cin>>start.first>>start.second;
	cin>>_end.first>>_end.second;
	visited[start.first][start.second]=true;
	v.push_back({start.first,start.second});
	dfs(start.first,start.second);
	if(!flag){
		cout<<-1<<endl;
	}
	return 0;
}