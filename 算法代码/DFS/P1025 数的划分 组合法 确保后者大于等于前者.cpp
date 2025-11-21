// Problem: Luogu P1025
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1025
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//法一：组合，确保后面选的比前面的大,这里可以写>=
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
	
	if(pos==k-1){//选取最后一个数，由于之前剪枝铺垫了，不可能出现选出的最后一个数大于前一个数
		//arr[pos]=left;
		dfs(left,0,pos+1);
	}else{
		//剪枝：因为后面的数>=前面的数，所以最少需要的数是 未选择的数*最小可选取的数<=剩余数
		for(int i=prev;i*(k-pos)<=left;i++){ //pos是从0开始的,所以k-pos不需要+1计算剩余多少个个数
			//arr[pos]=i;
			dfs(i,left-i,pos+1);
			//恢复现场
			//arr[pos]=0;
		}
	}
}
int main(){
	cin>>n>>k;
	dfs(1,n,0);
	cout<<ans<<endl;
	return 0;
}