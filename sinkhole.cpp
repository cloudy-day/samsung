#include<iostream>
#include<vector>
using namespace std;
int query(int a,int b,int c,int d,vector<vector<int>>&cum){
    return cum[c][d]-cum[a-1][b]-cum[a][b-1]+cum[a-1][b-1];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>>mat(n+4,vector<int>(m+4,0)),cum(n+4,vector<int>(m+4,0));
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        mat[x][y]=1;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cum[i][j]=cum[i-1][j]+cum[i][j-1]-cum[i-1][j-1]+mat[i][j];
        }
    }
    int ans=0;
    int tmp=-1;
    int xb=-1,yb=-1,xt=-1,yt=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;i+k<=n && j+k<=n;k++){
                int x=query(i,j,i+k,j+k,cum);
                cout<<x<<endl;
                if(x==1){
                    if(k+1>ans) {
                        ans=k+1;
                        // tmp=x;
                        xb=i+k,yb=j+k,xt=i,yt=j;
                    }
                    // else if(k+1==ans && x<tmp){
                    //     tmp=x;
                    //     xb=i+k,yb=j+k,xt=i,yt=j;
                    // }
                }
            }
        }
    }

    cout<<xb<<" "<<yb<<" "<<xt<<" "<<yt<<endl;

    return 0;
}