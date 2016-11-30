#include <iostream>

#include <vector>

using namespace std;

int main(){
    int m,n,temp;
    int b,s,g;
    vector<int> count;
    vector<int> number;
    while(cin>>m>>n){
        if(m>n) (temp=m,m=n,n=temp);
        int x=0;
        for(int i=m;i<=n;i++){
            b=i/100;
            s=i%100/10;
            g=i%10;
            if( (b*b*b+s*s*s+g*g*g) == i ){
                x++;
                count.push_back(i);
            }
        }
        number.push_back(x);
    }
    temp=0;
    for(int j=0;j<number.size();j++){
        if(number[j]){
            for(int k=0;k<number[j];k++){
                if(k) cout<<" ";
                cout<<count[temp];temp++;
            }
            cout<<endl;
        }
        else cout<<"no"<<endl;
    }
}
