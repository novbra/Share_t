/*
解题思路类似于环状队列
关键在于找到起始位置，求模取余，将所有的数据放到同一个坐标系中
*/
#include <bits/stdc++.h>
using namespace std;
struct Item{
	int k;
	int t;
};
int main(){
	//In
	int r,y,g,n;
	cin>>r>>y>>g;
	cin>>n;
	vector<Item> items;
	for(int i=0;i<n;i++){
		int k,t;
		cin>>k>>t;
		items.push_back({k,t});
	}
	//Deal
	//红绿黄的顺序
	int sum=0;
	int circle=r+g+y;
	for(auto ele:items){
		int tmp=0;
		int wait=0;
		//计算实际交通灯情况
		cout<<ele.k<<endl;
		switch(ele.k){
			case 0://经过一段道路
			sum+=ele.t;
			cout<<"经过一段道路"<<ele.t<<endl;
			continue;
			break;
			case 1://红灯
			tmp=g+y+r-ele.t+sum;
			break;
			case 2://黄灯
			tmp=g+y-ele.t+sum;
			break;
			case 3://绿灯
			tmp=g-ele.t+sum;
			break;
			default:
			break;
		}
		tmp%=circle;
		if(ele.k!=0 && tmp<=g){
			//绿灯
			cout<<"绿灯通行"<<endl;
		}else{
			wait=circle-tmp;
			sum+=wait;
			cout<<"等待"<<wait<<endl;
		}
	}
	//Out
	cout<<sum<<endl;
	return 0;
}