#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    int n,i,j;
    vector<int> array;
    int count=0;
    while(cin>>n,n){
        array.push_back(n);
        count++;
        int *arr=new int[n];
        for(i=0;i<n;i++)
            cin>>arr[i];
        int temp;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(abs(arr[i])<abs(arr[j]))
                    (temp=arr[i],arr[i]=arr[j],arr[j]=temp);
        for(i=0;i<n;i++)
            array.push_back(arr[i]);
        delete [] arr;
    }
    int first=0;
    for(i=0;i<count;i++){
        for(j=0;j<array[first];j++){
            if(j) cout<<" ";
            cout<<array[first+1+j];
        }
        cout<<endl;first+=(array[first]+1);
    }
}