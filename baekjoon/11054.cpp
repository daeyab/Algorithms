#include<iostream>
#include<memory.h>

using namespace std;


int main() {

	int arr[1001];
	int revarr[1001];
	int dp[1001];
	int dp2[1001];
	int n;
	int maxval = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		revarr[n - 1 - i] = arr[i];
	}
	//풀기
	dp[n - 1] = 0;
	memset(dp2, 0, sizeof(dp2));

	for (int i = 0; i <n; i++) {
		int maxtmp=0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				if (dp[j] > maxtmp)
					maxtmp = dp[j];
			}
		}
		dp[i] = maxtmp + 1;
	
	}

	for (int i = 0; i < n; i++) {
		int maxtmp = 0;
		for (int j = 0; j < i; j++) {
			if (revarr[i] > revarr[j]) {
				if (dp2[j] > maxtmp)
					maxtmp = dp2[j];
			}
		}
		dp2[i] = maxtmp + 1;

	}


	//cout << endl;
	for (int i = 0; i < n; i++) {
		dp[i]+=dp2[n-1-i];
		if (maxval < dp[i])
			maxval = dp[i];
	//	cout << dp[i] << " ";
	}

//	for (int i = 0; i < n; i++)
	//	cout << dp[i] << " ";
	
	cout <<maxval-1<< endl;

}