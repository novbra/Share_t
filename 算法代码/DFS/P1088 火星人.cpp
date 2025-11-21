// Problem: Luogu P1088
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1088
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,arr[N]; //1<=m<=100
int pos[N];
bool flag[N]={false};

int _count=0;

//next_permutation也可以写
void dfs(int position){
	if(position>n){
		//输出
		_count++;
		if(_count==m+1){
			for(int i=1;i<=n;i++)
				printf("%d ",pos[i]);
			printf("\n");
			exit(0);
		}

		return;
	}
	
	for(int i=1;i<=n;i++){
		if(!_count)
			i=arr[position]; //从指定的位置开始递归
		if(!flag[i]){
			//未被选择
			pos[position]=i;
			flag[i]=true;
			dfs(position+1);
			//恢复现场
			pos[position]=0;
			flag[i]=false;
		}
	}
}

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1);
	return 0;
}