
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

#define MAX 100

int n,m;
int sx,sy,tx,ty;
int mat[1005][1005],vis[1005][1005],dis[1005][1005];

int dirX[]={1,0,-1,0};
int dirY[]={0,1,0,-1};


bool isValid(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}

void calculateFrogJump(){

    queue<pair<int,int>>q;
    q.push({sx,sy});

    vis[sx][sy]=1;
    dis[sx][sy]=0;

    while(!q.empty()){

        pair<int,int> t = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int newX=t.first+dirX[i];
            int newY=t.second+dirY[i];
            if(isValid(newX,newY) && mat[newX][newY] && !vis[newX][newY]){
                if(i == 1 || i == 3){
					dis[newX][newY] = dis[t.first][t.second];
 				}
				else if(i == 0 || i == 2){
					dis[newX][newY] = 1 + dis[t.first][t.second];
				}
 
				vis[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }


}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
            vis[i][j]=0;
            dis[i][j]=0;
        }
    }

    cin>>sx>>sy>>tx>>ty;
    calculateFrogJump();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<dis[tx][ty]<<endl;
    return 0;
}