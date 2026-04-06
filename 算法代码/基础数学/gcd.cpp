#include <bits/stdc++.h>
using namespace std;
/*
	辗转相除法(欧几里得算法)求最大公因数(公约数)
*/
int gcd(int a,int b){//必须保证a>=b
	return b==0? a:gcd(b,a%b);
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}