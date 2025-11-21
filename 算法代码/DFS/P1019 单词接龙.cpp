// Problem: Luogu P1019
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1019
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=25;
int n,ans;
string words[N];
int st[N]={0};//0表示未选取，1表示选取1次，2表示选取2次;
char start;
int g[N][N];//记录第i个单词与第i个单词最小重合数


void dfs(int cur,int len){
	//使用次数+1
	st[cur]++;
	ans=max(ans,len);
	for(int i=0;i<n;i++){
		if(st[i]<2&&g[cur][i]>0){
			dfs(i,len+(int)words[i].length()-g[cur][i]);
		}
	}
	//恢复现场
	st[cur]--;
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	cin>>start;
	//邻接矩阵预处理
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			string a=words[i],b=words[j];
			for(int k=1;k<=min((int)a.length()-1,(int)b.length()-1);k++){//由于不能包含关系，所以a从第二个开始取，b截止到倒数第二个
				if(a.substr(a.length()-k,k)==b.substr(0,k)){
					g[i][j]=k;
					break;
				}
			}
			//cout<<g[i][j]<<" ";
		}
		//cout<<endl;
	}
	
	for(int i=0;i<n;i++){
		//取string中某个字符，可以直接str[i]来取，不需要用str.substr();
		if(words[i][0]==start)	dfs(i,(int)words[i].length());
	}
	cout<<ans<<endl;
	return 0;
}