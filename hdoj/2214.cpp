#include<iostream>
#include<stdio.h>
using namespace std;

int pow(int a,int b){
    int ans=1;
    while(b--) ans*=a;
    return ans;
}

int fun(char* f,int x){
    int i=2;
    int len=strlen(f);
    int ans=0;
    while(i<len){
        int temp=0;
        int sign=1;
        if(f[i]=='-'){
            sign=-1;
            i++;
        }else if(i!=2) i++;
        while(i<len && f[i]!='-' && f[i]!='+'){
            if(f[i]>='0' && f[i]<='9')
                if(temp==0 && f[i-1]!='^') temp=f[i]-'0';
                else temp=temp*pow(x,f[i]-'0'-1);
            else if(f[i]=='x'){
                if(temp) temp=temp*x;
                else temp=x;
            }
            i++;
        }
        ans+=sign*temp;
    }
    return ans;
}

int main(){
    int n,t=1;
    char f[30];
    char map[63][63];
    char c;
    while(scanf("%d",&n)!=EOF){
        c='a';
        memset(map,' ',sizeof(map));
        for(int i=0;i<62;i++){
            map[i][30]='|';
            map[31][i]='-';
            map[i][61]='\0';
        }
        map[0][29]='y';
        map[0][30]='^';
        map[31][61]='>';
        map[32][61]='x';
        map[31][30]='+';
        map[31][62]=map[32][62]='\0';
        for(int i=0;i<n;i++){
            scanf("%s",f);
            for(int x=-30;x<=30;x++){
                int y=fun(f,x);
                if(y>=-30 && y<=30){
                    if(map[-y+31][x+30]==' ') map[-y+31][x+30]=c;
                    else map[-y+31][x+30]='.';
                }
            }
            c++;
        }
        printf("Case:%d\n",t);
        for(int i=0;i<62;i++)
            printf("%s\n",map[i]);
        t++;
    }
}

