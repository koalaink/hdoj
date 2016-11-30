#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    vector<int> average;
    vector<int> number;
    while(cin>>n>>m){
        if(n%m) number.push_back(n/m+1);
        else number.push_back(n/m);
        int first=m+1;int count=0;
        while((n-(count+1)*m)>=0){
            average.push_back(first);
            first+=(2*m);
            count++;
        }
        if((n-count*m)) average.push_back(n+count*m+1);
    }
    int temp=0,index=0;
    for(int i=0;i<number.size();i++){
        for(int j=0;j<number[i];j++){
            if(temp) cout<<" ";
            cout<<average[index];index++;
            temp++;
        }
        cout<<endl;temp=0;
    }
}