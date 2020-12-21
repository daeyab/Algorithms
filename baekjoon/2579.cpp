#include<iostream>
#include<vector>
#include<algorithm>

using namespace std; 

int stairs[301];
int cache[301];
int check[301];

int n;

int dp(int x) {
	return cache[x] = stairs[x] + max(dp(x-3) + stairs[x - 1], dp(x-2));
}

int main() {
	cin >> n;
	int num;

	for (int i = 1; i <= n; i++) {
		cin >> stairs[i];
	}
	cache[1] = stairs[1];
	cache[2] = cache[1] + stairs[2];

//	dp(n);
	
	for (int i = 3; i <= n; i++){
		cache[i] = stairs[i] + max(cache[i - 3] + stairs[i - 1], cache[i - 2]);
	//	cout << i << ":" << cache[i] << endl;

	}
	cout<< cache[n] << endl;;
	
	return 0;
}