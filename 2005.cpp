#include<iostream>

#include<vector>

#include<string>

using namespace std;

int year,month,day;

int main(){
    vector<int> number;
    int monthday[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };
    while(scanf("%d/%d/%d",&year,&month,&day)!=EOF){
        int yea;
        if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) yea=1;
        else yea=0;

        for(int i=1;i<month;i++)
            day+=monthday[yea][i];
        number.push_back(day);
    }
    for(int j=0;j<number.size();j++)
        cout<<number[j]<<endl;
}

