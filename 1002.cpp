#include<iostream>
#include<string>
using namespace std;
int main(){
    int n,i,j,k;
    char* addString(char*,char*);    // a function to count a-string add to b-string ,return a sum-string
    char a[1000],b[1000];            // a + b 
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%s%s",&a,&b);        
        char *c=addString(a,b);    
        printf("Case %d:\n",i+1);
        printf("%s + %s = %s\n",a,b,c);
        if(i!=(n-1)) printf("\n");
    }
}

char * addString(char* a,char* b){
    char c[10000];
    int l1=strlen(a),l2=strlen(b);
    if(l1<l2) {int temp=l1;l1=l2;l2=temp;char *x=a;a=b;b=x;}        // to make sure l1>=l2 
    int i,j,carry=0;
    c[l1+1]='\0';
    for(i=l1,j=l2;i>0;i--,j--){
        if(j>0){
            c[i]=a[i-1]+carry+b[j-1]-48;
            carry=(c[i]-48)/10;
            c[i]=(c[i]-48)%10+48;
        }else{
            c[i]=a[i-1]+carry;
            carry=(c[i]-48)/10;
            c[i]=(c[i]-48)%10+48;
        }
        if(c[i]>'9'){carry=(c[i]-48)/10;c[i]=(char)((c[i]-48)%10+48);}
    }
    if(carry){
        c[i]='1';return c;
    }else return c+1;
}