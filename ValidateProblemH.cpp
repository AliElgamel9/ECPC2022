#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

class ValidateGrid{
    public:
        // check current cell is connected to l-shaped
        bool check_l(int x, int y, int& n, vector<vector<int>>& arr){
            if(arr[x][y]==0) return 1;

            if(y-1>0&&x-1>0&&arr[x][y]==arr[x-1][y]&&arr[x][y]==arr[x][y-1]) return 1;
            if(y-1>0&&x+1<=n&&arr[x][y]==arr[x+1][y]&&arr[x][y]==arr[x][y-1]) return 1;
            if(y+1<=n&&x-1>0&&arr[x][y]==arr[x-1][y]&&arr[x][y]==arr[x][y+1]) return 1;
            if(y+1<=n&&x+1<=n&&arr[x][y]==arr[x+1][y]&&arr[x][y]==arr[x][y+1]) return 1;

            if(y+1<=n&&arr[x][y]==arr[x][y+1])
                return (x-1>0&&y+1<=n&&arr[x][y]==arr[x-1][y+1]) || 
                    (x+1<=n&&y+1<=n&&arr[x][y]==arr[x+1][y+1]);
            if(y-1>0&&arr[x][y]==arr[x][y-1])
                return (x-1>0&&y-1>0&&arr[x][y]==arr[x-1][y-1]) || 
                    (x+1<=n&&y-1>0&&arr[x][y]==arr[x+1][y-1]);
            if(x+1<=n&&arr[x][y]==arr[x+1][y])
                return (y-1>0&&x+1<=n&&arr[x][y]==arr[x+1][y-1]) || 
                    (y+1<=n&&x+1<=n&&arr[x][y]==arr[x+1][y+1]);
            if(x-1>0&&arr[x][y]==arr[x-1][y])
                return (y-1>0&&x-1>0&&arr[x][y]==arr[x-1][y-1]) || 
                    (y+1<=n&&x-1>0&&arr[x][y]==arr[x-1][y+1]);
            return 0;
        }

        bool validate(int& n, int& tx, int& ty, vector<vector<int>>& arr){
            // there should by m l-shaped in grid of n*n where n is power of 2
            int m = (n*n/3)+1;
            int freq[m]={0};
            bool check=1;

            for(int i=1;i<n+1;i++){
                for(int j=1;j<n+1;j++){
                    freq[arr[i][j]]++;
                    if(!check_l(i, j, n, arr)){
                        cout<<"ERROR ("<<i<<", "<<j<<")"<<endl;
                        check=0;
                        break;
                    }
                }
                if(!check) break;
            }
            // there should be only one zero in cell (tx, ty)
            if(freq[0]!=1) {
                check=0;
                cout<<"ERROR count zero= "<<freq[0]<<endl;
            }
            if(arr[tx][ty]!=0){
                check=0;
                cout<<"ERROR found ("<<arr[tx][ty]<<") instead of zero"<<endl;
            }
            // check if there are m l-shaped
            int k=1;
            while(k!=m && freq[k]==3) k++;
            if(k!=m) {
                check=0;
                cout<<"ERROR k="<<k<<", m="<<m<<endl;
            }
            
            if(check) cout<<"Successful"<<endl;
            return check;
        }
};