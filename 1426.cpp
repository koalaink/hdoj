#include<iostream>
#include<stdio.h>
#include<set>
using namespace std;

int const MAX=10;
int map[MAX][MAX];
int row[MAX],col[MAX],r[3][3],sum;
bool flag;

struct node{
    int x,y;
}em[80];

bool check(int index,int num){
    for(int i=0;i<9;i++)
        if(map[em[index].x][i]==num||map[i][em[index].y]==num) return false;
    int x=em[index].x/3*3;
    int y=em[index].y/3*3;
    for(int i=x;i<x+3;i++)
        for(int j=y;j<y+3;j++)
            if(map[i][j]==num) return false;
    return true;
}

void dfs(int index){
    if(index==sum){
        for(int i=0;i<9;i++){
            for(int j=0;j<8;j++)
                printf("%d ",map[i][j]);
            printf("%d\n",map[i][8]);
        }
        flag=true;
        return ;
    }
    for(int i=1;i<=9;i++){
        if(check(index,i) && !flag ){
            map[em[index].x][em[index].y]=i;
            dfs(index+1);
            map[em[index].x][em[index].y]=0;
        }
    }
    return ;
}

int main(){
    char c;
    node no;
    bool hx=false;
    while(cin>>c){
        memset(map,0,sizeof(map));
        sum=0;
        flag=false;
        if(c=='?'){
            em[sum].x=0;
            em[sum].y=0;
            sum++;
        }
        else map[0][0]=c-'0';
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!(i==0&&j==0)){
                    cin>>c;
                    if(c=='?'){
                        em[sum].x=i;
                        em[sum].y=j;
                        sum++;
                    }
                    else map[i][j]=c-'0';
                }
            }
        }
        if(hx++) printf("\n");
        dfs(0);
    }
    return 0;
}