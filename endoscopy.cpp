#include<iostream>
#include<queue>
#include<utility>
using  namespace std;


struct Node{
    bool left,right,up,down;
};
struct Point{
    int x,y;
};

int n,m,sx,sy,len;
int arr[1005][1005],vis[1005][1005],dis[1005][1005];
int ans;
Node pipes[1005][1005];


bool isVal(int i,int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

void bfs(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            vis[i][j]=0;
            dis[i][j]=0;
        }
    }
    queue<pair<int,int>>qq;
    // int front=0,rear=0;
    dis[sx][sy]=1;
    vis[sx][sy]=1;
    if(arr[sx][sy]==0){
        ans=0;
        return;
    }

    // queue[rear].x=sx;
    // queue[rear].y=sy;
    // rear=(rear+1)%1000005;
    qq.push({sx,sy});

    while(!qq.empty()){
        pair<int,int> t=qq.front();
        qq.pop();
        int p=t.first;
        int q=t.second;
        if(1+dis[p][q] <= len){

            if(isVal(p-1,q) && !vis[p-1][q] && pipes[p-1][q].down && pipes[p][q].up){
                vis[p-1][q]=1;
                dis[p-1][q]=1+dis[p][q];
                ans++;

                qq.push({p-1,q});
            }

            if(isVal(p+1,q) && !vis[p+1][q] && pipes[p+1][q].up && pipes[p][q].down){
                vis[p+1][q]=1;
                dis[p+1][q]=1+dis[p][q];
                ans++;

                qq.push({p+1,q});
            }
            if(isVal(p,q-1) && !vis[p][q-1] && pipes[p][q-1].right && pipes[p][q].left){
                vis[p][q-1]=1;
                dis[p][q-1]=1+dis[p][q];
                ans++;

               qq.push({p,q-1});
            }
            if(isVal(p,q+1) && !vis[p][q+1] && pipes[p][q+1].left && pipes[p][q].right){
                vis[p][q+1]=1;
                dis[p][q+1]=1+dis[p][q];
                ans++;

               qq.push({p,q+1});
            }

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
        ans=1;
        cin>>n>>m>>sx>>sy>>len;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]==1){
                    pipes[i][j].left=true;
                    pipes[i][j].right=true;
                    pipes[i][j].up=true;
                    pipes[i][j].down=true;
                }
                else if(arr[i][j]==2){
                    pipes[i][j].left=false;
                    pipes[i][j].right=false;
                    pipes[i][j].up=true;
                    pipes[i][j].down=true;
                }
                else if(arr[i][j]==3){
                    pipes[i][j].left=true;
                    pipes[i][j].right=true;
                    pipes[i][j].up=false;
                    pipes[i][j].down=false;
                }
                else if(arr[i][j]==4){
                    pipes[i][j].left=false;
                    pipes[i][j].right=true;
                    pipes[i][j].up=true;
                    pipes[i][j].down=false;
                }
                else if(arr[i][j]==5){
                    pipes[i][j].left=false;
                    pipes[i][j].right=true;
                    pipes[i][j].up=false;
                    pipes[i][j].down=true;
                }
                else if(arr[i][j]==6){
                    pipes[i][j].left=true;
                    pipes[i][j].right=false;
                    pipes[i][j].up=false;
                    pipes[i][j].down=true;
                }
                else if(arr[i][j]==7){
                    pipes[i][j].left=true;
                    pipes[i][j].right=false;
                    pipes[i][j].up=true;
                    pipes[i][j].down=false;
                }
                else{
                    pipes[i][j].left=false;
                    pipes[i][j].right=false;
                    pipes[i][j].up=false;
                    pipes[i][j].down=false;
                }
            }
        }
        bfs();
        cout<<ans<<endl;

    }

    return 0;

}













// struct Node{
//     bool left,right,up,down;
// };
// struct Point{
//     int x,y;
// };

// int n,m,sx,sy,len;
// int arr[1005][1005],vis[1005][1005],dis[1005][1005];
// int ans;
// Node pipes[1005][1005];
// Point queue[1000005];

// bool isVal(int i,int j){
//     return (i>=0 && i<n && j>=0 && j<m);
// }

