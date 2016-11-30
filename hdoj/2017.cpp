#include<iostream>

#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string *str=new string[n];
    int i;
    for(i=0;i<n;i++)
        cin>>str[i];
    for(i=0;i<n;i++){
        int count=0;
        for(int j=0;j<str[i].size();j++){
            if(str[i][j]>='0' && str[i][j]<='9')
                count++;
        }
        cout<<count<<endl;
    }
}