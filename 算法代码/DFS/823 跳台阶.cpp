// Problem: 跳台阶
// Contest: AcWing
// URL: https://www.acwing.com/problem/content/823/
// Memory Limit: 64 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int n;
int dfs(int s,int step){
	int _s=s+step;
	if(_s==n){
		return 1;
	}else if(_s>n){
		return 0;
	}else {
		//走一/二级
		return dfs(_s,1)+dfs(_s,2);
	}
}
int main(){
	cin>>n;
	int ans=dfs(0,1)+dfs(0,2);
	cout<<ans<<endl;
	return 0;
}