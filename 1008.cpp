#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,i;
    vector<int> totalT;
    while(cin>>n,n){
        int *floor=new int[n+1];
        floor[0]=0;
        int time=0;
        for(i=0;i<n;i++){
            cin>>floor[i+1];
            if(floor[i+1]>floor[i])
                time+=(floor[i+1]-floor[i])*6+5;
            else
                time+=(floor[i]-floor[i+1])*4+5;
        }
        totalT.push_back(time);
        delete [] floor;
    }

    for(i=0;i<totalT.size();i++){
        cout<<totalT[i]<<endl;
    }
}