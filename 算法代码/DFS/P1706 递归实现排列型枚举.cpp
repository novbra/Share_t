// Problem: Luogu P1706
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1706
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
//法一：依次枚举每个位置应该放哪个数
//法二：依次枚举每个数应该放哪个位置
//法三：打表
#include <bits/stdc++.h>
using namespace std;
const int N=10;
int n;
bool st[N]={false};
int arr[N]={0};
//依次枚举每个位置应该放哪个数
void dfs(int x){
	if(x>n){
		//无位置可选了
		//输出
		for(int i=1;i<=n;i++){
			printf("%5d",arr[i]);
		}
		printf("\n");
	}
	for(int i=1;i<=n;i++){
		if(st[i]==false){//未选中
			//执行选中
			st[i]=true;
			arr[x]=i;
			dfs(x+1);//选下一个位置
			//恢复现场
			st[i]=false;
			arr[x]=0;
		}
	}
}
int main(){
	cin>>n;
	dfs(1);
	return 0;
}