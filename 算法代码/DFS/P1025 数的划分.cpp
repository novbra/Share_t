// Problem: Luogu P1025
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1025
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//法一：组合，确保后面选的比前面的大
//法二：动态规划
const int N=10;
int n,k,ans,arr[N];
void dfs(int prev,int left,int pos){
	if(pos==k){
		ans++;
		/*
		for(int i=0;i<k;i++){
			cout<<arr[i]<<",";
		}
		cout<<endl;
		*/
		return;
	}
	
	if(left==0) return;	
	if(pos==k-1){
		if(left>=prev){
			arr[pos]=left;
			dfs(left,0,pos+1);
		}
	}else{
		for(int i=prev;i<=left;i++){
			arr[pos]=i;
			dfs(i,left-i,pos+1);
			//恢复现场
			arr[pos]=0;
		}
	}
}
int main(){
	cin>>n>>k;
	dfs(1,n,0);
	cout<<ans<<endl;
	return 0;
}