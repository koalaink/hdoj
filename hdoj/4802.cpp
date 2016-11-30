/*
sample input:
5
2 B
3 D-
2 P
1 F
3 A
2
2 P
2 N
6
4 A
3 A
3 A
4 A
3 A
3 A
 */
#include<iostream>
#include<stdio.h>
#include<map>
using namespace std;

map<string,double> m ;

int main(){
    // freopen("0input.txt","r",stdin) ;
    int n ;
    m["A"] = 4.0 ;
    m["A-"] = 3.7 ;
    m["B+"] = 3.3 ;
    m["B"] = 3.0 ;
    m["B-"] = 2.7 ;
    m["C+"] = 2.3 ;
    m["C"] = 2.0 ;
    m["C-"] = 1.7 ;
    m["D"] = 1.3 ;
    m["D-"] = 1.0 ;
    m["F"] = 0 ;
    m["P"] = m["N"] = -1 ;
    while( scanf( "%d" , &n ) != EOF ){
        double ans1 = 0 ;
        double ans2 = 0 ;
        while( n-- ){
            int tmp ;
            char temp[3] ;
            scanf( "%d %s" , &tmp , temp ) ;
            if( m[temp] != -1 ){
                ans1 += tmp*m[temp] ;
                ans2 += tmp ;
            }
        }
        printf( "%.02lf\n" , ans2?ans1/ans2:0 ) ;
    }
    return 0 ;
}