#include<iostream>

#include<vector>

using namespace std;

int main(){
    int n;
    vector<double> result;
    cin>>n;
    for(int i=0;i<n;i++){
        double sum=0;int m;
        cin>>m;
        for(int j=1;j<=m;j++)
            if(j&1)
                sum+=(double)1/j;
            else
                sum-=(double)1/j;
        result.push_back(sum);
    }

    for(int k=0;k<result.size();k++)
        printf("%.2f\n",result[k]);
}