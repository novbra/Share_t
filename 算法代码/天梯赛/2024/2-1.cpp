#include<bits/stdc++.h>

using namespace std;
int n,m;
bool users[100005][1005];
int search(int a,int b){
    int count=0;
    for(int i=1;i<=n;i++){
    	if(users[i][a]&&users[i][b]){
        	count++;
        }
    }
    return count;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;cin>>k;
        while(k--){
            int id;cin>>id;
            users[i][id]=true;
        }
        
    }

    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        cout<<search(a,b)<<"\n";
    }
}