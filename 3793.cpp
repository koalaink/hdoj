#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
    string s ;
    int i , j , len , ans;
    bool flag;
    while( cin>>s ){
        if( s == "#" )
            break;
        len = s.size();
        s += s;
        for( ans = 0 ; ans < len ; ++ans ){
            flag = true;
            for( i = 1 ; i <= len/2 ; ++i ){
                if( s[ans+len-i] != s[ans+i] ){
                    flag = false;
                    break;
                }
            }
            if( flag ) break;
        }
        if( ans < len ) printf( "YES %d\n" , ans );
        else printf( "NO\n" );
    }
}