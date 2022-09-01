#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

void solve(){
    ll N, L, R;
    cin>>N>>L>>R;

    ll ans = N;

    ll l1=1, r1=N, m;

    while(l1!=r1){
        m = (l1+r1+1)/2;
        if(N/m >= L || (N%m != 0 && (N/m)+1 >= L)) l1=m;
        else r1=m-1;
    }
    
    ll l2=1, r2=l1;
    while(l2!=r2){
        m = (l2+r2)/2;
        if(N/m <= R || (N%m != 0 && (N/m)+1 <= R)) r2=m;
        else l2=m+1;
    }
    ans -= l1-r2+1;
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t=1;
    cin>>t;

    while(t--) solve();

    return 0;
}