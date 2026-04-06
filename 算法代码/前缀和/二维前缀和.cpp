#include <bits/stdc++.h>
using namespace std;

int matrix[3][6]={
	{1,2,3,4,5,6},
	{1,2,3,4,5,6},
	{1,2,3,4,5,6}
};
int presum[3][6];

int main(){
	//O(n*m)
	//先搞定首行，和首列的presum
	presum[0][0]=matrix[0][0];
	for(int j=1;j<6;j++){
		presum[0][j]=presum[0][j-1]+matrix[0][j];
	}
	
	for(int i=1;i<3;i++){
		presum[i][0]=presum[i-1][0]+matrix[i][0];
	}
	
	for(int i=1;i<3;i++){
		//int linesum=0;
		for(int j=1;j<6;j++){
			//linesum+=matrix[i][j]; 好理解版本
			//presum[i][j]=presum[i-1][j]+linesum;
			presum[i][j]=presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1]+matrix[i][j];
			cout<<presum[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}