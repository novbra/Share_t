// Problem: Luogu P1683
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1683
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
const int W=21;
const int H=21;
int w,h;
bool r[H][W];
bool st[H][W];
int startI,startJ;
int ans;

int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

void dfs(int i,int j){
	if(0<=i && i<h && 0<=j && j<w){
		if(r[i][j]==true &&st[i][j]==false){
			st[i][j]=true;//标记踩过
			ans++;
			for(int d=0;d<4;d++){
				//cout<<"x:"<<i+dx[d]<<",y:"<<j+dy[d]<<endl;
				dfs(i+dx[d],j+dy[d]);
			}
		}	
	}
}

int main(){
	scanf("%d %d",&w,&h);
	for(int i=0;i<h;i++){//行
		for(int j=0;j<w;j++){
			char ch;
			ch=getchar();
			while(ch=='\r'||ch=='\n')
				ch=getchar();
			//cout<<ch<<endl;
			//cout<<"ch:"<<ch<<endl;
			if(ch=='.')	r[i][j]=true;
			else if(ch=='#')	r[i][j]=false;
			else if(ch=='@'){
				r[i][j]=true;
				startI=i;
				startJ=j;
			}
		}
	}
	dfs(startI,startJ);
	cout<<ans<<endl;
	return 0;
}