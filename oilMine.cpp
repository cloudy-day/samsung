
// #include<iostream>
// #include<vector>
// #include<climits>
// #include<algorithm>
// using namespace std;
// const int inf=1e9;

// int bt(int i,int n,vector<int>&v,vector<int>&assignment){

//     if(i==v.size()){
//         int x=0;
//         vector<int>sm(n);
//         for(int j=0;j<v.size();j++)sm[assignment[j]]+=v[j];
//         sort(sm.begin(),sm.end());
//         x=sm.back()-sm[0];
//         return x;
//     }
//     int ret=inf;
//     for(int j=0;j<n;j++){
//         assignment[i]=j;
//         ret=min(ret,bt(i+1,n,v,assignment));
//     }
//     return ret;
// }

// int main(){


//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int n,m;
//     cin>>n>>m;

//     vector<int>vec(m);
//     for(int i=0;i<m;i++)cin>>vec[i];

//     vector<int>assignment(n);
//     cout<<bt(0,n,vec,assignment)<<endl;

//     return 0;
// }








#include<bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int bct(int i, int n, vector<int> &v, vector<int> &assignment){
    if(i == v.size()){
        //base case
        int ret = 0;
        // calculate ret
        vector<int> sm(n);
        for(int i = 0; i < v.size(); i++) sm[assignment[i]] += v[i];
        sort(sm.begin(), sm.end());
        ret = sm.back() - sm[0];
        return ret;
    }
    int ret = inf;
    for(int j = 0; j < n; j++){
        assignment[i] = j;
        ret = min(ret, bct(i + 1, n, v, assignment));
    }
    return ret;
}
int32_t main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> v(m);
        for(auto &x : v) cin >> x;
        vector<int> assignment(m);
        cout << bct(0, n, v, assignment) << '\n';
    }
} 