#include <bits/stdc++.h>
using namespace std;

const int N=105;
int n,m;
struct Node{
	int id;
	Node* up;
	Node* down;
	Node* left;
	Node* right;
};
int start_index;
Node a[N*N];
int main(){
	cin>>n>>m;
	
	for(int i=1;i<=n*m;i++){
		Node node;
		a[i]=node;
	}
	
	for(int i=1;i<=n*m;i++){
		int index;
		cin>>index;
		a[index].id=index;
		int iup,idown,ileft,iright;
		cin>>iup>>idown>>ileft>>iright;
		a[index].up=&a[iup];
		a[index].down=&a[idown];
		a[index].left=&a[ileft];
		a[index].right=&a[iright];
		if(!iup&&!ileft)	start_index=index;
	}
	
	
	//输出
	//start_index
	Node* cur=nullptr;
	Node* next=&a[start_index];
	for(int i=1;i<=n;i++){
		cur=next;
		next=cur->down;
		//对cur进行从左到右遍历
		for(int j=1;j<=m;j++){
			cout<<cur->id<<" ";
			cur=cur->right;
		}
		cout<<"\n";
	}
	
	return 0;
}