#include<iostream>
#include<queue>

using namespace std;


int color[1000];
bool edge[1005][1005];
int e,v;

bool isBiPartite(int src){
    color[src]=1;
    queue<int>q;
    q.push(src);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(edge[node][node]){
            return false;
        }
        for(int i=0;i<v;i++){
            if(edge[node][i]){
                if(color[i]==-1){
                    color[i]=1-color[node];
                    q.push(i);
                }
                else if(color[i]==color[node]){
                    return false;
                }
            }
        }
    }
    return true;
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    for(int i=0;i<1005;i++){
        color[i]=-1;
        for(int j=0;j<1005;j++){
            edge[i][j]=false;
        }
    }

    cin>>v>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        edge[a-1][b-1] = true;
    }

    for(int i=0;i<v;i++){
        if(color[i]==-1){
            if(!isBiPartite(i)){
                cout<<i<<" "<<-1<<endl;
                return 0;
            }
        }
    }

    for(int i=0;i<v;i++){
        if(color[i]==0){
            cout<<i<< " "<<color[i]<<endl;
        }
    }
    

    return 0;
}