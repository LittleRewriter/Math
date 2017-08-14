#include <iostream>
#include <cstring>
using namespace std;
#define MAXN 1000001
int main(){
    bool notprime[MAXN];
    memset(notprime,0,sizeof(notprime)); 
    notprime[1]=1;
    for(int a=2;a<MAXN;a+=(a==2?1:2))
        if(!notprime[a])  //如果不加的话复杂度nlnn 
            for(int k=2;a*k<MAXN;++k)
                notprime[k*a]=1;
    for(int i=1;i<MAXN;++i)
        if(!notprime[i])
            cout<<i<<endl;
    return 0;
}
