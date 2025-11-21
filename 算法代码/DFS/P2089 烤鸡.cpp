// Problem: Luogu P2089
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2089
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
//每种调料有3种选择，那么10种调料有3^10=59049
const int N=6e4;

int n,sum,recipe[11]={0};
int record[11][N];
void dfs(int ingredientIndex,int total){
	if(total>n || ingredientIndex>10){
		
		if(total==n){
			//符合条件记录
			for(int i=1;i<=10;i++){
				record[i][sum]=recipe[i];
			}
			sum++;
		}
		return;
	}
	for(int i=0;i<3;i++){
		recipe[ingredientIndex]=i+1;
		dfs(ingredientIndex+1,total+i+1);
		//恢复现场
		recipe[ingredientIndex]=0;
	}
}
int main(){
	cin>>n;
	dfs(1,0);
	//print
	cout<<sum<<endl;
	for(int i=0;i<sum;i++){
		for(int j=1;j<=10;j++)
			printf("%d ",record[j][i]);
		printf("\n");
	}
	return 0;
}