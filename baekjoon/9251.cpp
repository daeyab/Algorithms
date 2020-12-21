#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

char str1[1001],str2[1001];

int dp[1001][1001];

int main() {
	string s1,s2;
	cin >> s1 >> s2;
	//cout << s1 << " " << s2;
	for (int i = 0; i < s1.length(); i++)
		str1[i] = s1.at(i);
	for (int i = 0; i < s2.length(); i++)
		str2[i] = s2.at(i);

	for (int x = 1; x <= s1.length(); x++) {
		for (int y = 1; y <= s2.length(); y++) {
		//	cout <<" "<<str2[y - 1] << "&" << str1[x - 1];
			if (str2[y - 1] == str1[x - 1]) {
				dp[y][x] = dp[y - 1][x - 1]+1;
	//			cout << "!";
			}
			else {
				dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]);
			}
	//		cout <<"("<<y<<","<<x<<")"<< dp[y][x];
		}
	//	cout << endl;
	}
		cout << dp[s2.length()][s1.length()];
}