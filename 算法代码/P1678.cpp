// Problem: Luogu P1678
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1678
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
	int m,n;
	cin>>m>>n;
	int a[N]={0};
	int b[N]={0};
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m);
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>b[i];
		int l=-1,r=m;
		while(l+1!=r){
			int mid=l+r>>1;
			if(a[mid]<b[i]){
				l=mid;
			}else{
				r=mid;
			}
		}
		int min_tmp;
		//需要区分两种极端情况，左右指针其中一个没有指向有效元素
		if(-1<l && l<m && -1<r && r<m){
			min_tmp=min(abs(a[l]-b[i]),abs(a[r]-b[i]));	
		}else if(l==-1 || l==m){
			min_tmp=abs(a[r]-b[i]);
		}else if(r==-1 || r==m){
			min_tmp=abs(a[l]-b[i]);
		}
		sum+=min_tmp;
	}
	cout<<sum<<endl;
	return 0;
}