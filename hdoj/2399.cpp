#include<iostream>
const int MAX=1000;
char s[MAX];
using namespace std;
int main()
{
    int n,i,j,p;
    double m;
    while(gets(s))
    {
        n=strlen(s);
        m=0;
        j=0;
        p=0;
        for(i=0;i<n;i++)
        {
            switch(s[i])
            {
                case'A':m+=4;j+=1;break;
                case'B':m+=3;j+=1;break;
                case'C':m+=2;j+=1;break;
                case'D':m+=1;j+=1;break;
                case'F':m+=0;j+=1;break;
                case' ':break;
                default:p=1;break;
            }
        }
        if(p==1)
        cout<<"Unknown letter grade in input"<<endl;
        else
        printf("%.2lf\n",m/j);
    }
    return 0;
}