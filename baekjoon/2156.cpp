#include<iostream>
#include<algorithm>

using namespace std;

int wine[10001];
int cache[10001][3] = { {0,0,0}, };

int MAX(int a,int b,int c) {
	if (a > b) {
		if (c > a)
			return c;
		else
			return a;
	}
	else {
		if (c > b)
			return c;
		else
			return b;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}
	
	for (int i = 1; i <= n; i++) {
		cache[i][0] = cache[i - 1][1] + wine[i];
		cache[i][1] = cache[i - 1][2] + wine[i];
		cache[i][2] = MAX(cache[i - 1][0], cache[i - 1][1], cache[i - 1][2]);
	}
	/*for (int i = 1; i <= n; i++) {
		cout<<i<<"의 1:"<< cache[i][0] <<" 2:"<< cache[i][1] <<" 3:"<< cache[i][2] << endl;
	}/**/
	cout<<MAX(cache[n][0], cache[n][1], cache[n][2])<<endl;
}