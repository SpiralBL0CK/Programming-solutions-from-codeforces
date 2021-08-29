#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll ans=0;
    for(ll i=a;i<=b;i++){
        ll mn=i+b-1,mx=i+c-1;
        if(mn>=d) ans+=(d-c+1)*(c-b+1);
        else{
            ll l=max(mn,c),r=min(d,mx);
            ans+=(r-l+1)*(l-c+1+r-c+1)/2;
            if(mx>d) ans+=(mx-d)*(d-c+1);
        }
    }
     cout<<ans;
}