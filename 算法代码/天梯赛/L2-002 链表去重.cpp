#include <bits/stdc++.h>
using namespace std;
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
int head,n;
const int  N=1e5+5;
bool flag[N];
struct Node{
	int value;
	int nxt;
	//int tag;//0表示主链，1表示副链
}nodes[N]; //不大可以直接开在栈里

// 输出的顺序不变，所以只需要修改结点标记即可, 标记为0的是去重后的主链，标记为1的是删掉的结点的链, 不可以这样做因为需要更新nxt指针，不推荐强行这样做，这样需要一直遍历找到下个结点，然后把它的地址打印一边
//处理方案2 推荐
//主链直接在处理过程中把保留的直接打印即可，head 只打印 地址和value，其他的打印 地址\n地址 value 等都输出完毕后，打印-1
vector<int> dl; //把删掉的放到这个里面。在里面打印      至于里面的某个结点的nxt,我们直接取下个元素的id打印就行了，如果后面没元素了就输出-1
//vector<Node*> nodes(N,nullptr);

void print_linkedlist(int h){
	for(int cur=h;cur!=-1;cur=nodes[cur].nxt){
		
		if(nodes[cur].nxt>=0){
			printf("%05d %d %05d\n",cur,nodes[cur].value,nodes[cur].nxt);
		}else{
			printf("%05d %d %d\n",cur,nodes[cur].value,nodes[cur].nxt);
		}
	}
}

int main(){
	cin>>head>>n;
	FOR(i,0,n){
		int a,b,c;
		cin>>a>>b>>c;
		nodes[a].value=b;
		nodes[a].nxt=c;
		nodes[a].tag=0;
		//Node* tmp= new Node(b,c);
		//nodes[a]=tmp;
	}
	//处理重复方案1
	int mainHead=head,deleteHead=-1,deleteTail=-1;
	
	for(int pre=-1,cur=head;cur!=-1;){
		
		int next=nodes[cur].nxt;
		if(flag[abs(nodes[cur].value)]){
			//处理方案1
			
			//pre结点的nxt变为cur的nxt
			nodes[pre].nxt=nodes[cur].nxt;
			//cur结点的nxt变为-1
			nodes[cur].nxt=-1;
			//delete链表中插入cur
			
			if(deleteHead==-1){
				//直接替换
				deleteHead=cur;
			}else{
				//在deleteTail后面插入
				nodes[deleteTail].nxt=cur;
			}
			deleteTail=cur;
		}else{
			flag[abs(nodes[cur].value)]=true;
			pre=cur;
		}
		cur=next;
	}
	print_linkedlist(mainHead);
	print_linkedlist(deleteHead);
	return 0;
}