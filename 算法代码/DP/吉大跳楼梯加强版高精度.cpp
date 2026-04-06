#include <bits/stdc++.h>
using namespace std;
const int N=5010;
const int M=11;
int n,m;
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
	//cout<<"结果是"<<a[1]<<"\n";
}

int main(){
	cin>>n>>m;
	int dp[M][N]; //dp[m]是临时区
	memset(dp,0,sizeof dp);
	//初始状态
	//定义指针数组，分别指向前10个数组
	int* p[M]={nullptr};
	
	dp[0][0]=1;dp[0][1]=1;
	p[0]=dp[0];
	//cout<<p[0][1]<<"\n";
	for(int i=1;i<m;i++){
		p[i]=dp[i];
		for(int j=0;j<i;j++){
			add_arr(dp[i],dp[j]);
		}
		/*
		for(int j=dp[i][0];j>=1;j--){
			cout<<dp[i][j];
		}
		cout<<"\n";
		*/
	}
	//第m个是临时区
	p[m]=dp[m];
	
	
	for(int i=m;i<=n;i++){
		//重置p[m]
		memset(p[m],0,sizeof dp[m]); //dp[m]是随便取的，因为dp[0]-dp[m]的大小都是一样的
		//sizeof p[m]会返回指针的大小，这样就无法正确地重置对应dp[?]的值了。
		//注意这里要写成sizeof dp[?]，因为dp[?]是一个数组，而p[m]是一个指针，sizeof dp[m]会返回整个数组的大小
		
		//把0的值赋给m先
		add_arr(p[m],p[0]);
		int* p0=p[0];
		for(int j=1;j<m;j++){
			p[j-1]=p[j];
		}
		
		//把前面的值加进去
		for(int j=0;j<m-1;j++){
			add_arr(p[m],p[j]);
		}--
		//p[m-1]空出来了
		p[m-1]=p[m];
		//p[m]把p0的指针给p[m]
		p[m]=p0;
		/*
		for(int j=p[m-1][0];j>=1;j--){

			cout<<p[m-1][j];
		}
		cout<<"\n";
		*/
	}
	
	for(int j=p[m-1][0];j>=1;j--){

			cout<<p[m-1][j];
	}
	cout<<"\n";
	
	
	return 0;
}