#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int main(){
	int n,q;
	int k[10010]={0};
	int a[N]={0};
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<q;i++){
		cin>>k[i];
	}
	for(int tmp=0;tmp<q;tmp++){
		int l=-1,r=n;
		while(l+1!=r){
			int mid=l+r>>1;
			if(a[mid]<k[tmp]) l=mid;
			else r=mid;
		}
		int begin_index=r;
		l=-1;
		r=n;
		if(begin_index!=n && begin_index!=-1){
			while(l+1!=r){
				int mid=l+r>>1;
				if(a[mid]<=k[tmp]) l=mid;
				else r=mid;
			}
		}
		int end_index=l;
		//若k不存在，此时l指针指向前一个
		if(end_index==-1){
			cout<<"-1 -1"<<endl;
		}else{
			cout<<begin_index<<" "<<end_index<<endl;
		}
	}
	return 0;
}