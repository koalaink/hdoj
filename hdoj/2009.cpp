#include<iostream>

#include<cmath>

#include<vector>

using namespace std;

int main(){
    double n;int m;
    vector<double> allS;
    while(cin>>n>>m){
        double sum=0.00;
        for(int i=0;i<m;i++)
            (sum+=n,n=sqrt(n));
        allS.push_back(sum);
    }

    for(int j=0;j<allS.size();j++)
        printf("%.2f\n",allS[j]);
}