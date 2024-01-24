#include<iostream>
#include<vector>
#include<algorithm>
#include <iomanip> 

using namespace std;

const int mx=100;

vector<int>adj[mx];
double mat[mx][mx];
double ans[mx];
double now=1.0;

void dfs(int n,int k){
	if(k==0){
		ans[n]+=now;
		return ;
	}

	
	for(auto &x:adj[n]){
		now*=mat[n][x];
		dfs(x,k-1);
		now/=mat[n][x];
	}
	return ;


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;

    while(t--){

        int n,m,k;
        cin>>n>>m>>k;

        for(int i=0;i<=n;i++){
            ans[i]=0;
            adj[i].clear();
            for(int j=0;j<=n;j++){
                mat[i][j]=0;
            }
        }

        double res=0;

        for(int i=0;i<m;i++){
            int x,y;
            double w;
            cin>>x>>y>>w;
            adj[x].push_back(y);
            mat[x][y]=w;
        }
        dfs(1,k/10);
        int idx=-1;
        for(int i=1;i<=n;i++){
            if(res<ans[i]){
                idx=i;
                res=ans[i];
            }
        }
        cout<<idx<<" "<<fixed<<setprecision(6)<<res<<"\n";

    }
}