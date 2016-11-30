/*
sample input:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
999999 James 90
0 0
 */
#include <algorithm>
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

struct node{
    int id;
    char name[10];
    int sc;
};

node stu[100005];

bool cmp1(const node& a,const node& b){
    return a.id<b.id;
}

bool cmp2(const node& a,const node& b){
    if(strcmp(a.name,b.name)!=0)
        return strcmp(a.name,b.name)<0;
    return cmp1(a,b);
}

bool cmp3(const node& a,const node& b){
    if(a.sc!=b.sc)
        return a.sc<b.sc;
    return cmp1(a,b);
}

int main(){
    int n , c ,cas=1;
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&c),n||c){
        for(int i=0;i<n;++i){
            scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].sc);
        }
        if(c==1) sort(stu,stu+n,cmp1);
        else if(c==2) sort(stu,stu+n,cmp2);
        else if(c==3) sort(stu,stu+n,cmp3);
        printf("Case %d:\n",cas++);
        for(int i=0;i<n;++i){
            printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].sc);
        }
    }
    return 0 ;
}