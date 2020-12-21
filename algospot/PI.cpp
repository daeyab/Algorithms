#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<memory.h>

using namespace std;

int lime[10001];
int dp[10001];
int n;

string N;

int checkVal(int start, int end) {

	//길이에 따라 동일한지, +-1 인지, 번갈아인지, 등차수열인지, 판단..
	string M = N.substr(start, end - start + 1);
	if (M == string(M.size(), M[0])) return 1;
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0])
			progressive = false;
	}
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	bool alternative = true;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] != M[i % 2])
			alternative = false;
	}
	if(alternative)
		return 4;
	if (progressive)
		return 5;
	return 10;
}

int memorize(int start) {
//	cout << N.size() << endl;
	if (start == N.size())
		return 0;
	int &ret = dp[start];
	if (ret != -1)
		return ret;
	ret = 9999999;
	for (int L = 3; L <= 5; L++) {
		if (start + L <= N.size())
			ret = min(ret, memorize(start + L) + checkVal(start, start + L - 1));
	}
//	cout << "?";
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	if (testcase < 1 || testcase>50)
		exit(-1);

	while (testcase--) {
		memset(dp, -1, sizeof(dp));
		cin >> N;
		if (N.length() < 8 || N.length() > 10000)
			exit(-1);
		cout << memorize(0) << endl;

	}
}