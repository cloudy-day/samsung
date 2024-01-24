#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+9;
int cnt[mx];

long long fn(int i,int m,vector<long long>&dp){
    if(i>m)return 0;
    if(dp[i]!=-1) return dp[i];
    long long x = i*cnt[i] + fn(i+2,m,dp);
    long long y = fn(i+1,m,dp) ;
    return dp[i]=max(x,y);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n,m=0;
    cin>>n;
    

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
        m=max(m,x);
    }
    
    vector<long long>dp(mx,-1);

    cout<<fn(1,m,dp)<<endl;
    
   
    return 0;
}

/*
5 5
1 2 1
2 5 2
1 3 5
3 4 1
2 4 1
*/