#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int main(){
    LL a;
    cin>>a;
    vector<pair<LL,int> > v;
    vector<pair<LL,int> >::iterator vi;
    for(int i=2;i*i<=a;i+=(i==2?1:2)){
        if(a%i==0){
            int count=0;
            while(a%i==0)
                ++count,a/=i;
            v.push_back(make_pair(i,count));
        }
    }
    if(a!=1) v.push_back(make_pair(a,1));
    for(vi=v.begin();vi!=v.end();++vi)
        cout<<vi->first<<" "<<vi->second<<endl;
}
