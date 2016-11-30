#include<iostream>
#include<stdio.h>
#include<memory.h>
#include<string>
using namespace std;

void change( char s[5100] , char ans[5100] ){
	int i , j = 0;
	for( i = 0 ; s[i] != '\0' ; ++i )
		if( s[i] != ' ' && s[i] != '\n' && s[i] != '\t' )
			ans[j++] = s[i] ;
	return ;
}

int main(){
	int t , len ;
	char correct[5100];
	char resultf[5100];
	char tmp[5100] , tmp1[5100];
	scanf( "%d" , &t );
	getchar();
	while( t-- ){
		memset( correct , '\0' , sizeof(correct) );
		memset( resultf , '\0' , sizeof(resultf) );
		memset( tmp , '\0' , sizeof(tmp) );
		gets(tmp);
		gets(correct);
		gets(tmp);
		while( strcmp( tmp , "END" ) != 0 ){
			len = strlen(correct);
			correct[len++] = '\n' ;
			correct[len++] = '\0' ;
			if( strlen(tmp) )
				strcat( correct , tmp );
			gets(tmp);
		}
		gets(tmp);
		gets(resultf);
		gets(tmp);
		while( strcmp( tmp , "END" ) != 0 ){
			len = strlen(resultf);
			resultf[len++] = '\n' ;
			resultf[len++] = '\0' ;
			if( strlen(tmp) )
				strcat( resultf , tmp );
			gets(tmp);
		}
		if( strcmp( correct , resultf ) == 0 )
			printf( "Accepted\n" );
		else{
			memset( tmp , '\0' , sizeof(tmp) );
			memset( tmp1 , '\0' , sizeof(tmp) );
			change(correct,tmp);
			change(resultf,tmp1);
			if( strcmp( tmp , tmp1 ) == 0 )
				printf( "Presentation Error\n" );
			else
				printf( "Wrong Answer\n" );
		}
	}
	return 0;
}