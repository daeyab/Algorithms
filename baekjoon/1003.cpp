#include<iostream>

using namespace std;

int dp[41];
int fibonacci(int n);

int main() {
	int n;
	int times;
	cin >> times;

	for (int i = 0; i < times; i++) {
		cin >> n;
		if (n == 0)
			cout << "1" << " " << "0" << endl;
		else if (n == 1)
			cout << "0" << " " << "1" << endl;
		else {
			fibonacci(n);
			cout << dp[n - 1] << " " << dp[n] << endl;
		}
	}
		return 0;
}

int fibonacci(int n) {
	if (n <= 0) {
		dp[0]=0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	if (dp[n] != 0) {
		return dp[n];
	}
	else {
		return dp[n]=fibonacci(n-1) + fibonacci(n-2);
	}
}