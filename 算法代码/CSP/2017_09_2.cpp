#include <bits/stdc++.h>
using namespace std;
struct Usage{
	int op_time;
	int op_room;
	int op;
};
bool cmp(Usage a,Usage b){
	if(a.op_time>b.op_time){
		return false;
	}else if(a.op_time==b.op_time){
		 if(a.op==0 && b.op==1){
		 	return false;
		 }else if(a.op==1 && b.op==1 && a.op_room>b.op_room){
		 	return false;
		 }
	}
	return true;
	}
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	vector<Usage> u;
	int b,c,d;
	for(int i=0;i<2*k;i+=2){
		cin>>b>>c>>d;
		u.push_back({c,b,0});
		u.push_back({c+d,b,1});
	}
	sort(u.begin(),u.end(),cmp);
	
	for(auto ele:u){
		cout<<ele.op_time<<" "<<ele.op_room<<" "<<ele.op<<endl;
	}
	for(int i=0;i<2*k;i++){
		if(u[i].op==0){
			//借
			for(int j=0;j<n;j++){
				if(a[j]==u[i].op_room){
					a[j]=0;
					break;
				}
			}
		}else{
			//还
			int left_index=-1;
			for(int j=0;j<n;j++){
				if(a[j]==0){
					left_index=j;
					break;
				}
			}
			a[left_index]=u[i].op_room;
		}
	}
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}