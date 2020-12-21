#include<iostream>

using namespace std; 

int main() {

	ios::sync_with_stdio(false);
	int n,num[1001],m;
	cin >> n>>m;
	int sum;
	int res = 0;
	if (n < 2 || n>1000 || m < 10 || m>300000)
		exit(-1);

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		if (num[i] > 100000)
			exit(-1);
	}
		
	//순서쌍을 만들어봅시다

	for (int i = 0; i < n - 2; i++) {
		for (int j=i+1;j<n-1;j++) {
			for (int k = j + 1; k < n;k++) {
				sum = num[i]+num[j]+num[k];
				if (sum <= m && m - res > m - sum)
					res = sum;
			}
		}
	}
	cout << res<<endl;
}