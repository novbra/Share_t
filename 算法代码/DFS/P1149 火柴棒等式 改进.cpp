// Problem: Luogu P1149
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1149
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//两个条件，A+B=C和A+B=C的火柴棍数量=n

#include <bits/stdc++.h>
using namespace std;
const int N=25;
int n;
int a[10]={6,2,5,5,4,5,6,3,7,6};
int pos[3];
int ans;

void dfs(int position){ //left表示剩余还有多少个火柴棍
	if(position==2){
		//条件A+B=C
		pos[2]=pos[0]+pos[1];
		int sum=0;
		for(int i=0;i<3;i++){
			int tmp=pos[i];
			do{
				sum+=a[tmp%10];
				tmp/=10;
			}while(tmp>0);
		}
		//判断是否符合A+B=C的火柴棍数量=n
		int l=n-4;
		//cout<<pos[0]<<"+"<<pos[1]<<"="<<pos[2]<<",火柴棍数:"<<sum<<endl;
		if(l==sum)	ans++;
		return;
	}
	
	for(int i=0;i<1000;i++){
		pos[position]=i;
		dfs(position+1);
		//恢复现场
		pos[position]=0;
	}
		
}

int main(){
	cin>>n;
	//+占2个，=占2个
	dfs(0);
	cout<<ans<<endl;
	return 0;
}