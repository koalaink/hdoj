#include<iostream>
using namespace std;
int main(){
    int t;
    int ascll[1000];
    scanf("%d",&t);
    int i;
    for(i=0;i<t;i++)
        scanf("%d",&ascll[i]);
    for(i=0;i<t;i++)
        printf("%c",(char)ascll[i]);
}