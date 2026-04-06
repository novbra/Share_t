#include <bits/stdc++.h>
using namespace std;

int lowbit(int n){
	//return n&(~n+1);
	return n&(-n);
}

/*
	把0变成1
	把1变成0
*/
int flip(int n){
	return n^1;
}

int sign(int n){
	//如果想让负数变为0, 非负数变为1，可以写成((n>>31)&1)^1
	return flip((n>>31)&1);
	//return (n>>31)&1;
}

/*
	该方法会溢出
*/
int getMax1(int a,int b){
	//c可能溢出
	int c=a-b;
	int returnA=sign(c); //a>=b, 则returnA=1; a<b, 则returnA=0
	int returnB=flip(returnA);
	return a*returnA+b*returnB;
}
/*
	该方法不会溢出
*/
int getMax2(int a,int b){
	int c=a-b;
	//需判断c是否溢出
	int sa=sign(a);
	int sb=sign(b);
	int sc=sign(c);
	//sa和sb符号位不同时，c可能溢出
	int diffAB=sa^sb;
	int sameAB=flip(diffAB);
	//diffAB=0, sameAB=1 符号相同时，不会出现溢出
	//sc=1  >>a
	//sc=0  >>b
	//diffAB=1, sameAB=0 符号不同时，可能出现溢出
	//sa=1 且 sb=0 >>a
	//sa=0 且 sb=1 >>b
	int returnA=sameAB*sc+diffAB*sa;
	int returnB=flip(returnA);//非此即彼，取反即可
	return returnA*a+returnB*b;
}
/*
	当i!=j时，可以完成交换
	当i=j时，无法完成交换，会令a[i]=0
*/
void swapArrayElements(int a[],int i,int j){
    a[i]=a[i]^a[j];
    a[j]=a[i]^a[j];
    a[i]=a[i]^a[j];
}

void swap(int &a,int &b){
	a=a^b;
	b=a^b;
	a=a^b;
}

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
/*
	arr数组包含left-right-1个数，且这些数都是left-right范围内的数，但缺少其中的一个数，找出这个数
	利用全部异或^部分异或=另一部分异或
*/
int getMissingNum(int arr[],int n,int left,int right){
	int eorAll=0;
	int eorHas=0;
	for(int i=0;i<n;i++){
		eorAll^=left+i;
		eorHas^=arr[i];
	}
	eorAll^=right;
	return eorAll^eorHas;
}
/*
	给出一组数，有一个数只出现了奇数次，其余的数都出现了偶数次
*/
int getOddTimesNum(int arr[],int n){
	int eor=0;
	for(int i=0;i<n;i++){
		eor^=arr[i];
	}
	return eor;
}


int main(){
	int a=6,b=-3;
	cout<<a<<" "<<b<<endl;
	swap(a,b);
	cout<<a<<" "<<b<<endl;

	int arr[]={1,2};
	cout<<arr[0]<<" "<<arr[1]<<endl;
	swapArrayElements(arr,0,1);
	cout<<arr[0]<<" "<<arr[1]<<endl;
	swapArrayElements(arr,0,0);
	cout<<arr[0]<<endl;
	cout<<"符号位"<<sign(-999)<<endl;
	cout<<"符号位"<<sign(0)<<endl;
	cout<<"getMax1:"<<getMax1(-1,5)<<endl;
	cout<<"getMax2:"<<getMax2(-1,5)<<endl;
	cout<<"getMax2:"<<getMax2(-1,0)<<endl;
	cout<<"getMax2:"<<getMax2(-1,-1)<<endl;
	cout<<"getMax2:"<<getMax2(1,3)<<endl;
	int arr2[]={2,3};
	cout<<"getMissingNum:"<<getMissingNum(arr2,2,1,3)<<endl;
	int arr3[]={1,3,1,3,5,5,1,2,2,5,5};
	cout<<"getOddTimesNum:"<<getOddTimesNum(arr3,sizeof(arr3) / sizeof(arr3[0]))<<endl;
	return 0;
}