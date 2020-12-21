#include<iostream>

using namespace std;


int main() {

	int arr[1001];
	int dp[1001];
	int n;
	int maxval = 1;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	//풀기
	dp[n - 1] = 0;
	for (int i = n - 1; i >= 0; i--) {
		int maxtmp=0;
		for (int j = n - 1; j > i; j--) {
			if (arr[i] < arr[j]) {
				if (dp[j] > maxtmp)
					maxtmp = dp[j];
			}
		}
		dp[i] = maxtmp + 1;
		if (dp[i] > maxval)
			maxval = dp[i];
	}

//	for (int i = 0; i < n; i++)
	//	cout << dp[i] << " ";
	
	cout <<maxval<< endl;

}