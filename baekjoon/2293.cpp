#include<iostream>
#include<algorithm>

using namespace std;

int n, k;
int cost[10001];
int coin[101];


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];
	cost[0] = 1;

	for (int i = 0; i < n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			cost[j] += cost[j - coin[i]];
		}
	}
	cout << cost[k];
}