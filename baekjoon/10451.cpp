#include<iostream>
#include<stack>
//백준 10451
using namespace std;

int line[1001];

int testcase,N;
int cnt=0;
int val, head;
int main() {
	cin >> testcase;
	while (testcase--) {
		bool visited[1001] = { 0, };
		cnt = 0;
		stack<int> stk;
		cin >> N;
		for (int i = 1; i <= N; i++) {
			cin >> line[i];
		} // 입력
		for (int i = 1; i <= N; i++) {
			if (!visited[i]) { //
				visited[i] = true;
				cnt++;
				head = i;
				val = line[head];
				while (val != i) {
					visited[val] = true;
					head = val;
					val = line[head];
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}