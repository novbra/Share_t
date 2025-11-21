#include <bits/stdc++.h>
using namespace std;
int main(){
	double n;
	cin>>n;
	double l=-100,r=100;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		if(mid*mid*mid<=n){
			l=mid;
		}else{
			r=mid;
		}
	}
	printf("%lf",l);
	return 0;
}