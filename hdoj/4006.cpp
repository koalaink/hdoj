/*
sample input:
8 3
I 1
I 2
I 3
Q
I 5
Q
I 4
Q
 */
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct node{
    int x;
    friend bool operator<(const node& a,const node& b){
        return a.x>b.x;
    }
};

int main(){
    char ch;
    int n,k;
    node cur;
    int tmp;
    // freopen("0input.txt","r",stdin);
    while(scanf("%d%d",&n,&k)!=EOF){
        priority_queue<node> q;
        while(n--){
            getchar();
            scanf("%c",&ch);
            if(ch=='I'){
                scanf("%d",&cur.x);
                if(q.size()<k) q.push(cur);
                else if(q.top().x<cur.x){ q.pop();q.push(cur);}
            }
            else{
                printf("%d\n",q.top().x);
            }
        }

    }
    return 0;
}