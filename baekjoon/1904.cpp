#include<iostream>

using namespace std;

int cache[1000001];

int fib(int n) {

	if (cache[n] != 0)
		return cache[n];

	 if (n==0 || n == 1 || n == 2) {
		return cache[n] = n;
	}
	else
		return 	cache[n] = cache[n - 1] + cache[n - 2];
}

int main() {

	int n;
	cin >> n;

	cache[0] = 0;
	cache[1] = 1;
	cache[2] = 2;
	
	for (int i = 3; i <= n; i++) {
		cache[i] = cache[i - 1] + cache[i - 2];
		cache[i] %= 15746;
	}
	cout << cache[n];
	//	for(int i=0;i<100;i++)
// cout <<i<<":"<< fib(i) << endl;
}