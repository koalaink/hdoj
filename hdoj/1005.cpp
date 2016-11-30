#include<iostream>
#include<vector>
using namespace std;
int A;
int B;
int main(){
    int n;
    int f[50]={1,1};
    vector<int> result;
    while(cin>>A>>B>>n,(A&&B&&n)){
        for(int i=2;i<=(n-1)%48;i++)
            f[i]=(A*f[i-1]+B*f[i-2])%7;
        result.push_back(f[(n-1)%48]);
    }

    for(int j=0;j<result.size();j++)
        cout<<result[j]<<endl;
}
