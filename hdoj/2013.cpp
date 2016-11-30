#include<iostream>

#include<vector>

using namespace std;

int main(){
    int n;
    vector<int> number;
    while(cin>>n){
        int sum=1;
        for(int i=1;i<n;i++){
            sum=(sum+1)*2;
        }
        number.push_back(sum);
    }

    for(int j=0;j<number.size();j++)
        cout<<number[j]<<endl;
}