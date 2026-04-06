#include <bits/stdc++.h>
using namespace std;


string _10to2(int num,bool keep_leading_zero=false){
	string binary="";
	//0110   6
    //0001   1
	bool flag=false;
	for(int i=31;i>=0;i--){
		int tmp=(1<<i)&num;
		if(!keep_leading_zero&&flag==false){
			if(tmp!=0){
				flag=true;
				binary+=tmp==0?'0':'1';
			}
		}
		else
			binary+=tmp==0?'0':'1';
	}
	return binary;
}
int main(){
	cout<<_10to2(1);
	return 0;
}