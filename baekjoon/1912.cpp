#include<iostream>
#include<algorithm>

using namespace std;
int arr[100001];
int dp[100001];

int D(int n) {
	if (n == 0)
		return dp[n] = arr[n];
	else 
		return dp[n] = max(D(n - 1) + arr[n], arr[n]);
	
}
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	D(n-1);
	sort(dp, dp + n);

/*	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
		*/

	cout << dp[n-1] << endl;
}