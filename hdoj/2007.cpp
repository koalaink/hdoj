#include<iostream>

#include<vector>

using namespace std;

int main(){
    int m,n,temp;
    vector<int> count;
    while(cin>>m>>n){
        if(m>n) (temp=m,m=n,n=temp);
        int x=0,y=0;
        for(int i=m;i<=n;i++){
            (i&1)?(y+=i*i*i):(x+=i*i);
        }
        count.push_back(x);
        count.push_back(y);
    }
    for(int i=0;i<count.size();i+=2)
        cout<<count[i]<<" "<<count[i+1]<<endl;
}