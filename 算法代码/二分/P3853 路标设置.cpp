// Problem: Luogu P3853
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3853
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//如果用暴力来做
//for(枚举答案) 枚举的是添加的路标的次数然后check，而非进行k次嵌套循环
//	for(check())
//二分答案,最大值最小模型

#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int L,n,k;//L公路长度, n原有路标的数量, k最多可增设的路标数量
//空旷指数越小，则增设的路标数量越多，更不符合条件
int a[N];

bool check(int x){
	int now=0,i=0;
	int add=0;
	while(i<n+1){
		i++;
		if(a[i]-a[now]>x){
			//不符合空旷指数，需要添加路标,注 添加的路标到原始路标的距离一定是满足<x的，因此若符合的话直接跳到下一个原始路标作为起点
			add+=(a[i]-a[now]-1)/x;
			if(add>k) return false;

		}
		//到此程序在k次以内增设后空旷指数一定符合<x，移动起点
		now=i;
	}
	return add<=k;
}

int main(){
	cin>>L>>n>>k;
	a[0]=0;
	a[n+1]=L;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	//若设置最小的空旷指数0符合错误区域，且设置最大的空旷指数L一定符合正确区域
	int l=0,r=L;
	while(l+1<r){
		int mid=l+r>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout<<r<<endl;
	return 0;
}