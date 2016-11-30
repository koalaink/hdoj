#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<string>
using namespace std;

int main(){
	char s1[105][105] , s2[105][105] , op[5] ;
	char tmp[105] , tmp1[105];
	// freopen( "0input.txt" , "r" , stdin );
	int i , j , len , index1 , index2 ;
	while( scanf( "%s" , tmp ) ){
		memset( s1 , '\0' , sizeof(s1) );
		memset( s2 , '\0' , sizeof(s2) );
		if( strcmp(tmp,".") == 0 )
			break;
		scanf( "%s%s" , op , tmp1 );
		index1 = j = 0 ;
		len = strlen(tmp);
		for( i = 1 ; i < (len - 1) ; ++i ){
			for( j = 0 ; i+j<(len-1) && tmp[i+j] != ',' ; ++j )
				s1[index1][j] = tmp[i+j] ;
			i+=j;
			++index1;
		}
		index2 = j = 0 ;
		len = strlen(tmp1);
		for( i = 1 ; i < (len - 1) ; ++i ){
			for( j = 0 ; i+j<(len-1) && tmp1[i+j] != ',' ; ++j )
				s2[index2][j] = tmp1[i+j] ;
			i+=j;
			++index2;
		}
		if( strcmp(op,"++") == 0 )
			for( i = 0 ; i < index2 ; ++i )
				strcpy( s1[index1++] , s2[i] );
		else{
			for( i = 0 ; i < index2 ; ++i ){
				for( j = 0 ; j < index1 ; ++j )
					if( s1[j][0] != '\0' && strcmp(s2[i],s1[j]) == 0 ){
						s1[j][0] = '\0' ;
						break;
					}
			}
		}
		printf( "[" );
		i = 0 ;
		while( i < index1 && s1[i][0] == '\0' ) i++;
		if( i < index1 )
			printf( "%s" , s1[i++] );
		for( ; i < index1 ; ++i )
			if( s1[i][0] != '\0' )
				printf( ",%s" , s1[i]);
		printf( "]\n" );
	}
	return 0;
}