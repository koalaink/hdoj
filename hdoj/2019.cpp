#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m,i;
    vector<int> array;
    int count=0;
    while(cin>>n>>m,(n&&m)){
        count++;
        array.push_back(n+1);
        int put=1;
        for(i=0;i<n;i++){
            int x;
            cin>>x;
            array.push_back(x);
            if(x>=m && put){
                array[array.size()-1]=m;array.push_back(x);put=0;
            }
            if(i==(n-1) && put)
                array.push_back(m);
        }
    }
    int first=0;
    for(i=0;i<count;i++){
        for(int j=0;j<array[first];j++){
            if(j) cout<<" ";
            cout<<array[first+j+1];
        }
        cout<<endl;
        first+=array[first]+1;
    }
}