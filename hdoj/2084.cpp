#include<iostream>
int max(int a,int b){
    if(a>b)
        return a;
    else
        return b;
}
int main(){
    int c,n,i,j;
    int st[101][101],dp[101][101];
    scanf("%d",&c);
    while(c--){
        scanf("%d",&n);
        for(i=0;i<n;i++)
            for(j=0;j<=i;j++){
                scanf("%d",st[i]+j);
                dp[i][j]=st[i][j];
            }
        for(i=n-2;i>=0;i--){
            for(j=0;j<=i;j++){
                dp[i][j]+=max(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        printf("%d\n",dp[0][0]);
    }
}