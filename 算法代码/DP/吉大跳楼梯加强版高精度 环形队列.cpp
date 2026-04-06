#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=11;
int n,m;

int mod_a(int a[],int b){
	int tmp=0;
	
	for(int i=a[0];i>=1;i--){
		tmp*=10;
		tmp+=a[i];
		if(tmp>=b){
			int c=tmp/b;
			tmp-=c*b;
		}
	}
	return tmp;
}

void swapArrays(int*& a,int*& b){
	int* t=a;
	a=b;
	b=t;
}

void add_arr(int a[],int b[]){
	//数组a,b都是下标从1开始逆序存放数据，a[0]和b[0]存放有效长度。
	//cout<<"加数为"<<b[1]<<"\n";
	int max_len=max(a[0],b[0]);
	for(int i=1;i<=max_len;i++){
		a[i]+=b[i];
		a[i+1]+=a[i]/10;
		a[i]=a[i]%10;
	}
	if(a[max_len+1]!=0)
		a[0]=max_len+1;
	else
		a[0]=max_len;
}

int main(){
	cin>>n>>m;
	int dp[M][N]; //dp[m]是临时区
	memset(dp,0,sizeof dp);
	dp[0][0]=1;dp[0][1]=1;
	int front=0;//记录首元素位置
	for(int i=1;i<m;i++){
		for(int j=0;j<i;j++){
			add_arr(dp[i],dp[j]);
		}
	}
	for(int i=m;i<=n;i++){
		for(int j=0;j<m;j++){//0 1 2 3 4 5 6 7 8 9
			//dp[front]是第一个要加的数，直接就存到dp[index]里，然后循环把后面的加上
			if(j==front) continue;
			add_arr(dp[front],dp[j]);
		}
		//更新front位置
		front=(front+1)%m;
	}
	int index=(front+m-1)%m;//最后结果在front的前一个位置上
	
	for(int j=dp[index][0];j>=1;j--){
			cout<<dp[index][j];
	}
	cout<<"\n";
	
	
	//求余
	cout<<mod_a(dp[index],10007);
	return 0;
}