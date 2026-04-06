#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

//40000*1000000000=4*10^13
//long long 是10^18位级别
int n,a,b;
//能被a或b整除的数字，找第n个这样的数字。第n个肯定会被限制到一个范围里来，假如a=2,b=3,那么第n=100个数肯定是在2*100以内。 所以有个上限因为200是被2整除的第100个
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int lcm(int x,int y){
	return x*y/gcd(x,y);
}
int getCnt(ll x){
	//容斥原理计算第x时，前面已有几个神奇数
	ll div_a=x/a;
	ll div_b=x/b;
	ll div_a_b=x/lcm(a,b);
	
	
	return div_a+div_b-div_a_b;
}

int main(){
	cin>>n>>a>>b;
	ll upper=(ll)min(a,b)*n;
	ll l=0,r=upper+1;
	
	while(l+1!=r){
		ll mid=(l+r)>>1;
		ll cnt=getCnt(mid);
		if(cnt<=n){
			if(cnt==n&&mid%a&&mid%b){
				r=mid;
			}else{
				l=mid;
			}
		}else{
			r=mid;
		}
	}
	
	ll ans=l%(long long)(1e9+7);
	cout<<ans;
	return 0;
}