// void bfs(){
//     for(int i=0;i<n;i++){
//         for(int j=0;j<m;j++){
//             vis[i][j]=0;
//             dis[i][j]=0;
//         }
//     }
//     int front=0,rear=0;
//     dis[sx][sy]=1;
//     vis[sx][sy]=1;
//     if(arr[sx][sy]==0){
//         ans=0;
//         return;
//     }

//     queue[rear].x=sx;
//     queue[rear].y=sy;
//     rear=(rear+1)%1000005;

//     while(front != rear){
//         int p = queue[front].x;
//         int q = queue[front].y;
//         front=(front+1)%1000005;
//         if(1+dis[p][q] <= len){

//             if(isVal(p-1,q) && !vis[p-1][q] && pipes[p-1][q].down && pipes[p][q].up){
//                 vis[p-1][q]=1;
//                 dis[p-1][q]=1+dis[p][q];
//                 ans++;

//                 queue[rear].x = p-1;
//                 queue[rear].y = q;
//                 rear=(rear+1)%1000005;
//             }

//             if(isVal(p+1,q) && !vis[p+1][q] && pipes[p+1][q].up && pipes[p][q].down){
//                 vis[p+1][q]=1;
//                 dis[p+1][q]=1+dis[p][q];
//                 ans++;

//                 queue[rear].x = p+1;
//                 queue[rear].y = q;
//                 rear=(rear+1)%1000005;
//             }
//             if(isVal(p,q-1) && !vis[p][q-1] && pipes[p][q-1].right && pipes[p][q].left){
//                 vis[p][q-1]=1;
//                 dis[p][q-1]=1+dis[p][q];
//                 ans++;

//                 queue[rear].x = p;
//                 queue[rear].y = q-1;
//                 rear=(rear+1)%1000005;
//             }
//             if(isVal(p,q+1) && !vis[p][q+1] && pipes[p][q+1].left && pipes[p][q].right){
//                 vis[p][q+1]=1;
//                 dis[p][q+1]=1+dis[p][q];
//                 ans++;

//                 queue[rear].x = p;
//                 queue[rear].y = q+1;
//                 rear=(rear+1)%1000005;
//             }

//         }
//     }


// }


// int main(){

//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);

//     int t;
//     cin>>t;
//     while(t--){
//         ans=1;
//         cin>>n>>m>>sx>>sy>>len;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cin>>arr[i][j];
//                 if(arr[i][j]==1){
//                     pipes[i][j].left=true;
//                     pipes[i][j].right=true;
//                     pipes[i][j].up=true;
//                     pipes[i][j].down=true;
//                 }
//                 else if(arr[i][j]==2){
//                     pipes[i][j].left=false;
//                     pipes[i][j].right=false;
//                     pipes[i][j].up=true;
//                     pipes[i][j].down=true;
//                 }
//                 else if(arr[i][j]==3){
//                     pipes[i][j].left=true;
//                     pipes[i][j].right=true;
//                     pipes[i][j].up=false;
//                     pipes[i][j].down=false;
//                 }
//                 else if(arr[i][j]==4){
//                     pipes[i][j].left=false;
//                     pipes[i][j].right=true;
//                     pipes[i][j].up=true;
//                     pipes[i][j].down=false;
//                 }
//                 else if(arr[i][j]==5){
//                     pipes[i][j].left=false;
//                     pipes[i][j].right=true;
//                     pipes[i][j].up=false;
//                     pipes[i][j].down=true;
//                 }
//                 else if(arr[i][j]==6){
//                     pipes[i][j].left=true;
//                     pipes[i][j].right=false;
//                     pipes[i][j].up=false;
//                     pipes[i][j].down=true;
//                 }
//                 else if(arr[i][j]==7){
//                     pipes[i][j].left=true;
//                     pipes[i][j].right=false;
//                     pipes[i][j].up=true;
//                     pipes[i][j].down=false;
//                 }
//                 else{
//                     pipes[i][j].left=false;
//                     pipes[i][j].right=false;
//                     pipes[i][j].up=false;
//                     pipes[i][j].down=false;
//                 }
//             }
//         }
//         bfs();
//         cout<<ans<<endl;

//     }

//     return 0;

// }