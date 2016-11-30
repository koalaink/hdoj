#include<iostream>

#include<vector>

using namespace std;

int main(){
    int T,i;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;scanf("%d",&n);
        int *a=new int[n];
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        int sum=0,int index[2]={0,0},temp=0;
        int max=a[0];
        for(i=0;i<n;i++){
            sum+=a[i];
            if(sum>max){max=sum;index[1]=i;index[0]=temp;index[1]=i;}
            if(sum<0){sum=0;temp=i+1;}
        }
        printf("Case %d:\n", t+1);
        printf("%d %d %d\n",max,index[0]+1,index[1]+1);
        if(t!=(T-1)) printf("\n");
    }
}