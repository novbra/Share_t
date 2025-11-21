// Problem: Luogu P2440
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2440
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=100010;
#define LL long long
//如果全局要用，建议还是把这些变量定位全局，而不需要去传参
int n;//n原木的数量
int k;//k小段的数量
int L[N];
bool check(int x){
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=L[i]/x;
		if(sum>=k)return true; //优化
	}
	return false;
}

int main(){
	cin>>n>>k;
	int highest=0;
	for(int i=0;i<n;i++){
		scanf("%d",&L[i]); //scanf快于cin
		highest=max(highest,L[i]);
	}
	int l=0,r=highest+1;
	while(l+1!=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%d",l);
	return 0;
}