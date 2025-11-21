#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int main(){
	int n,m;
	int a[N]={0};
	cin>>n>>m;
	for(int i=0;i<n;i++) {
        cin>>a[i];
    }
	while(m--){
		int q;
		cin>>q;
		int l=-1,r=n;
		while(l+1!=r){
			int mid=(l+r)>>1;
			if(a[mid]<q){
				l=mid;
			}else{
				r=mid;
			}
		}
		if(a[r]==q){
			cout<<r+1<<" ";
		}else{
			cout<<-1<<" ";
		}
	}
	
	return 0;
}