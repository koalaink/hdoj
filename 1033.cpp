#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

struct node{
    int x,y,dir;
    node(int a,int b,int d):x(a),y(b),dir(d){};
};

int dir[4][2][2]={{{0,-10},{0,10}},{{-10,0},{10,0}},{{0,10},{0,-10}},{{10,0},{-10,0}}};    // 【 右 下 左 上 】 【 顺 逆 】 【 x y 】

void action(char* com){
    printf("300 420 moveto\n310 420 lineto\n");
    node n(310,420,0);
    int i,len,turn;
    len=strlen(com);
    for(i=0;i<len;i++){
        if(com[i]=='A') turn=0;
        else if(com[i]=='V') turn=1;
        n.x+=dir[n.dir][turn][0];
        n.y+=dir[n.dir][turn][1];
        printf("%d %d lineto\n",n.x,n.y);
        if(turn==1) n.dir=(n.dir==0)?3:(n.dir-1);
        else n.dir=(n.dir==3)?0:(n.dir+1);
    }
    printf("stroke\nshowpage\n");
}

int main(){
    char t[200];
    while(cin>>t){
        action(t);
    }
}