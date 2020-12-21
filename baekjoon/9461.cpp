#include<iostream>

using namespace std;

int tc;
int n;
long long dp[101] = { 0,1,1,1,2,2,3,4,5,7,9,12, };

long long getAns(int k) {
	if (k <= 11)
		return dp[k];
	for (int i = 11; i <= k; i++) {
		dp[i] = dp[i - 2] + dp[i - 3];
	}
	return dp[k];
}

int main() {

	cin >> tc;
	for (int T = 0; T < tc; T++) {
		cin >> n;
		cout<<getAns(n)<< endl;
	}

}