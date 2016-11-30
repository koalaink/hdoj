#include<iostream>
#include<vector>
using namespace std;
int main(){
    int jie(int);
    cout<<"n e\n";
    cout<<"- -----------\n";
    for(int n=0;n<10;n++){
        cout<<n<<" ";double sum=0;
        for(int i=0;i<=n;i++){
            sum+=(double)1/jie(i);
        }
        if(n>2)
            printf("%.9f\n",sum);
        else cout<<sum<<endl;
    }
}

int jie(int n){
    if(n){
        int s=1;
        for(int i=2;i<=n;i++)
            s*=i;
        return s;
    }else return 1;
}
