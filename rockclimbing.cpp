
#include <iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>


using namespace std;

const int mx=1e5+9;
bool ok=false;
int n,m;

void dfs(int i,int j,int jmp,vector<vector<int>>&mat,vector<vector<int>>&vis){
    if(i<0 || i>=n || j<0 || j>=m) return;
    if(mat[i][j]==3){
        ok=true;
        return;
    }
    if(vis[i][j])return ;
    vis[i][j]=1;
    // cout<<jmp<<" "<<i<<" "<<j<<endl;
    if(j+1<m && (mat[i][j+1]==1 || mat[i][j+1]==3) && !vis[i][j+1]){
        dfs(i,j+1,jmp,mat,vis);
    }
    if(j-1>=0 && (mat[i][j-1]==1 || mat[i][j-1]==3) && !vis[i][j-1]){
        dfs(i,j-1,jmp,mat,vis);
    }
    for(int k=1;k<=jmp;k++){
        if(i+k<n && (mat[i+k][j]==1 || mat[i+k][j]==3) && !vis[i+k][j]){
            dfs(i+k,j,jmp,mat,vis);
        }
    }
    for(int k=1;k<=jmp;k++){
        if(i-k>=0 && (mat[i-k][j]==1 || mat[i-k][j]==3) && !vis[i-k][j]){
            dfs(i-k,j,jmp,mat,vis);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    vector<vector<int>>mat(n,vector<int>(m));
    for(auto &v:mat)for(auto &x:v)cin>>x;
    for(int i=0;i<n;i++){
        ok=false;
        vector<vector<int>>vis(15,vector<int>(15,0));
        dfs(n-1,0,i,mat,vis);
        if(ok){
            cout<<i<<endl;
            break;
        }
    }
    
    
    return 0;
}





/*


*/