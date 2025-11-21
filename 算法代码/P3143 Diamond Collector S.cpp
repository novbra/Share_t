// Problem: Luogu P3143
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3143
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//以下是局部最优解，但不是全局最优解

#include <bits/stdc++.h>
using namespace std;
const int N=50010;
int n,k;
int d[N];
int record1,record2;

bool check(int x){ //x表示符合条件的钻石数量
	int valid=-1;
	for(int i=0;i<n;i++){
		if(d[i]!=-1){
			valid=i;
			break;
		}
	}
	int p1=valid,p2=valid+1;//p1指向起始符合条件元素,p2指向结束符合条件元素
	while(p2<n){
		//cout<<"p1:"<<p1<<" "<<"p2:"<<p2<<endl;
		if(d[p2]-d[p1]>k){ //p1指向下一个
			p1++;
		}else{
			//当前p2符合元素
			if(p2-p1+1>=x){
				record1=p1;
				record2=p2;
				return true;
			}
			//p2指向下一个----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			p2++;
		}
	}
	return false;
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	sort(d,d+n);
	/*
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	*/
	
	int sum=0;
	int l=0,r=n;
	while(l+1<r){
		int mid=l+r>>1;
		//cout<<"查找的数为"<<mid<<endl;
		if(check(mid)){
			l=mid;
			//cout<<"l更新为"<<l<<endl;
		}else{
			r=mid;
			//cout<<"r更新为"<<r<<endl;
		}
	}
	sum+=l;
	//cout<<record1<<"-"<<record2<<endl;
	for(int i=0;i<=record2-record1;i++){
		d[record1+i]=-1;
		
	}
	
	sort(d,d+n);
	/*
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	*/
	l=0;
	r=n;
	record1=-1;
	record2=-1;
	while(l+1<r){
		int mid=l+r>>1;
		//cout<<"查找的数为"<<mid<<endl;
		if(check(mid)){
			l=mid;
			//cout<<"l更新为"<<l<<endl;
		}else{
			r=mid;
			//cout<<"r更新为"<<r<<endl;
		}
	}
	sum+=l;
	
	
	//cout<<record1<<"-"<<record2<<endl;
	printf("%d",sum);
	return 0;
}