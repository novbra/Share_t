// Problem: Luogu P1873
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1873
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
bool isBlue(int t[],int n,int cut_height,int m){
	long long sum=0;
	for(int i=0;i<n;i++){
		sum+=max(0,t[i]-cut_height);
	}
	//cout<<"sum:"<<sum<<endl;
	if(sum>=m){
		return true;
	}else{
		return false;
	}
}
int main(){
	int n,m;
	int t[N];
	
	cin>>n>>m;
	int highest;
	
	for(int i=0;i<n;i++){
		cin>>t[i];
		highest=max(highest,t[i]);
	}
	//10 15 17 20
	//匹配m
	
	int l=0,r=highest;
	while(l+1!=r){
		int mid=l+r>>1;
		//cout<<mid<<endl;
		if(isBlue(t,n,mid,m)){ //10
			//<木材长度符合条件的色块
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l<<endl;
	
	return 0;
}