#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
template <typename Tp>
void read(Tp &x){
	char c=getchar();x=0;int f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}x*=f;
}//快速读入，不解释
struct node{
	int x,y,c,w; 
	bool operator <(node b)const{//const不可丢 
		return w>b.w;
	}//因为STL中优先队列默认取出最大的元素 
	 //所以这里重载运算符，保证每次取出的是最小代价的 
};
priority_queue<node>q;//node类型必须定义< 
int dx[]={0,1,0,-1,1,1,-1,-1,0,2,0,-2};//12方向及魔法代价 
int dy[]={1,0,-1,0,1,-1,1,-1,2,0,-2,0};
int dw[]={0,0,0,0,2,2,2,2,2,2,2,2};
int a[105][105],dis[105][105];//a存储棋盘上格子的颜色 
int n,m;
void bfs(){
	memset(dis,0x3f,sizeof(dis));dis[1][1]=0;
	q.push((node){1,1,a[1][1],dis[1][1]});
	node cur,nxt;
	while(!q.empty()){
		cur=q.top();q.pop();
		if(dis[cur.x][cur.y]<cur.w)continue;
		for(int i=0;i<12;i++){//懒惰删除 
			nxt.x=cur.x+dx[i];
			nxt.y=cur.y+dy[i];
			nxt.w=cur.w+dw[i];          // 暂且不考虑颜色 先把权重加起来
            if(nxt.x<=0||nxt.x>m||nxt.y<=0||nxt.y>m)continue;//保证在棋盘范围内
			nxt.c=a[nxt.x][nxt.y];      // nxt
			if(!nxt.c)continue; //由于转化了，最终落脚点不能是无色
			if(cur.c!=nxt.c)nxt.w++;//异色+1，确定下一步的信息 
			if(dis[nxt.x][nxt.y]>nxt.w){//选优
				dis[nxt.x][nxt.y]=nxt.w;
				q.push(nxt);
			}
		}
	}
}
int main(){
	int x,y,c;
	read(m);read(n);
	for(int i=1;i<=n;i++){
		read(x);read(y);read(c);
		a[x][y]=c+1;  //无色0 红1 黄2
	}//这里c+1，为了方便区分无色格子 
	bfs();
	if(!a[m][m]){//处理(m,m)无色情况 
		int ans=min(dis[m][m-1],dis[m-1][m])+2;
		if(ans>=inf)puts("-1");
		else printf("%d\n",ans);
	}
	else{
		if(dis[m][m]==inf)puts("-1");
		else printf("%d\n",dis[m][m]);
	}
	return 0;
}