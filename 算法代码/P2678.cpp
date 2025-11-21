// Problem: Luogu P2678
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2678
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
int L,N,M;
int a[50005];
bool check(int x){
	int remove=0;
	//会移除某个数据的循环，不要使用for,而要使用while
	int i=0,now=0; //快慢指针
	//cout<<"x:"<<x<<endl;
	while(i<N+1){
		i++;
		if(a[i]-a[now]<x){
			//out<<now<<"-"<<i<<"距离不够，移除石头"<<i<<endl;
			//移除该石头
			remove++;
			if(remove>M){
				//cout<<"remove:"<<remove<<endl;
				return false;
			}
		}else{
			//cout<<now<<"-"<<i<<", 距离为"<<a[i]-a[now]<<endl;
			//符合条件，则更换起点
			now=i;
		}
	}
	return remove<=M;
}
int main(){
	cin>>L>>N>>M;
	a[0]=0;
	a[N+1]=L;
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	
	//搬到两石子之间的距离>给定的距离
	int l=0,r=L+1;
	while(l+1!=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l<<endl;
	return 0;
}