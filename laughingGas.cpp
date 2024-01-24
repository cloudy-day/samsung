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

        int c,r;
        cin>>c>>r;

        vector<vector<int>>arr(r+4,vector<int>(c+4,0));

        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                cin>>arr[i][j];
            }
        }

        int cc,rr;
        cin>>cc>>rr;

        vector<vector<int>>vis(r+4,vector<int>(c+4,0));
        vector<vector<int>>dis(r+4,vector<int>(c+4,0));

        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};

        queue<pair<int,int>>q;
        vis[rr][cc]=1;
        dis[rr][cc]=1;
        q.push({rr,cc});

        while(!q.empty()){
            pair<int,int>tmp=q.front();
            // cout<<tmp.first<<" "<<tmp.second<<endl;
            q.pop();
            for(int i=0;i<4;i++){
                int x=tmp.first+dx[i];
                int y=tmp.second+dy[i];
                if(x>=1 && x<=r && y>=1 && y<=c && !vis[x][y] && arr[x][y]){
                    dis[x][y]=dis[tmp.first][tmp.second]+1;
                    q.push({x,y});
                    vis[x][y]=1;
                }

            }
        }
        int ans=-1;
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
              ans=max(ans,dis[i][j]);
            }
            
        }
        cout<<"Case #"<<tst<<endl;
       
        cout<<ans<<endl;

    }

    return 0;
}