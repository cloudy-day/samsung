#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int k;
    cin>>k;
    string s;
    cin>>s;

    int sum=0;
    int level=-1;

    for(int i=0;i<s.size();i++){
        if(s[i]=='(') level++;
        else if(s[i]==')') level--;
        else if(level==k){
            int x=s[i]-'0';
            i++;
            while(s[i]>=48 && s[i]<=57){
                int d=s[i]-'0';
                x=x*10+d;
                i++;
            }
            i--;
            sum+=x;
        }
    }

    cout<<sum<<endl;

    return 0;
}