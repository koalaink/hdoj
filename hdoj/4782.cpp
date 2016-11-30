/*
sample input:
2
<html><body>
<h1>ACM
ICPC</h1><p></p>
<p>Hello<br/>World</p>
<p>hah wo qu a   d </p>
<a href="http://baidu.com/">baidu</a>
</body></html>
<html><body><p>
Asia Chengdu Regional</p>
<p class="icpc">
ACM-ICPC</p></body></html>
 */
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string ans;

int main(){
	int t,cas=1;
	int ci,index,i;
	char c;
	freopen("0input.txt","r",stdin);
	char tag[100005];
	scanf( "%d" , &t ) ;
	c=getchar();
	bool first;
	// printf("[pre]");
	while( t-- ){
		ci=0;
		first=true;
		ans.clear();
		printf("Case #%d:\n",cas++);
		while(true){
			while(c==' '||c=='\n'||c=='\t') c=getchar();
			if( c=='<' ){
				c=getchar();
				if( c=='/' ){
					index=1;
					tag[0]=c;
					while(c=getchar()){
						tag[index++]=c;
						if(c=='>'){
							--ci;
							break;
						}
					}
					if(!first) ans+='\n';
					for(i=0;i<ci;++i) ans+=' ';
				}
				else{
					bool flag=true;
					index=1;
					tag[0]=c;
					while(c=getchar()){
						tag[index++]=c;
						if(c=='>'){
							if( tag[index-2]!='/' ){
								flag=false;
								++ci;
							}
							break;
						}
					}
					if(!first) ans+='\n';
					first=false;
					for(i=1;i<ci;++i) ans+=' ';
					if(flag) ans+=' ';
				}
				tag[index]='\0';
				ans+='<';
				for(i=0;i<index;++i) ans+=tag[i];
				c=getchar();
				while(c==' '||c=='\n'||c=='\t') c=getchar();
			}
			else{
				bool flag1=false;
				if(ci) ans+='\n';
				for(i=0;i<ci;++i) ans+=' ';
				ans+=c;
				while(c=getchar()){
					flag1=false;
					while(c==' '||c=='\n'||c=='\t'){flag1=true;c=getchar();}
					if(c=='<') break;
					if(flag1) ans+=' ';
					ans+=c;
				}
			}
			if(ci==0 || strcmp("/html>",tag)==0 ) break;
		}
		ans+="\0";
		cout<<ans<<endl;
	}
	// printf("[/pre]\n");
	return 0 ;
}