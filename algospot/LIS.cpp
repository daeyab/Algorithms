#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>

using namespace std;

int seq[501];
int dp[501];
int n;

int LIS(int start) {
//	cout << start << "시작" << endl;
	int &ret = dp[start];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int next = start + 1; next < n; next++) {
		if (seq[start] < seq[next]) {
			//cout << start << "에서 " << next <<" 호출"<<endl;
			ret = max(ret, 1 + LIS(next));
		}
	}
	//cout << start<<"="<<seq[start]<< ":" << ret << endl;
	return ret;
}
int main() {
	int testcase;
	cin >> testcase;
	if (testcase > 50 || testcase < 1)
		exit(-1);
	while (testcase--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n < 1 || n>500)
			exit(-1);
		for (int i = 0; i < n; i++) {
			cin >> seq[i];
			if (seq[i] < 1 || seq[i]>100000)
				exit(-1);
		}
		int result = -1;
		for (int i = 0; i < n; i++) {
			int ret = LIS(i);
		//	cout <<i<<"-----"<< ret << endl;
			if (result < ret)
				result =ret;
		}
		cout << result << endl;
	}
	
}