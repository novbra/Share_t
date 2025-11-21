// Problem: Luogu P1379
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1379
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
unordered_map<string,int> dist;
unordered_map<string,int> tag;
queue<string> q;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
string target="123804765";

int bfs(string s){
	//先检查一下s是否已经是target状态
	if(s==target) return 0;
	q.push(s);//起点
	q.push(target);//终点
	dist[s]=0;
	dist[target]=0;
	tag[s]=1;//表示从起点搜到的
	tag[target]=2;//表示从终点搜到的
	
	while(q.size()){
		auto t=q.front();
		q.pop();
		int distance=dist[t];
		int flag=tag[t];//先把标记存起来
		//一维转二维
		int zero_index=t.find('0');
		int x=zero_index/3;
		int y=zero_index%3;
		for(int i=0;i<4;i++){
			int a=x+dx[i],b=y+dy[i];
			if(a<0||a>=3||b<0||b>=3) continue;
			//exchange
			int tmp=a*3+b;
			swap(t[tmp],t[zero_index]);
			
			if(!dist.count(t)){//表示未搜索到
				q.push(t);
				dist[t]=distance+1;
				//标记
				tag[t]=flag;
			}else if(tag[t]!=flag){
				//搜索交叉
				return distance+dist[t]+1;
			}
			swap(t[tmp],t[zero_index]);//恢复现场
		}
	}
	
	return -1;
}
int main(){
	string s;
	cin>>s;
	cout<<bfs(s)<<"\n";
	return 0;
}