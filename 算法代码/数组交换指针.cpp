#include <bits/stdc++.h>
using namespace std;
void swapArrays(int*& a,int*& b){
	int* temp=a;
	a=b;
	b=temp;
}

int main(){
	int a[]={1,2,3};
	int b[]={10,20,30};
	
	int* p1=a;
	int* p2=b;
	
	swapArrays(p1,p2);
	
    for (int i = 0; i < 3; i++) {
        std::cout << p1[i] << " ";  // 10 20 30
    }
	
	return 0;
}