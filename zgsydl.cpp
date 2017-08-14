#include <iostream>
using namespace std;
typedef long long LL;
#define MAXN 10003
LL W[MAXN],B[MAXN],k;//k个方程式表示a同余B[n](mod W[n])
LL exgcd(LL a,LL b,LL &x,LL &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    LL gcd=exgcd(b,a%b,x,y);
    LL t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
LL china(){
    LL x,y,a=0,m,n=1;
    for(int i=0;i<k;++i) n*=W[i];
    for(int i=0;i<k;++i){
        m=n*W[i];
        exgcd(W[i],m,x,y);
        a=(a+y*m*B[i])%n;
    }
    if(a>0) return a;
    else return a+n;
}
int main(){
    cin>>k;
    for(int i=0;i<k;++i)
        cin>>W[i]>>B[i];
    cout<<china();
}