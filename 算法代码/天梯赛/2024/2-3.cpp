#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
struct Node{
	int id;
	list<Node*> children;
	Node(int x): id(x){}
};
Node* nodes[N];
Node* root;

void visit(Node* r){
	cout<<r->id<<" ";
}

void dfs(Node* r){
	Node* cur=r;
	visit(r);
	list children=cur->children;
	for(Node* child:children){
		dfs(child);
	}
}

int main(){
	cin>>n;
	int max_degree=0;
	int flag=true;
	for(int i=1;i<=n;i++){
		nodes[i]=new Node(i);
	}
	
	for(int i=1;i<=n;i++){
		int tmp;cin>>tmp;
		if(!tmp){
			root=nodes[i];
		}else{
			(nodes[tmp]->children).push_back(nodes[i]);
		}
	}
	
	for(int i=1;i<=n;i++){
		if((nodes[i]->children).size()>max_degree){
			if(max_degree){
				//max_degree！=0
				//表示非k阶满树
				flag=false;
			}
			max_degree=(nodes[i]->children).size();
			
		}
	}
	
	cout<<max_degree<<" ";
	if(flag){
		cout<<"yes"<<"\n";
	}else{
		cout<<"no"<<"\n";
	}
	
	dfs(root);
	
	return 0;
}