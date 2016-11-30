#include<iostream>
#include<vector>
using namespace std;
main()
{
    vector<char> s;
    int n,r,temp,i,is=0;
    while(scanf("%d%d",&n,&r)!=EOF){
        if(n<0){n=-n;is=1;}
        while(n>0){
            temp=n%r;
            if(temp>=10){
                switch(temp){
                case 10:s.push_back('A');break;
                case 11:s.push_back('B');break;
                case 12:s.push_back('C');break;
                case 13:s.push_back('D');break;
                case 14:s.push_back('E');break;
                case 15:s.push_back('F');break;
                case 16:s.push_back('G');break;
                }
            }
            else s.push_back((char)(temp+'0'));
            n=n/r;
        }
        while(s[s.size()-1]=='0') s.pop_back();
        if(is) cout<<'-';
        for(i=s.size()-1;i>=0;i--)
            cout<<s[i];
        cout<<endl;
        s.clear();
        is=0;
    }
}