#include<iostream>
#include<algorithm>

using namespace std; 

double len,N;//len은 막대 길이 , N은 개미 수
int T;
int ant[1000001];
int minval, maxval;

int main() {
	cin >> T;
	while (T--) {
		cin >> len >> N;
		minval = 0;
		maxval = 0;
		for (int i = 0; i < N; i++) {
			cin >> ant[i]; // 입력
			int mintmp, maxtmp;
			if (ant[i] < len / 2)
				mintmp = ant[i];
			else
				mintmp = len - ant[i];

			if (mintmp > minval)
				minval = mintmp; //최소값 찾기 성공
			
			if (ant[i] < len / 2 && len - ant[i]>maxval)
				maxval = len - ant[i];
			else if (ant[i] >= len / 2 && ant[i] > maxval)
				maxval = ant[i];

		}
		cout <<minval<<" "<<maxval << endl; // 최소 값 찾기 성공
	}
}