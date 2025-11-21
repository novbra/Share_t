// Problem: Luogu P1157
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1157
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//与全排列相似，但需要保证升序

#include <bits/stdc++.h>
using namespace std;
const int N=22;
int pos[N]={0};
int n,r;
void dfs(int position){
	//stop condition
	if(position>r){
		for(int i=1;i<=r;i++){
			cout<<setw(3)<<pos[i];
		}
		cout<<endl;
		return;
	}
	
	int beenSelectMax=pos[position-1];
	if(n-beenSelectMax<=r-position){
		return;
	}
	for(int i=pos[position-1]+1;i<=n;i++){
		//选
		pos[position]=i;
		//选下一个位置
		dfs(position+1);
		//恢复现场
		pos[position]=0;
	}
	
}
int main(){
	cin>>n>>r;
	dfs(1);
	return 0;
}