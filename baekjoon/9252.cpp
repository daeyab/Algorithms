#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

using namespace std;


char str1[1001],str2[1001];
vector <char> stk;

int dp[1001][1001];
bool rised[1001][1001];

void checkRoute(int y, int x) {
	int nx = x;
	int ny = y;
	while (nx > 0 && ny > 0) {
	//	cout << ny << "," << nx << ":" << str2[ny - 1] << endl;
		if (rised[ny][nx]) {
		//	cout << ny << "," << nx << "가 올랐음:"<< str2[ny - 1] <<endl;
			stk.push_back(str2[ny - 1]);
			nx--; ny--;
		}
		else {
		//	cout << "한칸 내릴게" << endl;
			if (dp[ny - 1][nx]==dp[ny][nx])
				ny--;
			else if(dp[ny][nx-1]==dp[ny][nx])
				nx--;
		}
	}
	for (int i = stk.size()-1; i >=0; i--) {

		cout << stk.at(i);
	}
}

int main() {
	string s1,s2;
	cin >> s1 >> s2;
//	cout << s1 << " " << s2;
	for (int i = 0; i < s1.length(); i++)
		str1[i] = s1.at(i);
	for (int i = 0; i < s2.length(); i++)
		str2[i] = s2.at(i);

	for (int x = 1; x <= s1.length(); x++) {
		for (int y = 1; y <= s2.length(); y++) {
	//		cout <<" "<<str2[y - 1] << "&" << str1[x - 1];
			if (str2[y - 1] == str1[x - 1]) {
				rised[y][x] = true;
				dp[y][x] = dp[y - 1][x - 1]+1;
			//	cout << "!";
			}
			else {
				dp[y][x] = max(dp[y][x - 1], dp[y - 1][x]);
			}
//			cout <<"("<<y<<","<<x<<")"<< dp[y][x];
	
		}
//		cout << endl;
	}
		cout << dp[s2.length()][s1.length()]<<endl;
		checkRoute(s2.length(), s1.length());

	
}