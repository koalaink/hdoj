#include<iostream>
using namespace std;
main(){
    int yhsj[30][30]={{1},{1,1}},i,j;
    for(i=2;i<30;i++){
        for(j=0;j<i+1;j++){
            if(j){
                yhsj[i][j]=yhsj[i-1][j-1]+yhsj[i-1][j];
            }else yhsj[i][j]=1;
        }
    }
    
    int n;
    while(cin>>n){
        for(i=0;i<n;i++){
            for(j=0;j<i+1;j++){
                cout<<yhsj[i][j];
                if(j!=i) cout<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
}