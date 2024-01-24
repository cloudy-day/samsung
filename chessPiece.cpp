#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<utility>

using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    for(int tst=1;tst<=t;tst++){

        int n,m,r,c,s,k;
        cin>>n>>m>>r>>c>>s>>k;

        vector<vector<int>>vis(n+4,vector<int>(m+4,0));
        vector<vector<int>>dis(n+4,vector<int>(m+4,INT_MAX));

        int dx[]={-2,-1,1,2,2,1,-1,-2};
        int dy[]={1,2,2,1,-1,-2,-2,-1};

        queue<pair<int,int>>q;
        vis[r][c]=1;
        dis[r][c]=0;
        q.push({r,c});

        while(!q.empty()){
            pair<int,int>tmp=q.front();
            // cout<<tmp.first<<" "<<tmp.second<<endl;
            q.pop();
            for(int i=0;i<8;i++){
                int x=tmp.first+dx[i];
                int y=tmp.second+dy[i];
                if(x>=1 && x<=n && y>=1 && y<=m && !vis[x][y]){
                    dis[x][y]=min(dis[x][y],dis[tmp.first][tmp.second]+1);
                    q.push({x,y});
                    vis[x][y]=1;
                }

            }
        }

        cout<<"Case #"<<tst<<endl;
        if(dis[s][k]==INT_MAX)cout<<-1<<endl;
        else cout<<dis[s][k]<<endl;

    }

    return 0;
}