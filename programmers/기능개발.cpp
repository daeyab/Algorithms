#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int i=0,j=0,cnt=0;
    int n=progresses.size();
    vector<int> answer;
    while(i<n){
        for(j=i;j<n;j++){
            progresses[j]+=speeds[j];    
        }
        if(progresses[i]>=100){
          cnt=1;
            while(i<n-1&&progresses[i+1]>=100){
                cnt++;
                i++;
            }
        answer.push_back(cnt);
            i++;
        }
    }
        return answer;
}
