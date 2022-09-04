#include <bits/stdc++.h>

#define ll long long
#define endl "\n"

using namespace std;

/*
    Time Complexity O(N) = (2^N)*(2^N)+4^(log2(n)-2)*2
    Space Complexity O(N) = (2^8)*(2^8)+1
*/

vector<vector<int>> arr;
int n, c, tx, ty;
bool flags[4][2]= {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
int center[4][2]= {{1, 1}, {1, 2}, {2, 1}, {2, 2}};

void fill_4by4(int x, int y){
    arr[x][y]=arr[x][y+1]=arr[x+1][y]=c++;
    arr[x+2][y]=arr[x+3][y+1]=arr[x+3][y]=c++;
    arr[x][y+2]=arr[x+1][y+3]=arr[x][y+3]=c++;
    arr[x+3][y+3]=arr[x+2][y+3]=arr[x+3][y+2]=c++;
    arr[x+1][y+1]=arr[x+1][y+2]=arr[x+2][y+1]=arr[x+2][y+2]=c++;
}

void merge_grid(int x, int y, int size, int bx, int by){
    if(size==4) return;
    
    int temp = c++;
    
    // break the grid into 4 grids and solve each one
    for(int i=0;i<4;i++){
        // the position of the top left corner of the grid 4by4
        int newposx = x+size/2 * flags[i][0];
        int newposy = y+size/2 * flags[i][1];
        if(bx >= newposx && bx < newposx+size/2 && by>=newposy && by< newposy+size/2){
            // that grid contains the zero cell
            merge_grid(newposx, newposy, size/2, bx, by);
        }
        else{
            int cx = newposx+(size/2-1)*(!flags[i][0]);
            int cy = newposy+(size/2-1)*(!flags[i][1]);
            arr[cx-1+2*flags[i][0]][cy-1+2*flags[i][1]] = arr[cx][cy];
            arr[cx][cy] = temp;
            merge_grid(newposx, newposy, size/2, (ceil(cx/4.0)-1)*4+1, (ceil(cy/4.0)-1)*4+1);
        }
    }
}

void insert_zero_cell(){
    int bx = (ceil(tx/4.0)-1)*4+1;
    int by = (ceil(ty/4.0)-1)*4+1;

    int idx = ((tx-1)%4)/2*2+((ty-1)%4)/2;
    int* cell = center[idx];

    arr[bx+cell[0]][by+cell[1]] = arr[bx+cell[0]][by+cell[1]+(idx%2)*2-1];
    arr[tx][ty]=0;
}

void display_grid(){
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
}

void solve(){
    cin>>n>>tx>>ty;

    n = pow(2, n);

    if(n==2){
        arr[1][1]=arr[1][2]=arr[2][1]=arr[2][2]=1;
        arr[tx][ty]=0;
    }
    else{
        c=1;
        for(int i=1;i<n;i+=4){
            for(int j=1;j<n;j+=4){
                fill_4by4(i, j);
            }
        }
        merge_grid(1, 1, n, tx, ty);
        insert_zero_cell();
    }
    display_grid();
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int t=1;
    cin>>t;

    arr = vector<vector<int>>(pow(2, 8)+1, vector<int>(pow(2, 8)+1));

    while(t--) solve();

    return 0;
}