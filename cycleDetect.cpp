
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<climits>

using namespace std;

#define MAX 100

vector<int>adj[MAX];
vector<int>tmp;
int ans=INT_MAX;
int n,m;

void bfs(int x,vector<int>&vis,vector<int>&par,vector<int>&dis){
    vis[x]=1;
    dis[x]=0;
    queue<int>q;
    q.push(x);

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            int v=adj[u][i];
            if(!vis[v]){
                par[v]=u;
                vis[v]=1;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    // for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
    // cout<<endl;
    for(int i=1;i<=n;i++){
        if(i==x) continue;
        for(int j=0;j<adj[i].size();j++){

            if(adj[i][j]==x){
                
                if(ans>dis[i]+1 && vis[i]){
                    // cout<<i<<" "<<ans<<endl;
                    ans=dis[i]+1;
                    tmp.clear();
                    tmp.push_back(x);
                    for(int k=i;k!=x;k=par[k])tmp.push_back(k);
                }
            }
        }
    }


}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    for(int i=1;i<=n;i++){
        vector<int>vis(n+1,0);
        vector<int>par(n+1,-1);
        vector<int>dis(n+1,INT_MAX);
        bfs(i,vis,par,dis);
    }
    // cout<<ans<<endl;
    sort(tmp.begin(),tmp.end());
    for(auto x:tmp)cout<<x<<" ";
    cout<<endl;
  
    return 0;
}



















// #include <iostream>
// #include<vector>
// #include<algorithm>

// using namespace std;

// #define MAX 100

// int n,m;
// int cycle_start, cycle_end;

// vector<int>adj[MAX];

// bool dfs(int v,vector<int>& color, vector<int>& parent){
//     color[v]=1;
//     for(int u: adj[v]){
//         if(color[u]==0){
//             parent[u]=v;
//             if(dfs(u,color,parent)) return true;
//         }
//         else if(color[u]==1){
//             cycle_end=v;
//             cycle_start=u;
//             return true;
//         }
//     }
//     color[v]=2;
//     return false;
// }


// int main()
// {
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     cin>>n>>m;
//     vector<int>parent(n,-1);
//     vector<int>color(n,0);
//     for(int i=0;i<m;i++){
//         int x,y;
//         cin>>x>>y;
//         adj[x].push_back(y);
//     }

//     cycle_start = -1;

//     for(int i=0;i<n;i++){
//         if(color[i]==0 && dfs(i,color,parent)) break;
//     }

//     if (cycle_start == -1) {
//         cout << "Acyclic" << endl;
//     } 
//     else {
//         vector<int> cycle;
//         for (int v = cycle_end; v != cycle_start; v = parent[v])
//             cycle.push_back(v);
//         cycle.push_back(cycle_start);
//         reverse(cycle.begin(), cycle.end());

//         cout << "Cycle found: ";
//         for (int v : cycle)
//             cout << v << " ";
//         cout << endl;
//     }

    
//     return 0;
// }


