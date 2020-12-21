#include<iostream>
#include<algorithm>

using namespace std; 
int N, val, coin[11], K, cnt = 0;

int findI() {
	for (int i = 0; i < N ; i++) {
		if ((coin[i + 1] > K && coin[i] <=K )|| i==N-1)
			return coin[i];
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> coin[i];
	}
//	coin[10] = X;

	while (1) {
	//	sort(coin,coin+11);
		if (K == 0) {
			cout << cnt << endl;
			return 0;
		}
		else {
			val= findI();
			cnt++;
			K =K- val;
			//cout <<"잔액 : "<< K << "쓴 동전 :"<<val<<endl;
		}
	}
}
