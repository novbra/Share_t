// Problem: Luogu P2730
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2730
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
string ss="12345678";
string es;
unordered_map<string,int> dist;
unordered_map<string,int> tag;
unordered_map<string,string> pre;
queue<string> q;
//BFS如何寻找到路径
string A(string s){
		swap(s[0],s[7]);
		swap(s[1],s[6]);
		swap(s[2],s[5]);
		swap(s[3],s[4]);
		return s;
}
string B(string s){
		char s3=s[3];
		char s4=s[4];
		s[3]=s[2];
		s[4]=s[5];
		s[2]=s[1];
		s[5]=s[6];
		s[1]=s[0];
		s[6]=s[7];
		s[0]=s3;
		s[7]=s4;
		return s;
}
string C(string s){
		char s2=s[2];
		s[2]=s[1];
		s[1]=s[6];
		s[6]=s[5];
		s[5]=s2;
		return s;
}
int bfs(){
	q.push(ss);
	q.push(es);
	dist[ss]=0;
	dist[es]=0;
	tag[ss]=1;
	tag[es]=2;
	while(q.size()){
		auto t=q.front();
		q.pop();
		cout<<tag[t]<<","<<dist[t]<<","<<t<<endl;
		int distance=dist[t];
		int flag=tag[t];
		for(int i=0;i<3;i++){
			string tmp;
			switch(i){
				case 0:
					tmp=A(t);
					break;
				case 1:
					tmp=B(t);
					break;
				case 2:
					tmp=C(t);
					break;
			}








			if(!tag.count(tmp)){
				//未操作的
				q.push(tmp);
				dist[tmp]=distance+1;
				tag[tmp]=flag;
			}else if(tag[tmp]!=tag[t]){
				cout<<"交叉"<<tag[tmp]<<","<<dist[tmp]<<","<<tmp<<endl;
				 return distance+dist[tmp]+1;
			}
		}
	}
	return -1;
}
int main(){
	getline(cin,es);
	int ei[]={1,2,3,4,5,6,7};
	for(int i=0;i<7;i++){
		es.erase(es.begin()+ei[i]);
	}
	cout<<bfs()<<"\n";
	return 0;
}