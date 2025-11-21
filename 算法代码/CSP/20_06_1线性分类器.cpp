#include <bits/stdc++.h>
using namespace std;
/*
判断两个点是否在直线的同一侧，只需要将(x1,y1),(x2,y2)代入f(x,y)=Ax+By+C中，
根据f(x1,y1)和f(x2,y2)是否同号即可判定，若同号则在同一侧，如果需要判断是上区还是下区需要乘以B，再与0作比较
利用各区计数判断是否正确
A上区实际数
B上区实际数
A下区实际数
B下区实际数

是否==A标注数,B标注数
*/
struct dot{
    int x;
    int y;
    char type;
};
struct linear{
    int A; //X
    int B; //y
    int C; //常数
    bool result;
};
int main(){
    //In
    int n,m;
    cin>>n>>m;
    vector<dot> dots;
    vector<linear> linears;
    int x,y;
    char type;
    for(int i=0;i<n;i++){
        cin>>x>>y>>type;
        dots.push_back({x,y,type});
    }
    int a,b,c;
    for(int i=0;i<m;i++){
        cin>>a>>b>>c; //a对应C,b对应x前系数，c对应y前系数
        linears.push_back({b,c,a});
    }
    //Deal
    //在线上/下边区分
    for(int i=0;i<m;i++){
        bool reslt=true;
        int f;
        bool check_dirction=false;
        char upper_letter;
        for(int j=0;j<n;j++){
            f=linears[i].A*dots[j].x+linears[i].B*dots[j].y+linears[i].C;
            if(linears[i].B*f>0){
                //上
                if(check_dirction==false){
                    check_dirction=true;
                    upper_letter=dots[j].type;
                }else{
                    //非首次
                    if(upper_letter!=dots[j].type){
                        reslt=false;
                        break;
                    }
                }
            }else if(linears[i].B*f<0){
                //下
                if(check_dirction==false){
                    check_dirction=true;
                    if(dots[j].type=='A'){
                        upper_letter='B';
                    }else{
                        upper_letter='A';
                    }
                }else{
                    //非首次
                    if(upper_letter==dots[j].type){
                        reslt=false;
                        break;
                    }
                }
            }
        }
        //Out
        if(reslt){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}