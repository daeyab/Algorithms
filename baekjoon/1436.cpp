#include<iostream>
#include<math.h>

using namespace std;

int n=666;
int cnt=0;
int x=0;
int len;

int main() {
	//cout << 68 / 10 << endl;
	cin >> x;
	while (cnt != x) {
		len = int(log10(n)) + 1;
		for (int i = 0; i < len - 2; i++) {
			if ((n % (int)pow(10, len - i)) / (int)pow(10, len - 1 - i) == 6 && (n % (int)pow(10, len - 1 - i)) / (int)pow(10, len - 2 - i) == 6 && (n % (int)pow(10, len - 2 - i)) / (int)pow(10, len - 3 - i) == 6) {
				cnt++;
		//		cout << cnt << ":" << n << endl;
				break;
			}
		}
		n++;
	}
	cout << n-1 << endl;
}