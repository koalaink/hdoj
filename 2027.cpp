#include<iostream>
using namespace std;
int main(){
    int n,k,j;
    char a[102];
    scanf("%d",&n);
    getchar();
    while(n--){
        gets(a);
        int n1=0,n2=0,n3=0,n4=0,n5=0;
        for(j=0;a[j]!='\0';j++){
            if(a[j]=='a') n1++;
            if(a[j]=='e') n2++;
            if(a[j]=='i') n3++;
            if(a[j]=='o') n4++;
            if(a[j]=='u') n5++;
        }
        printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",n1,n2,n3,n4,n5);
        if(n) printf("\n");
    }
}