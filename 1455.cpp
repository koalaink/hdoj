#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int const MAX=65;
int sticks[MAX];
bool mark[MAX],flag;
int n,sum,l;


int cmp(const void * a,const void * b){
    return *(int *)b-*(int *)a;
}

void dfs(int sl,int left){
    if(left==0) flag=true;
    else{
        for(int i=0;i<n && !flag;i++){
            if(!mark[i] && sl-sticks[i]>=0){
                mark[i]=true;
                if(sl==sticks[i]) dfs(l,left-sticks[i]);
                else dfs(sl-sticks[i],left-sticks[i]);    
                mark[i]=false;
                if(sl==sticks[i]) return ;
                if(sl==l && sticks[i]<l) return ;
                while(sticks[i]==sticks[i+1]) i++;
            }
        }
    }
    return ;
}

int main(){
    while(scanf("%d",&n),n){
        sum=0;
        for(int i=0;i<n;i++) scanf("%d",sticks+i),sum+=sticks[i];
        qsort(sticks,n,sizeof(int),cmp);
        for(l=sticks[0];l<=sum;l++){
            if(sum%l==0){
                if(sum==1) printf("1\n");
                else{
                    memset(mark,false,sizeof(mark));
                    flag=false;
                    dfs(l,sum);
                    if(flag){
                        printf("%d\n",l);
                        break;
                    }
                }
            }
        }
    }
    return 0;
}