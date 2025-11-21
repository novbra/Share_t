// Problem: Luogu P1036
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1036
// Memory Limit: 128 MB
// Time Limit: 1500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=22;

int n,k,x[N];
int pick[N]={0};
int ans=0;
bool isPrime(int number){
	for(int i=2;i<=number/i;i++){ //如果写成i*i有可能会爆int
		if(number%i==0) return 0;
	}
	return number>1; //质数必须要大于1
}

void dfs(int position,int start){ //position 选择的位置, start是x数组开始的位置
	
	if(position>k){
		int add=0;
		//加起来
		for(int i=1;i<=k;i++){
			add+=pick[i];
		}
		//计算是否是素数
		ans+=isPrime(add);
		return;
	}
	
	for(int i=start;i<n;i++){
		pick[position]=x[i];
		dfs(position+1,i+1);
		//恢复现场
		pick[position]=0;
	}
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&x[i]);
	}
	//sort(x,x+n);
	dfs(1,0);
	cout<<ans<<endl;
	return 0;
}