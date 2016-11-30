#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int count(int);
    vector<int> cow;
    while(cin>>n,n)
        cow.push_back(count(n));

    for(int i=0;i<cow.size();i++)
        cout<<cow[i]<<endl;
}

int count(int n){
    switch(n){
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    default:
        int sum=count(n-1)+count(n-3);
        return sum;
    }
}