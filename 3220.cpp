#include<iostream>
#include<memory.h>
#include<stdio.h>
#include<string>
#include<queue>
#include<map>
using namespace std;

const int S_STATUS = (1<<16) - (1<<8) ;
int dir[16][4] = {{1,2,4,8},{0,3,5,9},{0,3,6,10},{1,2,7,11},{0,5,6,12},{1,4,7,13},{2,4,7,14},{3,5,6,15},{0,9,10,12},{1,8,11,13},{2,8,11,14},{3,9,10,15},{4,8,13,14},{5,9,12,15},{6,10,12,15},{7,11,13,14}} ;
/*bool matrix[16][16] = { {0,1,1,0,1,0,0,0,1,0,0,0,0,0,0,0} ,
	{1,0,0,1,0,1,0,0,0,1,0,0,0,0,0,0} , 
	{1,0,0,1,0,0,1,0,0,0,1,0,0,0,0,0} ,
	{0,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0} ,
	{1,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0} ,
	{0,1,0,0,1,0,0,1,0,0,0,0,0,1,0,0} ,
	{0,0,1,0,1,0,0,1,0,0,0,0,0,0,1,0} ,
	{0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,1} ,
	{1,0,0,0,0,0,0,0,0,1,1,0,1,0,0,0} ,
	{0,1,0,0,0,0,0,0,1,0,0,1,0,1,0,0} ,
	{0,0,1,0,0,0,0,0,1,0,0,1,0,0,1,0} ,
	{0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,1} ,
	{0,0,0,0,1,0,0,0,1,0,0,0,0,1,1,0} ,
	{0,0,0,0,0,1,0,0,0,1,0,0,1,0,0,1} ,
	{0,0,0,0,0,0,1,0,0,0,1,0,1,0,0,1} ,
	{0,0,0,0,0,0,0,1,0,0,0,1,0,1,1,0} };*/
map<int,int> ans ;

struct node{
	int step ;
	int status ;
};

void bfs(){
	queue<node> q ;
	node cur , nex ;
	cur.step = 0 ;
	cur.status = S_STATUS ;
	ans[S_STATUS] = 0 ;
	q.push(cur) ;
	while( !q.empty() ){
		cur = q.front() ;
		q.pop() ;
		if( cur.step == 3 )
			continue ;
		for( int i = 0 ; i < 16 ; ++i ){
			int si = cur.status&(1<<i) ;
			for( int j = 0 ; j < 4 ; ++j ){
				int sj = cur.status&(1<<dir[i][j]) ;
				if( si*sj==0&&si+sj!=0 ){
					nex.status = cur.status^(1<<i) ;
					nex.status = nex.status^(1<<dir[i][j]) ;
					nex.step = cur.step + 1 ;
					if( ans[nex.status] ){
						continue ;
					}
					ans[nex.status] = nex.step ;
					q.push(nex) ;
				}
			}
		}
	}
	return ;
}

int main(){
	int t ;
	int tmp ;
	bfs();
	while( scanf("%d",&t) != EOF ){
		for( int cas = 1 ; cas <= t ; ++cas ){
			int eStatus = 0 ;
			for( int i = 0 ; i < 16 ; ++i ){
				scanf("%d" , &tmp ) ;
				tmp==1?tmp=tmp<<i:tmp=0;
				eStatus += tmp ;
			}
			if( eStatus == S_STATUS ){
				printf( "Case #%d: 0\n" , cas  ) ;
			}
			else if( ans[eStatus] ){
				printf( "Case #%d: %d\n" , cas , ans[eStatus] ) ;
			}
			else{
				printf( "Case #%d: more\n" , cas  ) ;
			}
		}
	}
	return 0 ;
}