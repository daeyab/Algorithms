#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> cMap;
    for(auto c: clothes)
        cMap[c[1]]+=1;
    for(auto it = cMap.begin(); it!=cMap.end(); it++){
        answer *= it->second+1;
    }
    return answer-1;
}
