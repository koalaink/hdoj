#include<iostream>

using namespace std;

int main(){
    int n,m,i,j,temp;
    int a[100],b[100];
    while(cin>>n>>m,(n||m)){
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<m;i++)
            cin>>b[i];
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                if(a[i]>a[j]) (temp=a[i],a[i]=a[j],a[j]=temp);
        int temp1=1;
        for(i=0;i<n;i++){
            temp=1;
            for(j=0;j<m;j++)
                if(a[i]==b[j]) temp=0;
            if(temp){temp1=0;cout<<a[i]<<" ";}
        }
        if(temp1) cout<<"NULL";
        cout<<endl;
    }
}