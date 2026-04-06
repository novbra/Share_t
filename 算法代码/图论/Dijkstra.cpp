#include <bits/stdc++.h>
using namespace std;
#define FOR(i,f_start,f_end) for(int i=f_start;i<f_end;i++)
int n,m,s,d;
int a[505];

const int INF=0x3f3f3f3f;

int g[505][505];
bool visited[505];
int dist[505];
int cnt[505];//记录从起点到其他点最短路径条数
int rescue[505];//记录从起点到其他点时，召集的救援队数量。
int pre[505];//记录各点的前驱结点
vector<int> path;

int main(){
    cin>>n>>m>>s>>d;
    FOR(i,0,n)
        cin>>a[i];
    memset(g,0x3f,sizeof g);
    
    memset(dist,0x3f,sizeof dist);
    
    memset(pre,-1,sizeof pre); //-1表示没有前驱结点
    FOR(i,0,m){
    	int u,v,w;
    	cin>>u>>v>>w;
    	g[u][v]=g[v][u]=w; //双向边  赋值是从右到左
    }
    //起点没有前驱结点
    
    //起点距离为0,让程序去找这个点去开始访问,而不是明确告诉程序哪个点去访问
    dist[s]=0;
    //起点到起点的路径为1，为后续起点到其他点的路径的计算提供参照
    cnt[s]=1;
    //更新起点救援队数量
    rescue[s]=a[s];
    FOR(round,0,n){
    	//查表找到最短的结点
    	int u=-1;
    	FOR(v,0,n){
    		if(visited[v])	continue;
    		//u未赋值，并且v结点距离已出现在表中
    		
    		//dist表初始化为无穷大了，所以只需要找到最小,那就是有效的
    		if(u==-1||dist[v]<dist[u])
    			u=v;
    	}
    	//如果未能获取有效的u，表示所有结点已访问，如果起点距离u无限大表示没有通路
    	if(u==-1||dist[u]==INF)	break;
    	
		//查找到有效的最短的结点
		//访问
		visited[u]=true;
		FOR(v,0,n){
			if(visited[v])	continue;
			if(g[u][v]!=INF){
				
				// 救援队数量，距离的长短会影响最终选择的路径，因此这俩会影响前驱结点
				
				
				// 有路径到达，更新与该结点相邻的结点的距离
				
				// 在维护路径距离表过程中同时维护路径数量 同则互加，短则赋己
				//情况1: dist[v]==dist[u]+g[u][v]   则将路径数叠加
				if(dist[v]==dist[u]+g[u][v]){
					cnt[v]+=cnt[u];
					//相同距离下，救援队数量比大小
					if(rescue[v]<rescue[u]+a[v]){
						rescue[v]=rescue[u]+a[v];
						//更新前驱结点
						pre[v]=u;
					}
				}
				//情况2: dist[v]>dist[u]+g[u][v]    则继承从起点到u结点的最短路径数量，而不是只填个1
				else if(dist[v]>dist[u]+g[u][v]){
					cnt[v]=cnt[u];
					//更新距离
					dist[v]=dist[u]+g[u][v];
					//更新救援队数量
					rescue[v]=rescue[u]+a[v];
					//更新前驱结点
					pre[v]=u;
				}
			}
		} 
    }
    cout<<cnt[d]<<" "<<rescue[d]<<"\n";
    vector<int> path;
    int cur=d;
    
    while(cur!=-1){
    	path.push_back(cur);
    	cur=pre[cur];
    }
    for(int i=path.size()-1;i>=0;i--){
    	cout<<path[i];
    	if(i!=0){
    		cout<<" ";
    	}
    }

    return 0;
}