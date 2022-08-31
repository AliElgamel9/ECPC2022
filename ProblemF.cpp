#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

void solve(){
    map<int, string> arr {
        {1508, "pocket watches"},
        {1608, "telescopes"},
        {1708, "steam engines"},
        {1808, "telephones"},
        {1908, "airplanes"},
        {2008, "terraforming"},
        {2108, "exploration"},
        {2208, "relaxing"},
        {2308, "going above and beyond"},
        {2408, "second chances"},
        {2508, "the origin"},
        {2608, "empowering the youth"},
        {2708, "ECPC"}
    };
    int y; cin>>y;

    cout<<arr[y]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t=1;
    //cin>>t;

    while(t--) solve();

    return 0;
}