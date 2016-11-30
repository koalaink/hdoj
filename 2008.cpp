#include<iostream>

#include<vector>

using namespace std;

int main(){
    int n, i, a, b, c;
    double x;
    vector<int> count;
    while (scanf("%d", &n) , n){
        (a=0,b=0,c=0);
        for (i = 0 ; i < n ; i++){
            scanf("%lf", &x);
            if (x > 0) c++;
            else if (x < 0) a++;
            else b++;
        }
        count.push_back(a);
        count.push_back(b);
        count.push_back(c);
    }

    for(i=0;i<count.size();i+=3)
        printf("%d %d %d\n",count[i],count[i+1],count[i+2]);
    return 0;
}
