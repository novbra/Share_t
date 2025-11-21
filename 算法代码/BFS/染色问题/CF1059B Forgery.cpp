// Problem: Luogu CF1059B
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1059B
// Memory Limit: 250 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m;
char g[N][N];
int dx[]={-1,-1,0,1,1,1,0,-1};
int dy[]={0,1,1,1,0,-1,-1,-1};
char now[N][N]={};
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>g[i]+1;
	}

	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			bool flag=true;
			for(int k=0;k<8;k++){
				int nx=i+dx[k],ny=j+dy[k];
				if(g[nx][ny]=='.'){
					flag=false;
					break;
				}
			}
			if(flag){
				//cout<<i<<","<<j<<"\n";
				//在now图中作画
				for(int k=0;k<8;k++){
					int nx=i+dx[k],ny=j+dy[k];
					now[nx][ny]='#';
				}
			}
		}
	}
	

	//判断now图与原图是否一致
	bool flag=true;
	
	for(int i=1;i<=n&&flag;i++){
		for(int j=1;j<=m&&flag;j++){
			if(now[i][j]=='\0') now[i][j]='.'; //判断字符是否为空时，用\0，注意单引号
			//cout<<now[i][j];
			if(g[i][j]!=now[i][j])	flag=false;
		}
		//cout<<"\n";
	}
	
	if(flag)	cout<<"YES"<<"\n";
	else	cout<<"NO"<<"\n";
	return 0;
}