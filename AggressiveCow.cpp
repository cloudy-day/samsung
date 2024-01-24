/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
5 3
1 3 5 8 10

Output: 4
1 5 10
*/

#include<bits/stdc++.h>
using namespace std;

bool canWePlace(vector<int>&v,int dist,int c){
    int n = v.size();
    int last = v[0];
    int cntCows = 1;
    for(int i=1;i<n;i++){
        if(v[i]-last>=dist){
            cntCows++;
            last = v[i];
        }
        if(cntCows>=c){
            return true;
        }
    }
    return false;
}

int bb(vector<int>&v,int c){
    int n = v.size();
    int low = 1;
    int high = v[n-1]-v[0];
    
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(v,mid,c)){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high;
}

// int aggressiveCows(vector<int>&v,int c){
//     int n = v.size();
//     int limit = v[n-1]-v[0];
//     for(int i=1;i<=limit;i++){
//         if(!canWePlace(v,i,c)){
//             return i-1;
//         }
//     }
//     return limit;
// }

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,c;
    cin>>n>>c;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans = bb(v,c);
    cout << "The maximum possible minimum distance is: " << ans << "\n";
    vector<int>ansV;
    ansV.push_back(v[0]);
    int last = v[0];
    for(int i=1;i<n;i++){
        if(v[i]-last>=ans){
            ansV.push_back(v[i]);
            last = v[i];
        }
    }

    cout << "The positions are: ";
    for(int i=0;i<ansV.size();i++){
        cout << ansV[i] << " ";
    }   
    cout << "\n";
    return 0;
}