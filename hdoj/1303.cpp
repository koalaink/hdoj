#include<iostream>
#include<vector>
using namespace std;
int main(){
    int x,end=0;
    vector<int> lists;
    while(scanf("%d",&x)&&(x+1)){
        int result=0;
        lists.push_back(x);
        while(cin>>x,x)
            lists.push_back(x);
        for(int i=0;i<lists.size();i++){
            for(int j=0;j<lists.size();j++){
                if(i==j) continue;
                if(lists[i]*2==lists[j]) result++;
            }
        }
        cout<<result<<endl;
        lists.clear();
    }
}