#include<iostream>

#include<vector>

#include<cmath>

using namespace std;

int main(){
    vector<double> abs;
    double x;
    while(cin>>x){
        abs.push_back(fabs(x));
    }

    for(int i=0;i<abs.size();i++)
        printf("%.2f\n",abs[i]);
}