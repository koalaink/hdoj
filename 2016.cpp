#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    vector<int> array;
    int count=0;
    while(cin>>n,n){
        count++;
        array.push_back(n);
        int a,min,index=0,i,temp;
        for(i=0;i<n;i++){
            cin>>a;
            array.push_back(a);
            if(!i) min=a;
            if(min>a){ min=a;index=i;}
        }
        (temp=array[array.size()-n+index],array[array.size()-n+index]=array[array.size()-n],array[array.size()-n]=temp);
    }
    int first=0;
    for(int j=0;j<count;j++){
        for(int k=0;k<array[first];k++){
            if(k) cout<<" ";
            cout<<array[first+1+k];
        }
        first+=(array[first]+1);
        cout<<endl;
    }
}