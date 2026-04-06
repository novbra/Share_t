#include <bits/stdc++.h>
using namespace std;
vector<int> a={5,3,2,7,1};
int main(){
	
	sort(a.begin(),a.end(),[](int a,int b){
		return a<b;
	});
	for(auto ele:a){
		cout<<ele<<" ";
	}
	return 0;
}