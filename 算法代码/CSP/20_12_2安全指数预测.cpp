//双重嵌套循环如果处理的数据规模比较大时，可能会超时；如何处理 O(n^2)
//降序，排序是一个好办法，排序算法可以达到nlogn优于n^2    前缀和算法
#include <bits/stdc++.h>
using namespace std;
struct Record{
	int y,result; //0表示挂科，1表示未挂科
};
bool cmp(Record r1,Record r2){
	return r1.y<r2.y;
}
int main(){
	int m;
	cin>>m;
	Record records[m];
	for(int i=0;i<m;i++){
		cin>>records[i].y>>records[i].result;
	}
	sort(records,records+m,cmp);
	
	int down_up[m+1]={0};
	int up_down[m+1]={0};
	int precision[m]={0};
	
	
	for(int i=m-1;i>=0;i--){
		if(records[i].result==1){
			down_up[i]=down_up[i+1]+1;
		}else{
			down_up[i]=down_up[i+1];
		}
		cout<<down_up[i]<<endl;
	}
	
	
	
	cout<<"-"<<endl;
	int count=0;
	for(int i=0;i<m;i++){
		
		if(i!=0){
			if(records[i].y>records[i-1].y){
				up_down[i]=count;
			}else{
				//相同
				up_down[i]=up_down[i-1];
			}
		}else{
			//i==0的情况，特别拎出来处理，最好是放在循环前处理
			up_down[i]=0;
		}
		
		if(records[i].result==0){
			count++;
		}
		
		cout<<up_down[i]<<endl;
	}
	cout<<"-"<<endl;
	for(int i=0;i<m;i++){
		precision[i]=up_down[i]+down_up[i];
		cout<<precision[i]<<endl;
	}
	/* 如果不是取最后一个最大值，可以采用该方法
	auto it=max_element(precision,precision+m);
	int index=distance(precision,it);
	*/
	
	//循环次数可能会达到e10,会超时
	/*
	for(int i=0;i<m;i++){ //m<=e5规模
		//选取theta
		int theta=records[i].y;
		count[i]=0;// 预测正确次数
		for(int j=0;j<m;j++){ //m<=e5规模
			//逐个比较
			if(records[j].result==1 && records[j].y>=theta){
				count[i]++;
			}else if(records[j].result==0 && records[j].y<theta){
				count[i]++;
			}
		}
		//cout<<theta<<" "<<count[i]<<endl;
		if(i!=0 && count[i]<count[i-1]){
			break;
		}
	}
	*/
	
	int largest_index=-1;
	int largest=-1;
	for(int i=0;i<m;i++){
		if(precision[i]>=largest){
			largest_index=i;
			largest=precision[i];
		}
	}
	
	cout<<records[largest_index].y<<endl;
	return 0;

}