#include<iostream>
#include<string>
using namespace std;
int main(){
    char str[100];
    while( gets(str) ){
        str[0]=str[0]-'a'+'A';
        for(int i=0;i<sizeof(str)/sizeof(char);i++)
            if(str[i]==' ')
                str[i+1]=str[i+1]-'a'+'A';
        printf("%s\n",str);
    }
}