#include <iostream>
#include <cstring>
#define MAXN 14
using namespace std;
bool notprime[MAXN];
int prime[MAXN];
int main(){
    notprime[1]=true;
    int count=0;
    for(int i=2;i<MAXN;++i){
        if(!notprime[i])
            prime[++count]=i;
        for(int j=1;j<=count;++j){
            if(prime[j]*i>MAXN) 
                break;
            notprime[prime[j]*i]=true;
            if(i%prime[j]==0)
                break;
        }
    }
    for(int i=1;i<MAXN;++i)
        if(!notprime[i])
            cout<<i<<endl;
}
