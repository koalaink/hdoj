#include<iostream>
#include<string>
using namespace std;
main()
{
    int n,i,c;
    cin>>n;
    getchar();
    char s[1000];
    while(n--){
        gets(s);
        c=0;
        for(i=0;i<strlen(s);i++)
            if((int)s[i]<0)
                c++;
        cout<<c/2<<endl;
    }
}