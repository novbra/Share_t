// Problem: Luogu P2036
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2036
// Memory Limit: 32 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//指数枚举或者组合排列

#include <bits/stdc++.h>
using namespace std;

const int N=11;
int n,a[2][N]; //0:酸度sour 1:苦度bitter
bool selected[N];
int min_difference=1e9;
int calc(){
	int ac=1,b=0;
	bool flag=false;//用于判断是否至少加了一份调料
	for(int i=1;i<=n;i++){
		if(selected[i]){
			flag=true;
			ac*=a[0][i];
			b=b+a[1][i];
		}
		//cout<<"i:"<<i<<",selected:"<<selected[i]<<endl;
	}
	//cout<<"ac:"<<ac<<",b:"<<b<<endl;
	return flag ? abs(ac-b):-1;
}
void dfs(int p){
	//10种食材, 2^10=1024
	if(p>n){
		int difference=calc();
		if(difference>=0){
			//cout<<difference<<endl;
			min_difference=min(min_difference,difference);
		}
		return;
	}
	selected[p]=true;
	dfs(p+1);
	selected[p]=false;
	dfs(p+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&a[0][i],&a[1][i]);
	dfs(1);
	printf("%d",min_difference);
	return 0;
}