#include <bits/stdc++.h>
using namespace std;

struct Appointment{
	int room_id;
	int start_time;
	int keep_time;
};
int main(){
	// in
	int n,k;//number of key
	cin>>n>>k;
	int a[n];//a[i]=0表示空
	//初始化钥匙挂钩
	for(int i=0;i<n;i++){
		a[i]=i+1;
	}
	int w,s,c;
	bool flag[k][2];// 记录借还操作 0表示借 1表示还，如果为true表示已经完成
	vector<Appointment> aptms;
	for(int i=0;i<k;i++)
	{
		cin>>w>>s>>c;
		aptms.push_back({w,s,c});
		flag[i][0]=false;
		flag[i][1]=false;
	}
	//处理
	for(int i=0;i<2*k;i++){
		int priority_k=-1;//被选中对象
		int op=-1;//0表示借,1表示还
		
		for(int j=0;j<k;j++){
			int cur;
			int cur_op;
			//判断是否已借
			if(flag[j][0]==false){
				//未借
				cur=aptms[j].start_time;
				cur_op=0;
			}else if(flag[j][1]==false){
				//未还
				cur=aptms[j].start_time+aptms[j].keep_time;
				cur_op=1;
			}else{
				//已借已还
				continue;
			}
			if(priority_k!=-1){
				//计算最早的时间
				int et=aptms[priority_k].start_time+op*aptms[priority_k].keep_time;
				if(cur<et){
					priority_k=j;
					op=cur_op;
				}else if(cur==et){
					if(cur_op==1&&op==0){
						//借和还之间还优先
						priority_k=j;
						op=cur_op;
					}else if(cur_op==1&&op==1&&aptms[j].room_id<aptms[priority_k].room_id){
						//还之间，roomId小的优先
						priority_k=j;
					}
				}
			}else{
				priority_k=j;
				op=cur_op;
			}
		}
		flag[priority_k][op]=true;
		int target_room=aptms[priority_k].room_id;
		if(op==0){
			//借
			for(int i=0;i<n;i++){
				if(a[i]==target_room){
					a[i]=0;
					break;
				}
			}
		}else if(op==1){
			//还
			for(int i=0;i<n;i++){
				if(a[i]==0){
					a[i]=target_room;
					break;
				}
			}
		}
	}
	//输出
	for(int i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}