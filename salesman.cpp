#include <iostream>
#include<vector>
#include<utility>
#include<climits>


using namespace std;

const int mx=1e5+9;


// int f(int u, int mask, vector<vector<int>> &mat, vector<vector<int>> &dp){
//     int n = dp.size();
//     if(mask + 1 == (1 << n)) return mat[u][0];
//     int &ret = dp[u][mask];
//     if(~ret) return ret;
//     ret = 1000000000;
//     for(int v = 0; v < n; v++){
//         if(mask & (1 << v)) continue;
//         int cur = mat[u][v] + f(v, mask | (1 << v), mat, dp);
//         ret = min(ret, cur);
//     }
//     return ret;
// }
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     int t;
//     cin >> t;
//     while(t--){
//         int n;
//         cin >> n;
//         vector<vector<int>> mat(n, vector<int>(n));
//         vector<vector<int>> dp(n, vector<int>((1 << n), -1));
//         for(auto &v : mat) for(auto &x : v) cin >> x;
//         cout << f(0, 1, mat, dp) << '\n';

//     }
   
    
    
//  for(auto &v : mat) for(auto &x : v) cin >> x;

   
//     return 0;
// }

int fn(int i,int mask,vector<vector<int>>&mat,vector<vector<int>>&dp){
    int n=dp.size();
    if(mask+1==(1<<n)) return mat[i][0];
    if(dp[i][mask]!=-1)return dp[i][mask];
    int x=INT_MAX;
    for(int j=0;j<n;j++){
        if(mask & (1<<j)) continue;
        int y=fn(j,mask | (1<<j),mat,dp)+mat[i][j];
        x=min(x,y);
    }
    return dp[i][mask]=x;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>mat(n,vector<int>(n));
        for(auto &v:mat)for(auto &x:v)cin>>x;
        vector<vector<int>>dp(n,vector<int>(1<<n,-1));
        cout<<fn(0,1,mat,dp)<<endl;
    }

}




/*


*/