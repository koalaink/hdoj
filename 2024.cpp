#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n,i;
    char **flag;
    string *judge;
    cin>>n;
    flag=new char*[n];
    judge=new string[n];
    for(i=0;i<n;i++){
        flag[i]=new char[50];
        cin.ignore();
        cin.get(flag[i],50);
    }
    for(i=0;i<n;i++){
        if( !((flag[i][0]>='a' && flag[i][0]<='z') || (flag[i][0]>='A' && flag[i][0]<='Z')) && flag[i][0]!='_' ){
            judge[i]="no";
        }
        else{
            int j;
            for(j=0;j<strlen(flag[i]);j++)
                if(!((flag[i][j]>='a' && flag[i][j]<='z') || (flag[i][j]>='A' && flag[i][j]<='Z')) && !(flag[i][j]>='0' && flag[i][j]<='9') && flag[i][j]!='_' )
                    break;
            if(j!=strlen(flag[i])) judge[i]="no";
            else judge[i]="yes";
        }
    }

    for(i=0;i<n;i++)
        cout<<judge[i]<<endl;
}