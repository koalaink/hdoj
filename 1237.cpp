#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;

double count( char s[205] ){
	int len = strlen(s);
	int tmp ;
	char op = 'f' ;
	double ans = 0;
	for( int i = 0 ; i < len ; ++i ){
		tmp = 0 ;
		while( i < len && s[i] != '*' && s[i] != '/' )
			tmp = tmp * 10 + s[i++] - '0' ;
		if( op == '*' )
			ans = ans *  tmp ;
		else if ( op == '/' )
			ans = ans / tmp ;
		else
			ans += tmp ;
		op = s[i] ;
	}
	return ans;
}

int main(){
	char s[205];
	char s1[205];
	char tmp ;
	int i , len , index ;
	double tmp1 , tmp2 , ans ;
	char op = 'f' ;
	while( cin.getline(s,205) ){
		if( strcmp(s,"0") == 0 )
			break;
		len = strlen(s);
		index = 0;
		ans = 0;
		int index1 = 0;
		while( index < len ){
			memset(s1,'\0',sizeof(s1));
			index1=0;
			while( index < len && s[index] != '+' && s[index] != '-' ){
				if( s[index] == ' '){
					++index;
					continue;
				}
				s1[index1++] = s[index++];
			}
			tmp1 = count(s1);
			if( op == '+' )
				ans += tmp1;
			else if( op == '-' )
				ans -= tmp1;
			else
				ans = tmp1;
			op = s[index];
			index+=2;
		}
		printf( "%.2lf\n" , ans );
	}
	return 0;
}