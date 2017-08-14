#include <iostream>
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	LL gcd,tmp;
	gcd=exgcd(b,a%b,x,y);
	tmp=x;
	x=y,y=tmp-a/b*y;
	return gcd;
}
int main(){
	LL a,b,x,y,z;
	cin>>a>>b;
	z=exgcd(a,b,x,y);
	cout<<z<<" "<<x<<" "<<y<<endl;
	return 0;
}
