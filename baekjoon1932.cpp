#include<iostream>
#include<algorithm>

using namespace std;

int n;
int triangle[502][502] = { 0, };
int cache[502][502]={ 0, };

void dp() {
	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= y; x++) {
			if (x == 1)
				cache[y][x] = cache[y - 1][x] + cache[y][x];
			else if (y == x)
				cache[y][x] = cache[y - 1][x - 1] + cache[y][x];
			else
			cache[y][x] += max(cache[y - 1][x], cache[y - 1][x - 1]);
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> triangle[i][j];
			cache[i][j] = triangle[i][j];
		}
	}
	dp();

	if (n == 1)
		cout << cache[1][1] << endl;
	else {
		sort(cache[n], cache[n] + n+1, greater<int>());
		cout << cache[n][0] << endl;
	}
}