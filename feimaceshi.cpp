#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int m[]={3,7,13,37,23};
LL ksm(LL a,LL m,LL n){
	if(m==0) return 1;
	if(m==1) return a%n;
	LL w=ksm(a,m>>1,n);
	w=w*w%n;
	if(m&1) w=w*a%n;
	return w;
}
bool MR(LL n){
	if(n==2) return true;
	for(int i=0;i<5;++i){
		int a=m[i];
		if(ksm(a,n,n)!=a) return false;
	}
	return true;
}
int main(){
	freopen("MR.in","r",stdin);
	freopen("MR.out","w",stdout);
	LL n;
	scanf("%d",&n);
	if(MR(n)) printf("Yes\n");
	else printf("No\n");
	return 0;
}
