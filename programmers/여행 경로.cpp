#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> answer;

bool dfs(string city, vector<vector<string>> tickets, vector<bool> &visited, int total){
    answer.push_back(city);
    if(total == tickets.size()) return true;
    
    // 전체 도시동안
    for(int i=0;i<tickets.size(); i++){
        if(tickets[i][0] == city && !visited[i]){
            visited[i] = true;
            bool res = dfs(tickets[i][1], tickets,visited, total+1);
            if(res) return true;
            visited[i] = false;
        }
    }
    answer.pop_back();
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<bool> visited(tickets.size(),false);
    sort(tickets.begin(), tickets.end());
    dfs("ICN",tickets,visited,0);
    return answer;
}
