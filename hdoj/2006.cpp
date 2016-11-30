#include<iostream>

#include<vector>

using namespace std;

int main(){
    int n;
    int *arr;
    vector<int> fin;
    while(cin>>n){
        arr=new int[n];int all=1;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2)
                all*=arr[i];
        }
        fin.push_back(all);
    }

    for(int j=0;j<fin.size();j++){
        printf("%d\n",fin[j]);
    }
}