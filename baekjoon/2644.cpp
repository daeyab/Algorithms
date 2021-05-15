#include <stdio.h>
#include <queue>
#include <vector>
#include <iostream>


using namespace std;

int main(){
    vector<int> map[102];
    bool visited[102];
    queue<pair<int, int> > q;
    int n, sNode, eNode, m, x, y;
 
    scanf("%d %d %d %d",&n ,&sNode, &eNode, &m);
    for(int i=0;i<m;i++){
        scanf("%d %d", &x, &y);
        map[x].push_back(y);
        map[y].push_back(x);
    }
    q.push(make_pair(sNode, 0));

    while(1){
        int node = q.front().first;
        int rel = q.front().second;
        q.pop();

        visited[node] = true;
        for(int i=0;i<map[node].size();i++){
            if (node == eNode) {
                printf("%d\n", rel);
                return 0;
            }
            if(!visited[map[node][i]]) {
                q.push(make_pair(map[node][i],rel+1));
            }
        }
            if(q.empty()){
                printf("-1\n");
                return 0;
            }
    }
    return 0;
}