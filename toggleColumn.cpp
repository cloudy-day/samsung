# include<iostream>
#include<utility>
#include<map>

using namespace std;

#define MAX 100009

int arr[25][MAX];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;

    map<string,pair<int,int>> mp;
    int cnt;
    string tmp;
    for(int i=0;i<n;i++){
        cnt=0;
        tmp="";
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
            tmp+=to_string(arr[i][j]);
            if(arr[i][j]==0) cnt++;
        }
        mp[tmp].first+=1;
        mp[tmp].second=cnt;
    }
    int ans=-1;
    for(auto [a,b]:mp){
        if(b.second == k){
            ans = max(ans,b.first);
        }
        else if(b.second < k && (k-b.second)%2==0){
            ans= max(ans,b.first);
        }
    }

    cout<<ans<<endl;




    return 0;
}