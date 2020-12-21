#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std; 


int main() {
	int tc; cin >> tc;
		
		/*우선순위 큐를 통해
		가장 작은 것 두개씩 합치면 돼*/

	while (tc--) {
		int len; cin >> len;
		vector<int> stringSize(101);
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < len; i++) {
			cin >> stringSize[i];
			pq.push(stringSize[i]);
		}
		int result = 0;
		while (pq.size() > 1) {
			int min1 = pq.top(); pq.pop();
			int min2 = pq.top(); pq.pop();
			pq.push(min1 + min2);
			result += min1 + min2;
		}
		cout << result << endl;
	

	}

}