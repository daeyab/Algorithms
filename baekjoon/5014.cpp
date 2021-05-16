#include<stdio.h>
#include<queue>
#include<iostream>
#include<queue>

using namespace std;

int building[1000002];
bool visited[1000002];
queue<pair<int,int> > q;

int main(){
    int total, current, destiniation, up, down;
    scanf("%d %d %d %d %d",&total, &current, &destiniation, &up, &down);
    q.push(make_pair(current,0));

    while(!q.empty()){
        int nowFloor=q.front().first;
        int nowMovement = q.front().second;
        // printf("%d  %d \n", nowFloor, nowMovement);
        if(nowFloor == destiniation){
            printf("%d\n", nowMovement);
            return 0;
        }
        // visited[nowFloor] = true;
        q.pop();
        int nextUp = nowFloor+up;
        if (nextUp <=total && !visited[nextUp]){
            q.push(make_pair(nextUp, nowMovement+1));
            visited[nextUp] = true;
        }
        int nextDown = nowFloor-down;
        if (nextDown > 0 && !visited[nextDown]){
            q.push(make_pair(nextDown, nowMovement+1));
            visited[nextDown] = true;
        }
    }
    printf("use the stairs\n");
    return 0;
}

