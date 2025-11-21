#include <bits/stdc++.h>
using namespace std;
const int N=105;
typedef pair<int,int> PII;
int ans;
//状态压缩   map中key格式为字符串型 长*宽={长侧切下标,宽侧切下标}
unordered_map<string,PII> cut; //切法记录 前者记录田型，后者记录该田型该怎么切取得最大，当长宽侧切下标为0，表示不是从该侧切的
int prices[3][3]={
	{1,2,3},
	{2,5,6},
	{3,6,8}
};
int best[N][N];
int dfs(int l,int w){  //l=3,w=5
	if(l==1&&w==1)	return prices[0][0];
	//记忆化搜索
	if(best[l][w]!=-1) return best[l][w];
	
	int _max,ql=0,qw=0;
	if(l>2||w>2)	_max=0;
	else _max=prices[l-1][w-1];
	
	//从长那条边切
	for(int i=1;i<l;i++){
		int tmp=dfs(l-i,w)+dfs(i,w);
		if(tmp>_max){
			_max=tmp;
			ql=i;
			qw=0;//记住要归0，否则后面判断不出是砍哪边
		}
	}
	//从宽那条边切
	for(int i=1;i<w;i++){
		int tmp=dfs(l,w-i)+dfs(l,i);
		if(tmp>_max){
			_max=tmp;
			qw=i;
			ql=0;//记住要归0，否则后面判断不出是砍哪边
		}
	}
	//记忆化搜索
	best[l][w]=_max;
	cut[to_string(l)+"*"+to_string(w)]={ql,qw};//在map中更新最佳分法
	return _max;
}
int main(){
	int l,w;
	cin>>l>>w;
	memset(best,-1,sizeof best);
	ans=dfs(l,w);
	cout<<ans<<"\n";
	//用DFS或BFS对着Map进行最佳切法逐一输出
	queue<PII> q;
	q.push({l,w});
	while(q.size()){
		auto t=q.front();
		q.pop();
		//获取对应的长*宽田地的切法
		PII tmp=cut[to_string(t.first)+"*"+to_string(t.second)];
		int cutL=tmp.first,cutW=tmp.second;
		if(cutL==0&&cutW==0){
			cout<<t.first<<"*"<<t.second<<"\n";//无须再切，直接输出
		}else if(cutL!=0){
			q.push({t.first-cutL,t.second});//下层输出
			q.push({cutL,t.second});
		}else if(cutW!=0){
			q.push({t.first,t.second-cutW});//下层输出
			q.push({t.first,cutW});
		}
	}
	return 0;
}