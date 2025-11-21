// Problem: Luogu P1126
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1126
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
/*
DEBUG:
机器人是一个直径1.6米的球->是有碰撞体积的。因此储藏室墙壁边缘是不可走的
机器人走是有个过程的，不是跳过去的，因此需要判断前面的格子是否可走，才能往这个格子后面走
障碍物是占据4个点位的
*/
#include <bits/stdc++.h>
using namespace std;
const int N=55;
struct State{
	int x,y,d;
	State(int a,int b,int c):x(a),y(b),d(c){}
	State():x(0),y(0),d(0){}
};
int n,m;
int sx,sy,ex,ey;
char sd;
int g[N][N];

int cost[N][N][4];

queue<State> q;

int dx[]={0,1,0,-1};//E S W N
int dy[]={1,0,-1,0};
/*
//移动可以使用二维数组; bfs可以先执行移动再执行转向
int dx[][]={
	{0,0,0},//E
	{1,2,3},//S
	{0,0,0},//W
	{-1,-2,-3},//N
};

int dy[][]={
	{1,2,3},//E
	{0,0,0},//S
	{-1,-2,-3},//W
	{0,0,0},//N
};
*/
map<char,int> mp;
State creep(State st){
	st.x+=dx[st.d];
	st.y+=dy[st.d];
	return st;
}
State walk(State st){
	st.x+=2*dx[st.d];
	st.y+=2*dy[st.d];
	return st;
}
State run(State st){
	st.x+=3*dx[st.d];
	st.y+=3*dy[st.d];
	return st;
}
State left(State st){
	if(st.d-1<0){
		st.d=3;
	}
	else st.d--;
	return st;
}
State right(State st){
	if(st.d+1>3){
		st.d=0;
	}else st.d++;
	return st;
}

void bfs(int x,int y,int d){
	memset(cost,0x3f,sizeof cost);//设置为无限大
	q.emplace(x,y,d);
	cost[x][y][d]=0;
	while(q.size()){
		auto t=q.front();q.pop();
		State st[5];
		st[0]=creep(t);
		st[1]=walk(t);
		st[2]=run(t);
		st[3]=left(t);
		st[4]=right(t);
		int valid=0;
		for(int i=0;i<5;i++){
			if(0<i&&i<3 && i>valid)	continue;//一步不能走，则两步必定不能走，两步不能走必定三步不能走
			//墙壁四周置也是不能要的
			if(st[i].x<1||st[i].x>=n||st[i].y<1||st[i].y>=m)	continue;
			//检查前方是否有障碍物
			if(g[st[i].x][st[i].y])	continue;
			//结点从不同父节点过来的距离大小需要比较后，如果小于已知的结点就可以更新
			if(cost[st[i].x][st[i].y][st[i].d]<cost[t.x][t.y][t.d]+1)	continue;
			valid++;
			q.emplace(st[i].x,st[i].y,st[i].d);
			cost[st[i].x][st[i].y][st[i].d]=cost[t.x][t.y][t.d]+1;
			if(st[i].x==ex&&st[i].y==ey)	return;
		}
	}
}
int main(){
	mp['E']=0;
	mp['S']=1;
	mp['W']=2;
	mp['N']=3;
	cin>>n>>m;
	memset(g,0,sizeof g);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			cin>>tmp;
			if(tmp){
				//1
				g[i][j]=1;//左上点
				g[i][j+1]=1;//右上点
				g[i+1][j]=1;//左下点
				g[i+1][j+1]=1;//右下点
			}
		}
	}

	cin>>sx>>sy>>ex>>ey>>sd;
	if(sx==ex&&sy==ey)	cout<<"0"<<"\n";
	else{
		bfs(sx,sy,mp[sd]);
		for(int i=0;i<4;i++){
			if(cost[ex][ey][i]!=0x3f3f3f3f){
				cout<<cost[ex][ey][i]<<"\n";
				return 0;
			}
		}
		cout<<-1<<"\n";
	}
	return 0;
}