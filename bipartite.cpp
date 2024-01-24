#include<iostream>
#include<queue>

using namespace std;

const int mx=100;

vector<int>adj[mx];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int node,edge;
    cin>>node>>edge;

    for(int i=0;i<edge;i++){
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<int>color(mx,-1);

    queue<int>q;
    q.push(0);
    color[0]=0;

    bool isBipartite=true;

    while(!q.empty() && isBipartite){

        int t = q.front();
        q.pop();
        for(int i=0;i<adj[t].size();i++){
            int nt=adj[t][i];
            if(color[nt]==-1){
                color[nt]=1-color[t];
                q.push(nt);
            }
            else if(color[nt]==color[t]){
                isBipartite=false;
                break;
            }
        }
    }

    if(!isBipartite){
        cout<<-1<<endl;
    }
    else{
        for(int i=0;i<node;i++){
            if(color[i])cout<<i<<" ";
        }
        cout<<endl;
    }

    

    return 0;
}