#include<iostream>
#include<string.h>
using namespace std;
char code[10010];
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        cin>>code;
        for(int i=0;code[i]!='\0';)
        {
            int count=1;
            while(code[i]==code[i+1])
            {
                count++;
                i++;
            }

            if(count==1)cout<<code[i];
            else cout<<count<<code[i];
            i++;
        }
        cout<<endl;
    }
    return 0;
}
 
