/*

1 2 2 3 5


*/
#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n;
int q[N]={0};
int cnt[N]={0};
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i];
	}
	
	
	int res=1;
	//快慢指针来优化双指针双重循环
	for(int i=1,j=1;i<=n;i++){
		cnt[q[i]]++;
		while(cnt[q[i]]>1){
			cnt[q[j]]--;
			j++;
		}
		res=max(res,i-j+1);
	}

	cout<<res<<endl;
	return 0;
}