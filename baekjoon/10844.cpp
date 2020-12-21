#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int n;
long long ans;

vector<vector< int>> D(100, vector<int>(10, 0));
int dp[101];
int main() {
		cin >> n;
		D[0] = { 0,1,1,1,1,1,1,1,1,1 };

		for (int i = 1; i < n; i++) {
			for (int j = 0 ; j < 10; j++) {
				if (j == 0)
					D[i][j] = D[i - 1][1];
				else if (j == 9)
					D[i][j] = D[i - 1][8];
				else
					D[i][j] = (D[i - 1][j - 1] + D[i - 1][j + 1]) ;
				D[i][j] %= 1000000000;
			}
		}
	/*	for (int i = 1; i < n; i++) {
			for (int j = 0; j < 10; j++) {
				cout << D[i][j]<<" ";
			}
			cout << endl;
		}*/
		int sum = 0;
		for (int x = 0; x < 10;x++) {
			sum = (sum + D[n-1][x]) % 1000000000;
		}
		cout << sum << endl;
	return 0;
}