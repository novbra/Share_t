// Problem: Luogu P1102
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1102
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=200010;

int binary_search1(int a[],int len,int x){
	int l=-1,r=len;
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(a[mid]<x){
			l=mid;
		}else{
			r=mid;
		}
	}
	if(a[r]==x){
		return r;
	}else{
		return -1;
	}
}

int binary_search2(int a[],int len,int x){
	int l=-1,r=len;
	while(l+1!=r){
		int mid=(l+r)>>1;
		if(a[mid]<=x){
			l=mid;
		}else{
			r=mid;
		}
	}
	if(a[l]==x){
		return l;
	}else{
		return -1;
	}
}


int main(){
	int a[N]={0};
	int n,c;
	cin>>n>>c;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);

	long long count=0;
	for(int i=0;i<n;i++){
		int begin=binary_search1(a,n,a[i]-c);
		if(begin!=-1){
			int end=binary_search2(a,n,a[i]-c);
			count+=end-begin+1;
			//cout<<a[i]-c<<" "<<end<<" "<<begin<<endl;
		}
	}
	
	cout<<count<<endl;
	return 0;
}