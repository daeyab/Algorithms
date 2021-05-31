
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> v(n,1);
    for(auto l : lost) v[l-1]--;
    for(auto r : reserve) v[r-1]++;
    if(v[0]==0 && v[1]>1){
        v[0]++;
        v[1]--;
    }
    for(int i=1; i<n-1;i++){
        if(v[i]==0){
            if(v[i-1]==2){
                v[i-1]--;
                v[i]++;
            }
            else if(v[i+1]==2){
                v[i]++;
                v[i+1]--;
            }
        }
    }
    if(v[n-1]==0 && v[n-2]==1){
        v[n-1]++;
        v[n-2]--;
    }

    for(int i=0;i<n;i++){
        if(v[i]>0)
            answer++;
    }
    return answer;
}
