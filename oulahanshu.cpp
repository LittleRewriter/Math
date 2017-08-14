#include <iostream>
#define MAXN 40003
using namespace std;
int n;
int phi[MAXN],prime[MAXN],cnt,ans;
bool notprime[MAXN];
void getphi(){
    int i,j;
    phi[1]=1;
    for(i=2;i<=40000;++i){
        if(!notprime[i]){
            prime[++cnt]=i;
            phi[i]=i-1;
        }
        for(j=1;j<=cnt;++j){
            if(i*prime[j]>0) break;
            notprime[i*prime[j]]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }else{
                phi[i*prime[j]]=phi[i]*(prime[j]-1);
            }
        }
    }
}
int main(){
    getphi();
    return 0;
}
