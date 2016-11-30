#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

struct node{
    int point,deadline;
};

bool cmp(node& a,node& b){
    if(a.deadline!=b.deadline)
        return a.deadline<b.deadline;
    return a.point>b.point;
}

int main(){
    node sub[1001];
    bool done[1001];
    int t,n,i,j,ans,day;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&sub[i].deadline);
        for(i=0;i<n;i++) scanf("%d",&sub[i].point);
        sort(sub,sub+n,cmp);
        memset(done,false,sizeof(done));
        day=ans=0;
        for(i=0;i<n;i++){
            if(day<sub[i].deadline){
                day++;done[i]=true;
            }
            else{
                int min=sub[i].point,index=-1;
                for(j=0;j<i;j++)
                    if(done[j] && sub[j].point<min){
                        min=sub[j].point;
                        index=j;
                    }
                if(index!=-1){
                    sub[i].point=sub[i].point^sub[index].point;
                    sub[index].point=sub[i].point^sub[index].point;
                    sub[i].point=sub[i].point^sub[index].point;
                }
                ans+=sub[i].point;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}