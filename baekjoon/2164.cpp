#include<iostream>
#include<queue>

using namespace std;

int main() {
	
	ios::sync_with_stdio(false);

	queue<int> q;
	int n;
	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 1; i <=n; i++)
		q.push(i);


	while (1)
	{
		q.pop();
		int k = q.front();
		if (q.size() == 1)
			break;
		q.pop();
		q.push(k);
	}
	cout << q.front() << endl;
	return 0;
}