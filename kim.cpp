#include<iostream>
#include<climits>
#include<vector>
#include<algorithm>

using namespace std;
int x[20],y[20],n,ans;


void optimalPath(int j,vector<bool>& visited,int nodes,int value){
	if(n == nodes){//If number of nodes equal n then set value of answer
		ans = min(ans,value + abs(x[j]-x[n+1]) + abs(y[j]-y[n+1]));
	}
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			visited[i] = true;
			optimalPath(i,visited,nodes+1,value + abs(x[j]-x[i])+abs(y[j]-y[i]));//Dfs call
			visited[i] = false;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
	int tCases=10;//For testcases
	for(int i=0;i<tCases;i++){
		ans=INT_MAX;//Set ans to max value
		cin >> n;
		cin >> x[n+1] >> y[n+1] >> x[0] >> y[0];//Input destination and source x,y coordinates
		for(int i=1;i<=n;i++){//Input drop off location coordinates
			cin >> x[i] >> y[i];
		}
		vector<bool>visited(n+2,false);
		optimalPath(0,visited,0,0);
		cout << "# " << i+1 << " " << ans << endl;
	}
	return 0;
}