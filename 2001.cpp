#include<iostream>
#include<vector>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
    double x[2],y[2];
    vector<double> des;
    while(cin>>x[0]>>y[0]>>x[1]>>y[1])
        des.push_back(sqrt((x[1]-x[0])*(x[1]-x[0]) + (y[1]-y[0])*(y[1]-y[0])));

    for(int i=0;i<des.size();i++)
        printf("%.2f\n", des[i]);
    return 0;
}