#include<iostream>
#include<queue>

using namespace std; 

int main() {
	int N, M;
	queue<int> q;
	vector<int> ans;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	int cnt=1,tmp;
	while (!q.empty()) {
		tmp = q.front();
		if (cnt % M != 0) {
			q.pop();
			q.push(tmp);
			cnt++;
		}
		else {
			q.pop();
			ans.push_back(tmp);
			cnt = 1;
		}
	}
	cout << "<";
	for (int i = 0; i < ans.size() - 1; i++) {
		cout << ans[i] << ", ";
	}
	cout << ans[ ans.size() - 1] << ">";
}