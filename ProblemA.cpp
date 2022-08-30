#include <bits/stdc++.h>

#define long long ll
#define endl "\n"

using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n+1];

    for(int i=0;i<n+1;i++)
        cin>>arr[i];
    
    int result[n+1];
    result[n] = arr[0];

    for(int i=n-1;i>0;i--)
        result[i] = arr[result[i+1]];

    for(int i=1;i<=n;i++)
        cout<<result[i]<<" ";
    cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    
    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}