#include<iostream>
#include<vector>

using namespace std;


vector<pair<int, int>> v(501);
int n;

void sortVector() {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].first > v[j].first) {
				swap(v[i], v[j]);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> v[i].first >> v[i].second;

	//cout << endl;
	//자 첫번째그거로 정렬해야하는데
	sortVector();
//	for (int i = 0; i < n; i++)
	//	cout << v[i].first << " " << v[i].second << endl;
	
	//두번째로 LIS
	int dp[501]{ 0, };
	int res = -1;
	for (int i = 0; i < n; i++) {
	//	cout << "---" << v[i].second << "번째" << endl;
		int maxval = 0;
		for (int j = 0; j < i; j++) {
			if (v[j].second < v[i].second) {
	//			cout <<v[j].second << "가 더 크다! maxval:"<<maxval <<endl;

				if (maxval < dp[j]) {
					maxval = dp[j];
				}
					
			}
		}
		dp[i] = maxval + 1;
		if (res < dp[i])
			res=dp[i];
	}

//	for (int i = 0; i < n; i++)
	//	cout << dp[i] << " "  ;
//	cout << endl;
	//cout << "정답:";
	cout << n-res <<endl ;
}
