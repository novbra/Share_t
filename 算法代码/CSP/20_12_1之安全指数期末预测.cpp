#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int w,s;//|w|<=10,0<=s<=100
		cin>>w>>s;
		sum+=s*w;
	}
	cout<<max(0,sum)<<endl;
	return 0;
}