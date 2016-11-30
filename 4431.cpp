/*
sample input:
5
1s 2s 3s 2c 2c 2c 2p 3p 5m 6m 7m 1p 1p
1p 1p 2p 4p 4s 5s 6s 7c 7c 7c 2m 2m 2m
7c 7s 3s 3s 2m 2m 6s 1p 2p 2p 1p 7s 7c
9s 1s 1p 9s 9p 9m 1c 4c 5c 3c 7c 2c 6c
1c 2c 3c 2c 2c 2c 2p 3p 5m 6m 7m 1p 1p
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <cmath>
using namespace std;

int ans;
string ans_str;
int ans_index[55];
int tiles_num[55];
char type[5]="mspc";
int w[13]={1,9,11,19,21,29,31,32,33,34,35,36,37};

bool win1(){
	int i,t1=0,t2=0;
	for(i=0;i<13;++i){
		if(tiles_num[w[i]]==1) t1++;
		else if(tiles_num[w[i]]==2) t2++;
	}
	if(t1==12&&t2==1) return true;
	else
		return false;
}

bool win2(){
	int i;
	int res=0;
	for(int i=1;i<=37;++i){
		if(tiles_num[i]==2) res++;
	}
	return res==7;
}

bool dfs(int mm,int pp,int kk){
	bool flag;
	if(kk==37&&mm==0&&pp==0) return true;
	if(tiles_num[kk]==0) return dfs(mm,pp,kk+1);
	if(tiles_num[kk]>=3){
		tiles_num[kk]-=3;
		flag=dfs(mm-1,pp,kk);
		tiles_num[kk]+=3;
		if(flag) return true;
	}
	if(tiles_num[kk]>=2&&pp){
		tiles_num[kk]-=2;
		flag=dfs(mm,pp-1,kk);
		tiles_num[kk]+=2;
		if(flag) return true;
	}
	if(kk/10<3&&kk%10<=7&&tiles_num[kk+1]&&tiles_num[kk+2]){
		tiles_num[kk]--;tiles_num[kk+1]--;tiles_num[kk+2]--;
		flag=dfs(mm-1,pp,kk);
		tiles_num[kk]++;tiles_num[kk+1]++;tiles_num[kk+2]++;
		if(flag) return true;
	}
	return false;
}

int main(){
	// freopen("0input.txt","r",stdin);
	int i;
	char str[5];
	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		ans=0;
		ans_str="";
		memset(tiles_num,0,sizeof(tiles_num));
		for(i=0;i<13;++i){
			scanf("%s",str);
			tiles_num[(strstr(type,str+1)-type)*10+str[0]-'0']++;
		}
		for(i=1;i<=37;++i){
			if(i%10==0) continue;
			if(tiles_num[i]>=4) continue;
			tiles_num[i]++;
			if(win1()||win2()||dfs(4,1,1)){
				ans_index[ans++]=i;
			}
			tiles_num[i]--;
		}
		if(!ans){
			printf("Nooten\n");
		}
		else{
			printf("%d",ans);
			for(i=0;i<ans;++i)
				printf(" %d%c",ans_index[i]%10,type[ans_index[i]/10]);
			puts("");
		}
	}
	return 0;
}