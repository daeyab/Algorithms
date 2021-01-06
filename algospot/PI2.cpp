#include<stdio.h>
#include<string>
#include<math.h>
#include<iostream>
#include<memory.h>

using namespace std;

int tc,i,j;
int dp[10001];
string s;


int evaluation(int start, int end) {
	string piece = s.substr(start, end-start+1);
	bool isSame = true;
	for (i = 0;i < piece.size();i++) {
		if (piece[i] != piece[0]) {
			isSame = false;
			break;
		}
	}
	if (isSame)
		return 1;
//if (s == string(s.size(), s[0])) return 1;
	
	bool isProgressing = true;
	for (i = 1;i < piece.size();i++) {
		if (piece[i] - piece[i - 1] != piece[1] - piece[0]) {
			isProgressing = false;
			break;
		}
	}
	if (isProgressing && abs(piece[1] - piece[0]) == 1)
		return 2;

	bool isSwitching = true;
	for (i = 0;i < piece.size();i++) {
		if (piece[i] != piece[i%2]) {
			isSwitching = false;
			break;
		}
	}
	if (isSwitching)
		return 4;
	if (isProgressing)
		return 5;

	return 10;

		
}

int solve(int start) {
	//다 끝난 경우 -> 끝까지 다 본 경우
	if (start == s.size())
		return 0;
	int &ret = dp[start];
	//이미 본 경우
	if (ret != -1)
		return ret;
	ret = 10000000;
	for (int len = 3; len <= 5;len++) {
		if (start + len <= s.size()) {
			ret = min(ret, solve(start + len) + evaluation(start, start + len - 1));
		}
	}
	return ret;

}

int main() {
	scanf("%d", &tc);
	while (tc--) {
		memset(dp, -1, sizeof(dp));
//		scanf("%s", s);
		cin >> s;
		printf("%d\n", solve(0));
	}
}
