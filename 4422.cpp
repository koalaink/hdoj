/*
sample input:
1
9
4
512 512 512 512
5
100 200 300 400 500
5
208 308 508 708 1108
 */
#include <memory.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int arr[6];
int n ;

int main(){
	// freopen("0input.txt","r",stdin);
	while(scanf("%d",&n)!=EOF){
		memset(arr,-1,sizeof(arr));
		for(int i=0;i<n;++i) scanf("%d",&arr[i]);
		if(n<=3){
			printf("1024\n");
			continue;
		}int ans=0,tmp,tans;
		int x,y;
		for(int i=0;i<3;++i){
			for(int j=i+1;j<4;++j){
				for(int k=j+1;k<5;++k){
					bool m=false;
					x=y=0;
					for(int f=0;f<5;++f){
						if(f!=i&&f!=j&&f!=k){
							if(!m){x=f;m=true;}
							y=f;
						}
					}
					// printf("%d %d %d %d %d\n",i,j,k,x,y);
					if(k==4&&n==4 || (arr[i]+arr[j]+arr[k])%1024==0){
						tmp=(y==4&&n==4)?1024:(arr[x]+arr[y]);
						if( tmp==0) continue;
						tmp=((tmp%1024==0)?1024:(tmp%1024));
						ans=ans<tmp?tmp:ans;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0 ;
}