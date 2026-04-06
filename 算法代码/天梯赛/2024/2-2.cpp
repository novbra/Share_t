#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;
const int M=1005;
int n,m;
string texts[N];
//首字母英语initials
string getWordsInitials(string text){
	string tmp="";
	//获取各个单词
	bool lastSpace=true;
	for(int i=0;i<text.size();i++){
		if(lastSpace&&text[i]>='a'&&text[i]<='z'){
			tmp+=text[i];
			lastSpace=false;
		}else if(text[i]==' '){
			lastSpace=true;
		}
	}
	return tmp;
}

int main(){
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){
        getline(cin,texts[i]);
    }
    cin>>m;
    cin.ignore();
    while(m--){
    	string tmp;getline(cin,tmp);
    	//取文本中各个文字首字母
    	string match_mode=getWordsInitials(tmp);
    	bool flag=false;
    	for(int i=n-1;i>=0;i--){
    		string initials=getWordsInitials(texts[i]);
    		if(initials==match_mode){
    			if(flag) cout<<"|";
    			cout<<texts[i];
    			flag=true;
    		}
    	}
    	if(!flag)
    		cout<<tmp;
    	cout<<"\n";
    }
    return 0;
}