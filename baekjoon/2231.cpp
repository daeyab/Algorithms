#include<iostream>
#include<algorithm>

using namespace std;

//2231
//https://www.acmicpc.net/problem/2231
//Daeyeop Kim

int N;
int sum=0;
int tmp,tmp2; // tmp 는 해당 숫자  깎기 , tmp 는 자리 숫자
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		tmp = i;
		tmp2 = tmp;
		//cout << "**I=" << i << endl;
		while (1) {
			sum += tmp2;
		//	cout << "sum:" << sum << "  tmp:" << tmp <<" tmp2:"<<tmp2<< endl;
			if (tmp == 0)
				break;
			tmp2 =tmp % 10;//10을 더 하는 것이 아닌 1을 더해야함
			tmp = tmp / 10;
		}
		if (sum == N) {
			cout << i << endl;

			break;
		}

		else if (i == N - 1)
			cout << 0 << endl;
		else  sum = 0;

	}
	return 0;
}