#include<iostream>

#include<string>

#include<vector>

using namespace std;

int main(){
    int x,y,temp;
    vector<string> result;
    while(cin>>x>>y,(x||y)){
        if(x>y) (temp=x,x=y,y=temp);
        int count=0;
        for(int i=x;i<=y;i++){
            int s;
            s=i*i+i+41;
            for(int j=2;j<s;j++){
                if(!(s%j)) break;
            }
            if(j==s) count++;
        }
        if(count==(y-x+1))
            result.push_back("OK");
        else
            result.push_back("Sorry");
    }

    for(int k=0;k<result.size();k++)
        cout<<result[k]<<endl;
}