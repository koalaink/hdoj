#include<iostream>
#include<vector>
using namespace std;
int main()
{
    long n;
    vector<long> sum;
    while(cin>>n){
        if(n%2!=0)
            sum.push_back((n+1)/2*n);
        else
            sum.push_back(n/2*(n+1));
    }

    for(int i=0;i<sum.size();i++)
        cout<<sum[i]<<endl<<endl;
    return 0;
}