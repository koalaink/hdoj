#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<string>
using namespace std;

bool cmp(char a,char b){
    return a<b;
}

bool comp(char *a,char *b){
    return strcmp(a,b)<0?true:false;
}

int main(){
    char d[100][10],s[100][10];
    char* arr[100];
    char sw[10];
    int dlen=0;
    while(cin>>d[dlen],strcmp(d[dlen],"XXXXXX")){
        arr[dlen]=d[dlen];
        dlen++;
    }
    int i;
    sort(&arr[0],&arr[0]+dlen,comp);
    for(i=0;i<dlen;i++){
        strcpy(s[i],arr[i]);
        sort(s[i],s[i]+strlen(s[i]),cmp);
    }
    i=0;
    bool flag;
    while(cin>>sw,strcmp(sw,"XXXXXX")){
        flag=false;
        sort(sw,sw+strlen(sw),cmp);
        for(i=0;i<dlen;i++){
            if(strcmp(sw,s[i])==0){
                printf("%s\n",arr[i]);
                flag=true;
            }
        }
        if(!flag) printf("NOT A VALID WORD\n");
        printf("******\n");
    }
}