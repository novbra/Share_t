#include <bits/stdc++.h>
using namespace std;
/**
高精度/低精度
**/
const int N=5010;
int main(){
	string s1;
	long long int b;
	int c[N]={0};
	cin>>s1>>b;
	long long int tmp=0;
	int index=s1.size()-1;
	for(int i=0;i<s1.size();i++){
		tmp*=10;
		tmp+=(int)(s1[i]-'0');
		
		if(tmp>=b){
			c[i]=tmp/b;
			tmp-=c[i]*b;
			if(i!=s1.size()-1&&index==s1.size()-1){
				index=i;
			}
		}
	}
	
	for(int i=index;i<s1.size();i++){
		cout<<c[i];
	}
	cout<<"\n";
	cout<<tmp;//余数
	
	return 0;
}