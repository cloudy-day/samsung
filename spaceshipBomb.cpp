#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

void maxCoins(int i,int j,int tmp,int &ans,int bomb,int effect,vector<vector<int>>&mat){

    if(i==-1){
        ans=max(ans,tmp);
        return ;
    }
    for(int k=-1;k<=1;k++){
        if(j+k<0 || j+k>4)continue;
        if(mat[i][j+k] == 1 || mat[i][j+k]==0){
            if(bomb==0){
                maxCoins(i-1,j+k,tmp+mat[i][j+k],ans,bomb,effect-1,mat);
            }
            else{
                maxCoins(i-1,j+k,tmp+mat[i][j+k],ans,bomb,effect,mat);
            }
        }
        else{
            if(bomb==0){
                if(effect>0)maxCoins(i-1,j+k,tmp,ans,bomb,effect-1,mat);
            }
            else{
                maxCoins(i-1,j+k,tmp,ans,0,5,mat);
            }
        }
    }
    return ;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    int ans;
    for(int tst=1;tst<=t;tst++){
        int n;
        cin>>n;
        vector<vector<int>>mat(n,vector<int>(5,0));

        for(int i=0;i<n;i++)for(int j=0;j<5;j++)cin>>mat[i][j];

        ans=0;

        maxCoins(n-1,2,0,ans,1,0,mat);
        cout<<"#"<<tst<<" "<<ans<<endl;

       

        


    }
    

    return 0;
}