#include<iostream>

#include<vector>

using namespace std;

int main(){
    vector<double> point;
    int n;
    while(cin>>n){
        int i;double sum=0;
        int *temp=new int [n];
        for(i=0;i<n;i++){
            cin>>temp[i];
            sum+=temp[i];
        }
        int max=temp[0],min=temp[0];
        for(i=1;i<n;i++){
            if(temp[i]>max) max=temp[i];
            if(temp[i]<min) min=temp[i];
        }
        point.push_back((sum-max-min)/(n-2));
    }

    for(int j=0;j<point.size();j++)
        printf("%.2f\n",point[j]);
}