#include <bits/stdc++.h>

#define long long ll
#define endl "\n"

using namespace std;

void solve(){
    int n; cin>>n;

    int x, ans=0;

    for(int i=0;i<n;i++){
        cin>>x;
        if(ans<x) ans=x;
    }
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}