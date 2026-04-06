#include <bits/stdc++.h>
using namespace std;
int const N=1e5+5;

vector<vector<int>> intervals;

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int left,right;
		cin>>left>>right;
		intervals.emplace_back(vector<int>{left,right});
	}
	
	sort(intervals.begin(),intervals.end(),[](const vector<int>& a,const vector<int>& b){
		return a[0]<b[0];
	});
	
	vector<vector<int>> zones;
	
	zones.emplace_back(vector<int>{intervals[0][0],intervals[0][1]});
	
	//cout<<zones[0][0]<<" "<<zones[0][1];
	
	for(int i=1,j=0;i<m;i++){
		
		
		vector<int>& cur=zones[j];
		vector<int>& nxt=intervals[i];
		
		//由于排过序一定有cur[0]<=nxt[0]
		if(nxt[1]<=cur[1]){
			//1.完全包含
			//cur保持不变
		}else if(nxt[0]<=cur[1]&&cur[1]<nxt[1]){
			//2.部分包含
			//改变cur的右边界
			cur[1]=nxt[1];
		}else if(cur[1]+1==nxt[0]){
			//3.不包含但连续
			cur[1]=nxt[1];
		}else{
			//4.无交集
			//添加新区间
			zones.emplace_back(vector<int>{nxt[0],nxt[1]});
			j++;
		}
	}
	
	for(int i=0;i<zones.size();i++){
		cout<<zones[i][0]<<" "<<zones[i][1]<<"\n";
	}
	
	return 0;
}