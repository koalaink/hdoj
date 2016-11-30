#include<iostream>
using namespace std;
int main(){
    int n,temp,sum;
    while(cin>>n){
        sum=0;
        while(n--){
            scanf("%d",&temp);
            sum+=temp;
        }
        printf("%d\n",sum);
    }
    return 0;
}