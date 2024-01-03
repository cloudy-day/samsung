
#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

#define MAX 100

int n,m;
int cycle_start, cycle_end;

vector<int>adj[MAX];

bool dfs(int v,vector<int>& color, vector<int>& parent){
    color[v]=1;
    for(int u: adj[v]){
        if(color[u]==0){
            parent[u]=v;
            if(dfs(u,color,parent)) return true;
        }
        else if(color[u]==1){
            cycle_end=v;
            cycle_start=u;
            return true;
        }
    }
    color[v]=2;
    return false;
}


int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n>>m;
    vector<int>parent(n,-1);
    vector<int>color(n,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
    }

    cycle_start = -1;

    for(int i=0;i<n;i++){
        if(color[i]==0 && dfs(i,color,parent)) break;
    }

    if (cycle_start == -1) {
        cout << "Acyclic" << endl;
    } 
    else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int v = cycle_end; v != cycle_start; v = parent[v])
            cycle.push_back(v);
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << "Cycle found: ";
        for (int v : cycle)
            cout << v << " ";
        cout << endl;
    }

    
    return 0;
}