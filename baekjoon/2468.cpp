#include <bits/stdc++.h>

using namespace std;

int n;
int arr[102][102];
bool visited[102][102];
int maxVal=-1;
int ans[102];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};


void decreaseHeight(){
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++)
            arr[a][b] = arr[a][b]-1;
    }
}

void dfs(int y, int x){
    visited[y][x]=true;
    for(int i=0;i<4;i++){
        int newY = y+ dy[i];
        int newX = x + dx[i];
        if( newY<n && newY>-1 && newX<n && newX>-1 && arr[newY][newX]>0 && !visited[newY][newX]){
            dfs(newY, newX);
        }
    }
}

int findGroup(){
    int res=0;
    for(int y=0;y<n;y++){
        for(int x=0;x<n;x++){
            if(arr[y][x]>0 && !visited[y][x]){
                res=res+1;
                dfs(y,x);
            }
        }
    }
    return res;
}

int main(){
    int maxAns =-1;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &arr[i][j]);
            maxVal = max(maxVal, arr[i][j]);
        }
    }
    for(int i=0;i<=maxVal;i++){
        memset(visited, false, sizeof(visited));
        ans[i] = findGroup();
        decreaseHeight();
        maxAns = max(maxAns, ans[i]);
    }
    printf("%d\n", maxAns);
}
