#include <iostream>
#include <vector>
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
vector<pair<LL,LL> > v;
bool work(LL a,LL b,LL c,LL l,LL r,LL L,LL R){
	LL x,y;
	LL gcd=exgcd(a,b,x,y);
	if(c%gcd) return false;
	x*=c/gcd,y*=c/gcd;
	v.push_back(make_pair(x,y));
	for(LL p=x+b,q=y-a;p<=r&&p>=l&&q<=R&&q>=L;p+=b,q-=a)
		v.push_back(make_pair(p,q));
	for(LL p=x-b,q=y+a;p<=r&&p>=l&&q<=R&&q>=L;p-=b,q+=a)
		v.push_back(make_pair(p,q));
	return true;
}
int main(){
	LL a,b,c,l,r,L,R;
	cin>>a>>b>>c>>l>>r>>L>>R;
	if(work(a,b,c,l,r,L,R)){
		vector<pair<LL,LL> >::iterator it;
		for(it=v.begin();it!=v.end();++it)
			cout<<it->first<<" "<<it->second<<endl;
	}
}
