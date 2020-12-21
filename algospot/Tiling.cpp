#include<iostream>
#include<memory.h>

#define mod 1000000007

using namespace std;

int tile[101];
int dp[101];

int tiling(int n) {
	if (n <= 1)
		return 1;
	int &ret = dp[n];
	if (ret != -1)
		return ret;

	return ret=(tiling(n - 1) + tiling(n - 2) )%mod;
}
int main() {
	int tc; cin >> tc;
	int n;
	while (tc--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		cout<<tiling(n)<<endl;
	}
}