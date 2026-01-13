// Problem: Luogu P1255
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1255
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
long long f[N];// 状态定义：第i阶有几种走法
//由于N很大，所以超出的数据，可以使用int数组来存，每一个元素存一个1~9的数
int n;
int main(){
	cin>>n;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1]+f[i-2];
	}
	cout<<f[n];
	return 0;
}