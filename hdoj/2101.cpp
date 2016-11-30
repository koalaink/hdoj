#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
    __int64 a , b ;
    while( scanf( "%I64d%I64d" , &a , &b ) != EOF ){
        printf( "%s\n" , ((a+b)%86)?"no":"yes" );
    }
}