// Problem: Luogu P3143
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3143
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)



#include <bits/stdc++.h>
using namespace std;
const int N=50010;
int n,k;
int d[N];
int s[N]={1};


int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	sort(d,d+n);
	
	for(int i=0;i<n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	
	for(int p0=0,p1=1;p1<n || p0<n;){
		//cout<<"p1:"<<p1<<endl;
		if(p1<n){
			if(d[p1]-d[p0]<=k){
				s[p0]++;
				p1++;
			}
			else{
				//超过k, p0++

				p0++;
				s[p0]=s[p0-1]-1;
				//cout<<p0<<endl;
			}	
		}else{
			p0++;
			s[p0]=s[p0-1]-1;
		}
		
	}
	
	for(int i=0;i<n;i++){
		cout<<s[i]<<" ";
	}
	cout<<endl;
	
	int max=0;
	for(int i=0;i<n;i++){
		bool flag[n]=false;
		
		for(int j=i;j<i+s[i];j++){
			flag[j]=true;//屏蔽对应的数
		}
		
		for(int p0=0,p1=1;p1<n || p0<n;){
			//cout<<"p1:"<<p1<<endl;
			
			if(p1<n){
				if(d[p1]-d[p0]<=k){
					s[p0]++;
					p1++;
				}
				else{
					//超过k, p0++
	
					p0++;
					s[p0]=s[p0-1]-1;
					//cout<<p0<<endl;
				}	
			}else{
				p0++;
				s[p0]=s[p0-1]-1;
			}
		
		}
	}
	
	return 0;
}