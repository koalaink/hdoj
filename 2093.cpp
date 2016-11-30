#include<iostream>
#include<algorithm>
#include<iomanip>
#include<string>
using namespace std;
struct student{
public:
    string name;
    int solved;
    int time;
};

void change(student& s,string pr,int m){
    if(pr[0]=='0' || pr[0]=='-') return ;
    s.solved++;
    int i=0,t=0;
    while(i<pr.size() && pr[i]!='('){
        t=t*10+pr[i]-'0';
        i++;
    }
    s.time+=t;
    if(i==pr.size()) return ;
    t=0;
    i++;
    while(i<pr.size() && pr[i]!=')'){
        t=t*10+(int)(pr[i]-'0');
        i++;
    }
    s.time+=m*t;
    return ;
}

bool cmp(student a,student b)
{
    if(a.solved==b.solved)
    {
        if(a.time==b.time)
        {
            return strcmp(a.name.c_str(),b.name.c_str())<0;
        }
        else
        return a.time<b.time;
    }
    else
    return a.solved>b.solved;
}

int main(){
    struct student st[1000];
    int n,m,i;
    while(scanf("%d%d",&n,&m)!=EOF){
        i=0;
        while(cin>>st[i].name && getchar() ){
            st[i].solved=0;st[i].time=0;
            for(int j=0;j<n;j++){
                string p;
                cin>>p;
                change(st[i],p,m);
            }
            i++;
        }
        sort(st,st+i,cmp);
        for(int j=0;j<i;j++)
            printf("%-10s %2d %4d\n",st[j].name.c_str(),st[j].solved,st[j].time);
            //printf("%-10s % 2d % 4d\n",st[j].name.c_str(),st[j].solved,st[j].time);
    }
    return 0;
}