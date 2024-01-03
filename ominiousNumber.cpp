#include<iostream>
#include<vector>
using namespace std;

int numberOminious(int a,int b,int k,int n,vector<int>& v){
    int ret=0;
    
    for(int i=a;i<=b;i++){
        int tmp=i;
        vector<int>digit(10,0);
        while(tmp){
            digit[tmp%10]++;
            tmp/=10;
        }
        int cnt=0;
        for(int j=0;j<n;j++){
            cnt+=digit[v[j]];
        }
        
        if(cnt<k){
            ret++;
        }
    }
    return ret;

}

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int a,b,k;
    cin>>a>>b>>k;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<numberOminious(a,b,k,n,v)<<endl;

    return 0;
}