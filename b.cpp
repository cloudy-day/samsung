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
        int n;
        cin >> n;
        vector<vector<int>> mat(n, vector<int>(n)), cum(n, vector<int>(n));
        for(auto &v : mat) for(auto &x : v) cin >> x;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int sm = 0;
                if(i - 1 >= 0) sm += cum[i - 1][j];
                if(j - 1 >= 0) sm += cum[i][j - 1];
                if(i - 1 >= 0 && j - 1 >= 0) sm -= cum[i - 1][j - 1];
                sm += mat[i][j];
                cum[i][j] = sm;
            }
        }
        auto query = [&](int a, int b,int c,int d){
            int ret = cum[c][d];
            if(b - 1 >= 0) ret -= cum[c][b - 1];
            if(a - 1 >= 0) ret -= cum[a - 1][d];
            if(a - 1 >= 0 && b - 1 >= 0) ret += cum[a - 1][b - 1];
            return ret;
        };
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; i + k < n && j + k < n; k++){
                    if(query(i, j, i + k, j + k) == 1) ans = max(ans, k + 1);
                }
            }
        }
        cout << ans << '\n';
    }
}