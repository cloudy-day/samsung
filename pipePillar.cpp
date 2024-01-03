#include<iostream>
#include<vector>
using namespace std;


void fn(int arr[],vector<int> &vis,int p1,int p2,int n,int &ans){
    if(p1 == p2){
        if(p1 > ans){
            ans = p1;
        }
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            vis[i]=1;
            fn(arr,vis,p1+arr[i],p2,n,ans);
            fn(arr,vis,p1,p2+arr[i],n,ans);
            vis[i]=0;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>vis(n);
    int ans = -1;
    fn(arr,vis,0,0,n,ans);
    cout<<ans<<endl;


    return 0;
}