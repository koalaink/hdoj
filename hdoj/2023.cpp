#include<iostream>
using namespace std;
int main(){
    int n,m,i,j;
    double stu[50][5];
    int id=0;
    while(cin>>n>>m){
        double stu_s[50]={0},sub_s[5]={0};
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>stu[i][j];
                stu_s[i]+=stu[i][j];
                sub_s[j]+=stu[i][j];
            }
        }

        for(i=0;i<n;i++){
            if(i) printf(" ");
            printf("%.2f",stu_s[i]/m);
        }
        printf("\n");
        for(i=0;i<m;i++){
            if(i) printf(" ");
            printf("%.2f",sub_s[i]/n);
        }
        printf("\n");
        int count=0,temp;
        for(i=0;i<n;i++){
            temp=1;
            for(j=0;j<m;j++)
                if(stu[i][j]<(sub_s[j]/n)) temp=0;
            if(temp) count++;
        }
        cout<<count<<endl<<endl;
    }
}