#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<utility>

using namespace std;
int pop_count(int mask){
    int cnt=0;
    while(mask){
        if(mask & 1)cnt++;
        mask/=2;
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(auto &x:v)cin>>x;
    sort(v.begin(),v.end());

    long long ans=v[n-1]*k;

    for(int mask=0;mask<(1<<n);mask++){
        if(pop_count(mask)!=k)continue;

        int lst=n;
        long long cur=0;
        for(int j=n-1;j>=0;j--){
            if(mask  & (1<<j)){
                cur+= v[j ]*(lst-j);
                lst=j;
            }

        }
        ans=min(ans,cur);

    }
    cout<<ans<<endl;

    return 0;
}