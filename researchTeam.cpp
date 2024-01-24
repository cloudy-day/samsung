#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<utility>

using namespace std;
 int n,m;

int bfs(int i,int j,vector<vector<int>>&dis,vector<vector<int>>&vis,vector<vector<int>>&arr){
    int cnt=0;
    dis[i][j]=0;
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    int dx[]={1,-1,0,0};
    int dy[]={0,0,1,-1};
    int depth = 0;
    
    while(!q.empty()){
        pair<int,int>tmp=q.front();
        q.pop();
        if(cnt==m){
            while(!q.empty()) q.pop();
            return depth;
        }
        for(int k=0;k<4;k++){
            int x=tmp.first+dx[k];
            int y=tmp.second+dy[k];
            if(x>=1 && x<=n && y>=1 && y<=n && !vis[x][y] && (arr[x][y]==1 || arr[x][y]==2)){
          
                dis[x][y]=dis[tmp.first][tmp.second]+1;
              
                vis[x][y]=1;
                q.push({x,y});
                if(arr[x][y]==2){
                    cnt++;
                    depth = dis[x][y];
                }
            }
        }
    }
    return depth;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tst;
    cin>>tst;

    for(int t=1;t<=tst;t++){

       
        cin>>n>>m;

        vector<pair<int,int>>v;

        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }
        vector<vector<int>>arr(n+4,vector<int>(n+4,0));

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>arr[i][j];

        for(auto[x,y]:v){
            arr[x][y]=2;
        }
        int ans=INT_MAX;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int tmp=0;
                if(arr[i][j]==1){
                    vector<vector<int>>dis(n+4,vector<int>(n+4,0));
                    vector<vector<int>>vis(n+4,vector<int>(n+4,0));
                    int x = bfs(i,j,dis,vis,arr);
                    ans=min(x,ans);
                }
            }
        }
        cout<<"Case :"<<t<<" "<<ans<<endl;

    }


    return 0;
}

/*

Input - 
6
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0
5 2
2 1
3 5
1 0 1 1 1
1 1 1 0 1
0 1 1 0 1
0 1 0 1 1
1 1 1 0 1

Output - 
1
2
2
12
15
4
*/