// Problem: Luogu P1149
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1149
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=10010;
int n;
int a[N]={6,2,5,5,4,5,6,3,7,6};
int pos[3];
int ans;

int calc(int num){
	if(a[num]>0) return a[num];
	int r=0;
	int tmp=num;
	while(tmp>0){
		r+=a[tmp%10];
		tmp/=10;
	}
	//记忆化搜索记录搜索到的值
	a[num]=r;
	return r;
}

void dfs(int left,int position){ //left表示剩余还有多少个火柴棍
	//用火柴棍弄出3个数
	if(position==2){
		//递归结束
		int res=pos[0]+pos[1];
		if(calc(res)==left){
			pos[2]=res;
			ans++;
			//printf("%d+%d=%d\n",pos[0],pos[1],pos[2]);
		}
		return;
	}
	
	//取数
	for(int i=0;i<1000;i++){
		int need=calc(i);
		if(need<left){
			pos[position]=i;
			//cout<<position<<":"<<i<<":"<<num<<endl;
			dfs(left-need,position+1);
		}
	}
}

int main(){
	cin>>n;
	//+占2个，=占2个
	int l=n-4;
	//建议预处理，递推出10到1000所需要的火柴棍
	for(int i=10;i<=1000;i++)
		a[i]=a[i%10]+a[i/10];
	dfs(l,0);
	cout<<ans<<endl;
	return 0;
}