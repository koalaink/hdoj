#include<iostream>
using namespace std;
int main(){
    int n,m,i,temp,sum;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        sum=0;
        for(i=0;i<m;i++){
            scanf("%d",&temp);
            sum+=temp;
        }
        cout<<sum<<endl;
    }
}