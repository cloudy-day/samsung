#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int ans;

void fn(vector<int>&v,int x,int y,vector<int>&vis){

    if(x==y){
        ans=max(ans,x);
    }
    for(int i=0;i<v.size();i++){
        if(!vis[i]){
            vis[i]=1;
            fn(v,x+v[i],y,vis);
            fn(v,x,y+v[i],vis);
            vis[i]=0;
        }
    }
}

int main(){


    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &x:v)cin>>x;

    ans=-1;
    vector<int>vis(n+1,0);
    fn(v,0,0,vis);
    cout<<ans<<endl;

    return 0;
}