#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

void solve(){
    int n, m;
    cin>>n;
    m = 1e6;

    int freq[m+1]={0};
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
        freq[arr[i]]++;
    }

    sort(arr, arr+n);

    ll ans=0;

    for(int i=0;i<n;i++){

        int p = __builtin_popcount(arr[i]);
        // if the number is power of 2 and not 1, then take triple combinations of it.
        if(p == 1 && arr[i] != 1){
            ll f = freq[arr[i]]-1;
            ans += (f*(f+1)*(f-1))/6;
        }

        for(int j=i+1;j<n;j++){
            // skip duplicated numbers
            j += freq[arr[j]]-1;

            int res = arr[i]^arr[j];

            // find the t that makes (res xor t) = 2 power of x, where x from 1 to 19
            for(int k=1;k<20;k++){
                int t = res^(1<<k);

                // target number is out of range
                if(t > m) continue;
                
                // if the target is one of these 2 numbers, 
                // then take triple combinations between these 2 numbers.
                if(t == arr[i] || t == arr[j]){
                    ll p = (freq[t] * (freq[t]-1)) / 2;
                    ans += p * freq[t^arr[i]^arr[j]];
                }
                // the target is a number that taken before
                else if(t < arr[j]) continue;
                // take triple combinations between these 3 numbers
                else
                    ans += freq[arr[i]] * freq[arr[j]] * freq[t];
            }
        }
        // skip duplicated numbers
        i += freq[arr[i]]-1;
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