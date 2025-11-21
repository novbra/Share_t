// Problem: 递归实现指数型枚举
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/94/
// Memory Limit: 256 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=15;
int st[N+1]={0};//0:未选择,1：选,2：不选
int n;
void dfs(int x) //x表示枚举到哪个位置
{
		if(x>n){
			for(int i=1;i<=n;i++){
				if(st[i]==1){
					cout<<i<<" ";
				}
			}
			cout<<endl;
			return;
		}
		
		//先不选
		st[x]=2;
		dfs(x+1);
		st[x]=0;//恢复现场
		//再选
		st[x]=1;
		dfs(x+1);
		st[x]=0;//恢复现场
		
}

int main(){
	cin>>n;
	dfs(1);
	return 0;
}