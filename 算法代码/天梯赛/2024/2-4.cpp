#include <bits/stdc++.h>
using namespace std;
int L,N;//L:各行各列元素和等于L N:几阶矩阵
int pos[4];



int dfs(int position,int pick){
	pos[position]=pick;
	int sum=0;
	for(int i=0;i<=position;i++){
		sum+=pos[i];
		if(sum>L)	return 0;
	}
	
	if(position==N-1){
		if(sum==L){
			cout<<pos[0];
			for(int i=1;i<N;i++){
				cout<<" "<<pos[i];
			}
			cout<<"\n";
			return 1;
		}else{
			return 0;
		}
	}
	
	int total=0;
	for(int i=0;i<=L;i++){
		total+=dfs(position+1,i);
	}
	return total;
}




int main(){
	cin>>L>>N;
	
	for(int i=0;i<=L;i++)
		dfs(0,i);
	return 0;
}
