#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

void solve(){
    int n;
    cin>>n;

    int arr[n];

    map<int, pair<bool, bool>> flags;

    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    bool check=1;
    stack<int> s;

    for(const int x : arr){
        if(!s.empty() && s.top() == x) continue;
        if(flags[x].second){
            check=0;
            break;
        }
        if(flags[x].first){
            while(s.top() != x){
                flags[s.top()].second = 1;
                s.pop();
            }
        }
        else{
            flags[x].first = 1;
            s.push(x);
        }
    }
    cout<<(check? "YES" : "NO")<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t=1;
    cin>>t;

    while(t--) solve();

    return 0;
}