#include<iostream>
#include<climits>
using namespace std;


int ans,n;

int w[35][5];
int mask[35];

int abs(int a){
    return (a>=0) ? a : -1*a;
}

int dist(int sx,int sy,int ex,int ey){
    return abs(sx-ex)+abs(sy-ey);
}

int min(int a,int b){
    return (a>=b) ? b : a;
}

void wormHole(int sx,int sy,int ex,int ey,int cost){
    ans=min(ans,dist(sx,sy,ex,ey)+cost);
    int tmp;
    for(int i=0;i<n;i++){
        if(!mask[i]){
            mask[i]=1;
            tmp = dist(sx,sy,w[i][0],w[i][1]) + w[i][4] + cost;
            wormHole(w[i][2],w[i][3],ex,ey,tmp);

            tmp = dist(sx,sy,w[i][2],w[i][3]) + w[i][4] + cost;
            wormHole(w[i][0],w[i][1],ex,ey,tmp);
            mask[i]=0;
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--){
        ans=INT_MAX;
        int sx,sy,ex,ey;
        cin>>sx>>sy>>ex>>ey>>n;

        for(int i=0;i<n;i++){
            mask[i]=0;
            for(int j=0;j<5;j++){
                cin>>w[i][j];
            }
        }
        wormHole(sx,sy,ex,ey,0);
        cout<<ans<<endl;

    }


    return 0;
}

/*
case-1:
1
0 0
100 100
3
1 2 120 120 2
4 5 120 100 3
6 8 150 180 4
ans: 32

case-2:
1
0 0
100 100
3
1 2 120 120 2
4 5 120 100  3
6 8 102 102 4
ans: 22


*/