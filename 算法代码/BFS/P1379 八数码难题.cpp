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
queue<string> q;
int dx[]={0,0,-1,1};
int dy[]={1,-1,0,0};
string target="123804765";
int bfs(string s){
	//先检查一下s是否已经是target状态
	if(s==target) return 0;
	q.push(s);
	dist[s]=0;
	while(q.size()){
		auto t=q.front();
		q.pop();
		int distance=dist[t];
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
			
			if(!dist.count(t)){
				q.push(t);
				dist[t]=distance+1;
				if(t==target)	return dist[t];
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