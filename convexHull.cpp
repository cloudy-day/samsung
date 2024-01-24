
#include <iostream>
#include<vector>
#include<utility>
#include<climits>
#include<algorithm>
 


using namespace std;

const int mx=1e5+9;

int orientation(pair<int,int> a,pair<int,int> b,pair<int,int> c){
    double v = a.first*(b.second-c.second)+b.first*(c.second-a.second)+c.first*(a.second-b.second);
    if(v<0)return -1;
    else if(v>0) return 1;
    else return 0;
}

void convex_hull(vector<pair<int,int>>&v){

    pair<int,int> a = v[0];
    pair<int,int> b = v.back();
    vector<pair<int,int>> up,down;

    up.push_back(a);
    down.push_back(a);

    for(int i=1;i<v.size();i++){

        if(i==v.size()-1 || orientation(a,v[i],b)==-1){
            while(up.size()>=2 && orientation(up[up.size()-2],up[up.size()-1],v[i])!=-1){
                up.pop_back();
            }
            up.push_back(v[i]);
        }
        if(i==v.size()-1 || orientation(a,v[i],b)==1){
            while(down.size()>=2 && orientation(down[down.size()-2],down[down.size()-1],v[i])!=1){
                down.pop_back();
            }
            down.push_back(v[i]);
        }
    }
    v.clear();
    for (int i = 0; i < up.size(); i++)
        v.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        v.push_back(down[i]);
    for(auto x:v)cout<<x.first<<" "<<x.second<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
    freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    vector<pair<int,int>>v;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end());

    convex_hull(v);
    
    
    return 0;
}





/*
input 
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3

output
0 3
4 4
3 1
0 0
*/