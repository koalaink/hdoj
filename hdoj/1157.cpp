#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main(){
    int n,arr[10005];
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<n;i++) scanf("%d",arr+i);
        sort(arr,arr+n);
        printf("%d\n",arr[n/2]);
    }
    return 0;
}