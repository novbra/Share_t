#include<bits/stdc++.h>
using namespace std;

map<int,int> intervals;
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int l,r;cin>>l>>r;
		auto it=intervals.lower_bound(l);
		if(it!=intervals.begin()){
			//检查新区间是否和前一项区间交叉重叠
			auto pre=it;pre--;//左端点<l的第一个区间
			if(pre->second+1>=l){
				//更新新合并区间的l
				l=pre->first;
				//更新新合并区间的r
				r=max(pre->second,r);
				//删除前一项被合并的区间
				intervals.erase(pre);
			}
		}
		
		while(it!=intervals.end()){
			//检查该区间与之后的区间是否交叉重叠
			if(r+1>=it->first){
				//l一定小于后项区间的左端点，无需更新
				//更新新合并区间r
				r=max(r,it->second);
				//删除后项被合并的区间,erase返回被删除的后一项迭代器
				it=intervals.erase(it);
			}else
				break;
		}
		
		//插入新区间
		intervals[l]=r;
		//输出遍历map范围
		int sum=0;
		for(auto it=intervals.begin();it!=intervals.end();it++){
			sum+=it->second-it->first+1;
		}
		cout<<n-sum<<"\n";
	}
	
}