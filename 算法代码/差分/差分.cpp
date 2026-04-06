#include <bits/stdc++.h>
using namespace std;
int d[5]={0};
int a[5]={3,1,7,5,2};
//6 4 11 6 3
void add(int l,int r,int v){
    d[l]+=v;
    d[r+1]-=v;
}


int main(){
	add(0,2,3);
	add(2,4,1);
	for(int i=1;i<5;i++)	d[i]+=d[i-1];
	for(int i=0;i<5;i++){
		cout<<a[i]+d[i]<<" ";
	}
	return 0;
}