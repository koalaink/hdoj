#include<iostream>

#include<vector>

using namespace std;

int main(){
    vector<char> level;
    int point;
    while(cin>>point){
        if(point<0 || point>100)
            level.push_back('F');
        else if(point<60)
            level.push_back('E');
        else if(point<70)
            level.push_back('D');
        else if(point<80)
            level.push_back('C');
        else if(point<90)
            level.push_back('B');
        else
            level.push_back('A');
    }

    for(int i=0;i<level.size();i++)
        if(level[i]!='F')
            cout<<level[i]<<endl;
        else
            cout<<"Score is error!"<<endl;
}