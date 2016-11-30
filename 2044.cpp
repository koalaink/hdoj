#include<iostream>
using namespace std;
int main(){
    __int64 way[100]={1,1,2};
    int n,a,b;
    for(int i=3;i<100;i++) way[i]=way[i-2]+way[i-1];
    cin>>n;
    while(n--){
        cin>>a>>b;
        printf("%I64d\n",way[b-a]);
    }
}