#include <bits/stdc++.h>
using namespace std;
const int N=5010;
int main(){
	string s1,s2;
	cin>>s1>>s2;
	int a[N],b[N],c[N];//被除数，除数，商
	a[0]=s1.size();
	b[0]=s2.size();
	for(int i=1;i<=a[0];i++)
		a[i]=s1[i-1]-'0';
	for(int i=1;i<=b[0];i++)
		b[i]=s2[i-1]-'0';
	//设置被除数的操作位数为除数的长度，让程序从第二个位置开始试
	int maxlen=a[0]-b[0]+1;
	a[0]=b[0];
	//商的最大位数位a[0]-b[0]+1次
	int index=-1;
	for(int i=0;i<maxlen;i++){
		//判断当前轮被除数截数是否比除数大
		int t[5010]={0};
		//把除数放到对应位置
		for(int j=1;j<=b[0];j++){
			t[i+j]=b[j];
		}
		bool flag=true;
		while(flag){
			//截位与除数比较
			for(int j=1;j<=a[0];j++){ //个位
				//先判断大小
				//对位做减法
				if(a[j]<t[j]){
					//首位不够减
					flag=false;
					break;
				}else if(a[j]==t[j]){
					continue;
				}else{
					break;
				}
			}
			// 截位-除数
			if(flag){
				//从个位开始
				for(int j=a[0];j>a[0]-b[0];j--){ //个位
					if(a[j]<t[j]){
						a[j]+=10;
						a[j-1]--;
					}
					a[j]-=t[j];
				}
				//c[a[0]]++;
				if(index==-1){
					index=i;
				}
				c[i]++;
			}
			//b[1+i] b[1+i+1] ... b[1+i+b[0]]
		}
		a[0]++;
	}
	if(index==-1){
		cout<<0;
	}else{
		for(int i=index;i<maxlen;i++){
			cout<<c[i];
		}
	}
	return 0;
}