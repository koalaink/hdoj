/*
sample input:
Jim_Green
Alan_Blue
 */
#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define MAX 5045
using namespace std;

int main(){
    // freopen("0input.txt","r",stdin);
    char s1[25],s2[25];
    while(scanf("%s %s",s1,s2)!=EOF){
        int i=0,j=0;
        while(s1[i]!='_') ++i;
        while(s2[j]!='_') ++j;
        ++i;++j;
        printf("%s_small_%s\n",s1+i,s2+j);
    }
    return 0;
}