#include<iostream>

#include<vector>

#define PI 3.1415927

using namespace std;

int main(){
    vector<double> v;
    double r;
    while(cin>>r){
        v.push_back((4*PI*r*r*r)/3);
    }

    for(int i=0;i<v.size();i++)
        printf("%.3f\n",v[i]);
}