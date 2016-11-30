#include<iostream>
using namespace std;
int main(){
    __int64 _[34][2]={{1,0},{3,1}};
    int i;
    for(i=2;i<34;i++){
        _[i][0]=_[i-1][0]*3+_[i-1][1]*2;
        _[i][1]=_[i-1][0]+_[i-1][1];
    }
    int n;
    while(scanf("%d",&n)!=EOF && n!=-1)
        printf("%I64d, %I64d\n",_[n][0],_[n][1]);
    return 0;
}