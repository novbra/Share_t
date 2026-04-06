// Problem: Luogu P1255
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1255
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int dp[2][N];//第一维是第几阶梯的走法，第二维存储高精度数组
int n;

void swapArrays(int*& a,int*& b){
	int* t=a;
	a=b;
	b=t;
}

void add_arr(int a[],int b[]){
	//数组a,b都是下标从1开始逆序存放数据，a[0]和b[0]存放有效长度。
	int max_len=max(a[0],b[0]);
	for(int i=1;i<=max_len;i++){
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]=a[i]%10;
	}
	if(a[max_len+1]!=0)
		a[0]=max_len+1;
	else
		a[0]=max_len;
}

int main(){
	cin>>n;
	dp[0][0]=1;dp[0][1]=1;
	dp[1][0]=1;dp[1][1]=1;
	
	int* a=dp[0];
	int* b=dp[1];
	for(int i=2;i<=n;i++){
		add_arr(a,b);//新的会放到a数组中
		swapArrays(a,b);//交换一下a和b，让b始终是新的
	}
	
	for(int i=b[0];i>=1;i--){
		cout<<b[i];
	}
	return 0;
}