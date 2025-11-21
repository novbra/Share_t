// Problem: Luogu P1163
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1163
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

bool check(double w0,double w,int month,double rate){
	double temp_w=w0;
	for(int i=0;i<month;i++){
		temp_w=temp_w*(1+rate)-w;
	}
	//printf("%.20lf:%lf\n",rate,temp_w);
	return temp_w<=0;//越大的利率越还不清，越往左 越接近答案
}

int main(){
	//等额本息
	double w0,w;
	int m;
	cin>>w0>>w>>m;
	//w1=w0*(1+month_rate)-w;
	double l=0,r=3;
	for(int i=0;i<100;i++){
		double mid=(l+r)/2;
		if(check(w0,w,m,mid)) l=mid;
		else r=mid;
	}
	printf("%.1lf",l*100);
	return 0;
}