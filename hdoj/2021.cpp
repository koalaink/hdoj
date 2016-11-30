#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int n,i;
    int count(int);
    vector<int> ready;
    while(cin>>n,n){
        int page=0;
        for(i=0;i<n;i++){
            int x;
            cin>>x;
            page+=count(x);
        }
        ready.push_back(page);
    }

    for(i=0;i<ready.size();i++)
        cout<<ready[i]<<endl;
}

int count(int x){
    int page=0;
    while(x){
        if(x>=100){
            page+=x/100;
            x%=100;
        }else if(x>=50){
            page+=x/50;
            x%=50;
        }else if(x>=10){
            page+=x/10;
            x%=10;
        }else if(x>=5){
            page+=x/5;
            x%=5;
        }else if(x>=2){
            page+=x/2;
            x%=2;
        }else{
            page+=x;
            x=0;
        }
    }
    return page;
}