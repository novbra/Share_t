// Problem: Luogu P1115
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1115
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int f[N]; //前i个数所能形成的最大字段和 无法实现, 正确的状态定义应该是以i结尾的最大字段和
int main(){
	scanf("%d",&n);
	int ans=-1e9;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		f[i]=max(x,f[i-1]+x); //f[i-1]是以i-1结尾的最大字段和和i连接后，依然是连续的
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}