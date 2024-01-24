#include<iostream>
#include<vector>
#include<climits>


using namespace std;

int burst(vector<int>&v,vector<vector<int>>& dp,int i,int j){
    if(i > j || j < i){
        return 0;
    }
    if(i==j){
        return v[i-1]*v[i+1];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int m = INT_MIN,tmp;

    for(int k=i;k<=j;k++){

        if(i==1 && j==v.size()-2){
            tmp = v[k]+burst(v,dp,i,k-1)+burst(v,dp,k+1,j);
        }
        else{
            tmp = v[i-1]*v[j+1]+burst(v,dp,i,k-1)+burst(v,dp,k+1,j);
        }
       
        
        // if(i==1 && j==v.size()-2){
        //     tmp+=v[k]-1;
        // }
        m=max(tmp,m);
    }
    
    return dp[i][j]=m;
}

 

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);


    int n;
    cin>>n;
    vector<int>v(n+2,0);
    v[0]=v[n+1]=1;
    for(int i=1;i<=n;i++)cin>>v[i];
    vector<vector<int>>dp(n+4,vector<int>(n+4,-1));

    cout<<burst(v,dp,1,n)<<endl;


    return 0;
}