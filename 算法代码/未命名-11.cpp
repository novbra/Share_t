//双重嵌套循环如果处理的数据规模比较大时，可能会超时；如何处理 O(n^2)
//降序，排序是一个好办法，排序算法可以达到nlogn优于n^2
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
	//for(int i=0;i<m;i++){
		//cout<<records[i].y<<endl;
	//}
	int count[m]={0};
	//循环次数可能会达到e10,会超时
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
	
	int largest_index=-1;
	int largest=-1;
	for(int i=0;i<m;i++){
		if(count[i]>=largest){
			largest_index=i;
			largest=count[i];
		}
	}
	cout<<records[largest_index].y<<endl;
	
	return 0;
}