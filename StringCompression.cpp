#include<iostream>
using namespace std;

void mergeAlpha(string s){
    int l = s.size();
    cout<<l<<endl;
    int hash[26] = {0};
    for(int i = 0; i < l; i++){
        char letter = s[i];
        i++;
        int tmp = 0;
        while(i < l && s[i] >= '0' && s[i] <= '9'){
            tmp = (tmp * 10) + (s[i] - '0');
            i++;
        }
        i--;
        hash[letter - 'a'] +=  tmp;
    }
    for(int i = 0; i < 26; i++){
        if(hash[i] != 0){
            cout<<(char)(i + 'a')<<" "<<hash[i]<<" ";
        }
    }
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    string s;
    cin>>s;
    mergeAlpha(s);
    return 0;

}