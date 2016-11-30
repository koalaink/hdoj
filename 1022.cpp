#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main(){
    string oi,oo;
    int n;
    while(cin>>n>>oi>>oo){
        int i=1,j=0;
        stack<char>st;
        st.push(oi[0]);
        for(;j<n;j++){
            while(st.empty() || st.top()!=oo[j] && i<n){
                st.push(oi[i]);i++;
            }
            if(st.top()==oo[j]){
                st.pop();
                continue;
            }
            break;
        }
        if(st.empty()){
            st.push(oi[0]);
            printf("Yes.\nin\n");
            i=1,j=0;
            for(;j<n;j++){
                while(st.empty() || st.top()!=oo[j] && i<n ){
                    st.push(oi[i]);i++;
                    printf("in\n");
                }
                if(st.top()==oo[j]){
                    st.pop();
                    printf("out\n");
                    continue;
                }
                break;
            }
            printf("FINISH\n");
        }
        else{
            printf("No.\nFINISH\n");
        }
    }
}