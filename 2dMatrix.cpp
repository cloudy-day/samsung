
#include <bits/stdc++.h>


using namespace std;

const int mx=1e3;

int n;
char arr[mx][mx];


pair<int,int> fn(int i,int j,vector<vector<pair<int,int>>>&dp){
    
    if(i==n-1 && j==n-1) return {0,1};
    if(i<0 || j<0 || i==n || j == n)return {INT_MIN,INT_MIN};
    if(arr[i][j]=='x') return {INT_MIN,INT_MIN};
    if(dp[i][j].first!=-1)return {dp[i][j].first,dp[i][j].second};
    // cout<<i<<" "<<j<<endl;
    pair<int,int> x=fn(i+1,j,dp);
    pair<int,int> y=fn(i,j+1,dp);
    pair<int,int> z=fn(i+1,j+1,dp);
    int m = max(x.first,max(y.first,z.first));
    int cnt=0;
    if(m==x.first) cnt+=x.second;
    if(m==y.first) cnt+=y.second;
    if(m==z.first) cnt+=z.second;
    dp[i][j].first=m+(arr[i][j]-'0');
    dp[i][j].second=cnt;
    return dp[i][j];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while(t--){

        cin>>n;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
        arr[0][0]=arr[n-1][n-1]='0';
        vector<vector<pair<int,int>>>dp(n+4,vector<pair<int,int>>(n+4,{-1,-1}));
        pair<int,int> x = fn(0,0,dp);
        cout<<x.first<<" "<<x.second<<endl;

    }

    
    return 0;
}