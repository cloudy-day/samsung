#include <iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>


using namespace std;

const int mx=1e5+9;
const int MAX=1e8+9;

int fn(int i,int j,int n,vector<pair<int,int>>&vp,vector<vector<int>>&dp){
    if(j>vp[0].second+vp[1].second+vp[2].second) return MAX;
    if(i==n){
        if(j==vp[0].second+vp[1].second+vp[2].second)return 0;
        else return MAX;
    }
    if(dp[i][j]!=-1) return dp[i][j];
    int x=0,y=0,cost;
    if(j<vp[0].second){
        cost=abs((i + 1)-vp[0].first)+1;
    }
    else if(j<vp[0].second+vp[1].second){
        cost=abs((i + 1)-vp[1].first)+1;
    }
    else{
        cost=abs((i + 1)-vp[2].first)+1;
    }
   
    x=fn(i+1,j+1,n,vp,dp)+cost;
    y=fn(i+1,j,n,vp,dp);
    return dp[i][j]=min(x,y);

}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<int>gates(3);
    for(int i=0;i<3;i++)cin>>gates[i];

    vector<int>v(3);
    for(int i=0;i<3;i++)cin>>v[i];

    vector<pair<int,int>>vp;
    for(int i=0;i<3;i++){
        vp.push_back({gates[i],v[i]});
    }
    sort(vp.begin(),vp.end());
   
    
    vector<vector<int>>dp(n+10,vector<int>(mx,-1));

    cout<<fn(0,0,n,vp,dp)<<endl;
    
    return 0;
}





/*

5
10
4 5
6 2
10 2
10
8 5
9 1
10 2
24
15 3
20 4
23 7
39
17 8
30 5
31 9
60
57 12
31 19
38 16
 
outputs
18
25
57
86
339
*/