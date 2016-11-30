/*
sample input:
3
2
1 0 3
4 5 6 7 8
9 0 11
10
0
1 2 3
4 5 6 7 8
9 10 11
0
0
11 10 9
8 7 6 5 4
3 2 1
0
 */
#include <iostream>
#include <memory.h>
#include <stdio.h>
#include <string>
#include <queue>
#include <map>
using namespace std;

struct node{
	int pos[2][2];
	int maze[6][6];
	int step;
	bool check(int index){
		if(pos[index][0]<1||pos[index][0]>5||pos[index][1]<1||pos[index][1]>5||maze[pos[index][0]][pos[index][1]]==-1)
			return false;
		return true;
		//return maze[pos[index][0]][pos[index][1]]!=-1;
	}
};

int ans;
bool flag;
node st,ed;
string end_str;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

string get_str(node T_T){
	string res="";
	for(int i=1;i<=5;++i){
		for(int j=1;j<=5;++j){
			if(T_T.maze[i][j]==-1) continue;
			if(T_T.maze[i][j]<10)
				res+=(char)(T_T.maze[i][j]+'0');
			else
				res+=(char)(T_T.maze[i][j]-10+'a');
		}
	}
	return res;
}

bool d_bfs(){
	queue<node> q[2];
	node cur,nex;
	map<string ,int > vis[2];
	string tmp=get_str(st);
	// cout<<tmp<<endl;
	if(tmp==end_str){
		ans=0;
		return true;
	}
	st.step=0;
	ed.step=0;
	q[0].push(st);
	q[1].push(ed);
	vis[0][tmp]=1;
	vis[1][end_str]=1;
	while( !q[0].empty() || !q[1].empty() ){
		for(int index=0;index<2;++index){
			cur=q[index].front();
			q[index].pop();
			for(int i=0;i<2;++i){
				for(int d=0;d<4;++d){
					nex=cur;
					nex.step++;
					nex.pos[i][0]+=dir[d][0];
					nex.pos[i][1]+=dir[d][1];

					if(nex.pos[i][0]==nex.pos[1-i][0]&&nex.pos[i][1]==nex.pos[1-i][1]) continue;
					// if(cur.maze[cur.pos[i][0]][cur.pos[i][1]]==0&&cur.maze[nex.pos[i][0]][nex.pos[i][1]]==0) continue;
					if(nex.check(i)){
						nex.maze[cur.pos[i][0]][cur.pos[i][1]]=cur.maze[nex.pos[i][0]][nex.pos[i][1]];
						nex.maze[nex.pos[i][0]][nex.pos[i][1]]=0;
						tmp=get_str(nex);
						//cout<<nex.step<<" "<<tmp<<endl;system("pause");
						if(vis[1-index][tmp]){
							ans=nex.step+vis[1-index][tmp]-1;
							return true;
						}
						if(nex.step>11) return false;
						if(!vis[index][tmp]){
							vis[index][tmp]=nex.step+1;
							q[index].push(nex);
						}
					}
				}
			}
		}
	}
	return false;
}

int main(){
	// freopen("0input.txt","r",stdin);
	memset(st.maze,-1,sizeof(st.maze));
	memset(ed.maze,-1,sizeof(ed.maze));
	int n,i,j,k=1;
	end_str="";
	end_str+='0';
	for(i=2;i<=4;++i) end_str+=(char)('0'+k),ed.maze[2][i]=st.maze[2][i]=k++;
	for(i=1;i<=5;++i) end_str+=(char)('0'+k),ed.maze[3][i]=st.maze[3][i]=k++;
	for(i=2;i<=4;++i) end_str+=k==10?'a':(k==11?'b':(char)('0'+k)),ed.maze[4][i]=st.maze[4][i]=k++;
	end_str+='0';
	st.maze[1][3]=st.maze[5][3]=1;
	ed.maze[1][3]=ed.maze[5][3]=0;
	int T_T;
	scanf("%d",&T_T);
	while(T_T--){
		int index=0;
		for(i=1;i<=5;++i){
			for(j=1;j<=5;++j){
				if(st.maze[i][j]==-1) continue;
				scanf("%d",&st.maze[i][j]);
				if(st.maze[i][j]==0){
					st.pos[index][0]=i;
					st.pos[index++][1]=j;
				}
			}
		}
		ed.pos[0][0]=1;
		ed.pos[0][1]=3;
		ed.pos[1][0]=5;
		ed.pos[1][1]=3;
		// flag=false;
		if(d_bfs()&&ans<=20) printf("%d\n",ans);
		else printf("No solution!\n");
	}
	return 0 ;
}

