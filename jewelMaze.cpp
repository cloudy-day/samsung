
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

#define MAX 100

int n,m;
int sx,sy,tx,ty;
int arr[1005][1005],vis[1005][1005],path[1005][1005],ans[1005][1005];
int maxjewel;
int dirX[]={1,0,-1,0};
int dirY[]={0,1,0,-1};

void savePath(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=path[i][j];
        }
    }
}

void dfs(int i,int j,int total){
    path[i][j]=3;
    vis[i][j]=1;
    if(i==0 && j==0 && arr[i][j]==2){
        total++;
    }
    if(i==n-1 && j==n-1){
        if(total > maxjewel){
            maxjewel=total;
            savePath();
        }
        vis[i][j]=0;
        return ;
    }

    if(j+1<=n-1){
        if(!vis[i][j+1] && arr[i][j+1]!=1){
            if(arr[i][j+1]==2) dfs(i,j+1,total+1);
            else dfs(i,j+1,total);
            path[i][j+1]=arr[i][j+1];
        }
    }
    if(j-1>=0){
        if(!vis[i][j-1] && arr[i][j-1]!=1){
            if(arr[i][j-1]==2) dfs(i,j-1,total+1);
            else dfs(i,j-1,total);
            path[i][j-1]=arr[i][j-1];
        }
    }
    if(i+1<=n-1){
        if(!vis[i+1][j] && arr[i+1][j]!=1){
            if(arr[i+1][j]==2) dfs(i+1,j,total+1);
            else dfs(i+1,j,total);
            path[i+1][j]=arr[i+1][j];
        }
    }
    if(i-1>=0){
        if(!vis[i-1][j] && arr[i-1][j]!=1){
            if(arr[i-1][j]==2) dfs(i-1,j,total+1);
            else dfs(i-1,j,total);
            path[i-1][j]=arr[i-1][j];
        }
    }
    vis[i][j]=0;
}




int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    for(int tst=1;tst<=t;tst++){
        cin>>n;
        maxjewel=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
                vis[i][j]=0;
                path[i][j]=arr[i][j];
            }
        }
        dfs(0,0,0);
        cout<<"Case "<<tst<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<maxjewel<<endl;
    }
    
    return 0;
}