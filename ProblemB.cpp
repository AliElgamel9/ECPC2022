#include <bits/stdc++.h>

#define long long ll
#define endl "\n"

using namespace std;

void solve(){
    int n, m, x;
    cin>>n;
    m = 1e5+1;

    int A[n];
    int B_pos[m]={0};

    for(int i=0;i<n;i++)
        cin>>A[i];

    for(int i=1;i<n+1;i++){
        cin>>x;
        B_pos[x] = i;
    }

    int rotations[n]={0};
    
    for(int i=0;i<n;i++){
        for(int j=sqrt(A[i]);j>0;j--){
            if(A[i]%j != 0) continue;
            if(B_pos[j] != 0)
                rotations[(B_pos[j]-i-1+n)%n]++;
            if(B_pos[A[i]/j] != 0)
                rotations[(B_pos[A[i]/j]-i-1+n)%n]++;
        }
        // if number is in form x^2 then it has increased a rotation twice.
        x = sqrt(A[i]);
        if(A[i]%x == 0 && B_pos[x] != 0) rotations[(B_pos[x]-i-1+n)%n]--;
    }
    cout<<*max_element(rotations, rotations+n)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t;
    cin>>t;

    while(t--) solve();

    return 0;
}